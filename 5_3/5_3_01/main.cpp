#include <iostream>

class smart_array {
  int size;  // Размер массива
  int* arr;  // Массив
  int pos;   // Текущая ползиция
 public:
  smart_array(int num) {
    size = num;
    arr = new int[num];
    pos = 0;
  }

  // Добавление элемента в массив
  void add_element(int num) {
    if (pos < size) {
      arr[pos] = num;
      pos++;
    } else {
      throw std::exception("Index out of range.");
    }
  }

  // Получение элемента из массива
  int get_element(int num) {
    if (num < size) {
      return arr[num];
    } else {
      throw std::exception("Index out of range.");
    }
  }

  ~smart_array() { delete[] arr; }
};

int main() {
  try {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);
    arr.add_element(14);
    arr.add_element(15);
    std::cout << arr.get_element(0) << std::endl;
  } catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  return 0;
}