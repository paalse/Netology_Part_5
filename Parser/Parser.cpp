#include <io.h>
#include <iostream>
#include <Windows.h>
#include "ini_parser.h"

int main() {

	SetConsoleOutputCP(CP_UTF8);
	try {
		ini_parser parser("settings.ini");

		std::cout << "Section1.var2 = ";
		auto value = parser.get_value<std::string>("Section1.var2");
		std::cout << value << std::endl;

		std::cout << "Section3.Vid = ";
		auto value1 = parser.get_value<double>("Section3.Vid");
		std::cout << value << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
