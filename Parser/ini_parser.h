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
	
	// Если специализированная функция для обработки типа не задана
	template<typename T>
	T get_value(std::string param); ;

	// Получение значения с типом int
	template<>
	int get_value(std::string param);;

	// Получение значения с типом double
	template<>
	double get_value(std::string param);

	// Получение значения с типом float
	template<>
	float get_value(std::string param);

	// Получение значения с типом string
	template<>
	std::string get_value(std::string param);

	~ini_parser() {}
};
