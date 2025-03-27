#include <io.h>
#include <iostream>
#include <Windows.h>
#include "ini_parser.h"

int main() {
 //setlocale(LC_ALL, "RUS");

 //SetConsoleCP(1251);
 //SetConsoleOutputCP(1251);
 SetConsoleOutputCP(CP_UTF8);
 //_setmode(_fileno(stdout), _O_U8TEXT);

  ini_parser parser("settings.ini");
 // auto value = parser.get_value<int>("section.value");

  return 0;
}
