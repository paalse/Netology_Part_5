#pragma once
#include <iostream>
#include <fstream>
#include <string> 
#include <map>


// Убрать спец символы и пробелы в начале строки
static std::string ltrim(std::string s) {
	size_t startpos = s.find_first_not_of(" \t\r\n\v\f");
	if (std::string::npos != startpos)
	{
		s = s.substr(startpos);
	}
	return s;
}

// Убрать спец символы и пробелы в конце строки
static std::string rtrim(std::string s) {
	size_t endpos = s.find_last_not_of(" \t\r\n\v\f");
	if (std::string::npos != endpos)
	{
		s = s.substr(0, endpos + 1);
	}
	return s;
}

class ini_parser {
private:
	std::ifstream fin;
	std::map<std::string, std::string> iniData;
	std::string line = "";
	size_t pos=0;
	std::string currentSection;
	std::string currentVariable;
	std::string currentVariableValue;

public:
	ini_parser(std::string filename); 

	// Получение значения с числовым типом
	template<typename T>
	T get_value(std::string param) {

		// Проверка наличия параметра
		if (!iniData.count(param)) {
			throw std::exception("No data found!");
		}

		std::string val = iniData[param]; // Получение значения параметра
		std::string var_type = typeid(T).name(); // Получение типа параметра

		// Проверка на допустимые типы
		if (var_type != "int" && var_type != "double" && var_type != "float") {
			throw std::exception("Not correct data type!");
		}

		// Преобразование строки в запрошенный тип
		if (var_type == "int") return std::stoi(val);
		else if (var_type == "double") return std::stod(val);
		else return std::stof(val);
	}

	// Получение значения с типом строка
	template<>
	std::string get_value(std::string param);

	~ini_parser() {}
};
