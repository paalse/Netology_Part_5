#pragma once
#include "ini_parser.h"

// ���� ������������������ ������� ��� ��������� ���� �� ������
template<typename T>
T ini_parser::get_value(std::string param) {
	static_assert(sizeof(T) == -1, "not implemented type for get_value");
}

// ��������� �������� � ����� int
template<>
int ini_parser::get_value(std::string param) {
	// �������� ������� ���������
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return std::stoi(iniData[param]);
}

// ��������� �������� � ����� double
template<>
double ini_parser::get_value(std::string param) {
	// �������� ������� ���������
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return std::stod(iniData[param]);
}

// ��������� �������� � ����� float
template<>
float ini_parser::get_value(std::string param) {
	// �������� ������� ���������
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return std::stof(iniData[param]);
}

// ��������� �������� � ����� string
template<>
std::string ini_parser::get_value(std::string param) {
	if (!iniData.count(param)) {
		throw std::exception("No data found!");
	}
	return iniData[param];
}
