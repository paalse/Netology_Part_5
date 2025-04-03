#include "ini_parser.h"

ini_parser::ini_parser(std::string filename) {
fin.open(filename);
	// ��������� ������������ �������� �����
	if (!fin.is_open()) {
		throw std::invalid_argument(filename + " could not be opened!");
	}

	// ������ ������ c����� �����
	while (std::getline(fin, line))
	{
		if (!line.empty()) {	// ��������� �� ������� �� ������
			line = ltrim(line);	// ������� ������� � ���� ������� � ������ ������

			if (line[0] == '[') {	//
				pos = line.find_first_of(']');
				if (std::string::npos != pos) {
					currentSection = line.substr(1, pos - 1);
					//std::cout << currentSection << std::endl;
				}
			}
			else if (line[0] != ';') {
				// ������� ����������� � ������ � ����������, ���� ��� ����
				pos = line.find_last_of(";");
				if (std::string::npos != pos)
					line.erase(line.begin() + pos, line.end());

				// ������� ������� � ����� ������
				line = rtrim(line);

				// ��������� �������� ���������� � �� ��������
				pos = line.find_first_of("=");
				currentVariable = rtrim(line.substr(0, pos));
				currentVariableValue = ltrim(line.substr(pos + 1, line.length() - 1));

				// ���������� �������� � ���������
				if (!iniData.count(currentSection + "." + currentVariable)) {	// �������� ������� ���������� � ���������
					iniData.insert({ currentSection + "." + currentVariable,currentVariableValue }); // �������� ����� �������� 
				}
				else {
					iniData[currentSection + "." + currentVariable] = currentVariableValue;	// �������� �������� ����������
				}
			}
		}
	}
	fin.close();
}


// ��������� �������� � ����� ������
template<>
std::string ini_parser::get_value(std::string param) {
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return iniData[param];
}