#pragma once
#include <iostream>
#include <fstream>
#include <map>

class ini_parser {
 private:
  std::map<std::string, std::string> iniData;
 public:
  ini_parser(std::string filename) {
  
    std::ifstream fin(filename);
    std::string str = "";

    if (fin.is_open()) {
      while (!(fin >> str).eof()) {
        //  fin >> str;
        std::cout << str << std::endl;
      }
    } else {
      std::cout << "Ошибка открытия файла !\n";
    }

    fin.close();
  }

  // Получение значения
  template<typename T>
  T get_value(std::string param) {}


  ~ini_parser() {}

};
