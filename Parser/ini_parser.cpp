#include "ini_parser.h"

ini_parser::ini_parser(std::string filename) {
fin.open(filename);
	// Опроверка корректности открытия файла
	if (!fin.is_open()) {
		throw std::invalid_argument(filename + " could not be opened!");
	}

	// Разбор каждой cтроки файла
	while (std::getline(fin, line))
	{
		if (!line.empty()) {	// Проверяем не пустали ли строка
			line = ltrim(line);	// Убираем пробелы и спец символы в начале строки

			if (line[0] == '[') {	//
				pos = line.find_first_of(']');
				if (std::string::npos != pos) {
					currentSection = line.substr(1, pos - 1);
					//std::cout << currentSection << std::endl;
				}
			}
			else if (line[0] != ';') {
				// Убираем комментарий в строке с переменной, если они есть
				pos = line.find_last_of(";");
				if (std::string::npos != pos)
					line.erase(line.begin() + pos, line.end());

				// Убираем пробелы в конце строки
				line = rtrim(line);

				// Вычленяем название переменной и ее значение
				pos = line.find_first_of("=");
				currentVariable = rtrim(line.substr(0, pos));
				currentVariableValue = ltrim(line.substr(pos + 1, line.length() - 1));

				// Сохранение значения в коллекции
				if (!iniData.count(currentSection + "." + currentVariable)) {	// Проверка наличия переменной в коллекции
					iniData.insert({ currentSection + "." + currentVariable,currentVariableValue }); // Вставить новое значение 
				}
				else {
					iniData[currentSection + "." + currentVariable] = currentVariableValue;	// Изменить значение переменной
				}
			}
		}
	}
	fin.close();
}


// Получение значения с типом строка
template<>
std::string ini_parser::get_value(std::string param) {
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return iniData[param];
}