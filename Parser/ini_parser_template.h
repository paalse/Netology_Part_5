#pragma once
#include "ini_parser.h"

// Если специализированная функция для обработки типа не задана
template<typename T>
T ini_parser::get_value(std::string param) {
	static_assert(sizeof(T) == -1, "not implemented type for get_value");
}

// Получение значения с типом int
template<>
int ini_parser::get_value(std::string param) {
	// Проверка наличия параметра
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return std::stoi(iniData[param]);
}

// Получение значения с типом double
template<>
double ini_parser::get_value(std::string param) {
	// Проверка наличия параметра
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return std::stod(iniData[param]);
}

// Получение значения с типом float
template<>
float ini_parser::get_value(std::string param) {
	// Проверка наличия параметра
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return std::stof(iniData[param]);
}

// Получение значения с типом string
template<>
std::string ini_parser::get_value(std::string param) {
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return iniData[param];
}
