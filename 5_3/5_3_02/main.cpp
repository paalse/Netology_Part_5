#include <iostream>

class smart_array {
  int size;  // Размер массива
  int* arr;  // Массив
  int pos;   // Текущая ползиция
 public:
  smart_array(int num) {
    size = num;
    arr = new int[num]{0};
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

  int getSize() { return size; }

  int* getArr() { return arr; }

  int getPos() { return pos; }

  // Перегрузка оператора =
  smart_array& operator=(smart_array& other) {
    if (this != &other) {
      size = other.getSize();
      pos = other.getPos();
      delete[] arr;
      arr = new int[size];
      std::copy(other.getArr(), other.getArr() + other.getSize(), arr);
    }
    return *this;
  }

  // Вывод массива в консоль
  void print() {
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }

  ~smart_array() { delete[] this->arr; }
};

int main() {
  try {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    std::cout << "arr: ";
    arr.print();

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    std::cout << "new_arr: ";
    new_array.print();

    arr = new_array;

    std::cout << "arr: ";
    arr.print();
  } catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
  return 0;
}