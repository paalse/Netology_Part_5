// Для лучшего понимания работы std::vector в этом задании вам нужно написать
// собственную шаблонную упрощённую реализацию std::vector. У вашего контейнера
// должны работать функции :
//    at(int index) — доступ к элементу контейнера по индексу;
//    push_back(T value) — размер контейнера неизвестен заранее, вам нужно
//    правильно увеличивать выделенную память;
//	  size() — количество элементов в контейнере;
//    capacity() — количество элементов, которое может вместить
//    контейнер до нового выделения памяти.

#include <iostream>

template <typename T>
class MyVector {
 private:
  T* arr = nullptr;
  int sizeArr;
  int capacityArr;

  // Увеличение размера контейнера
  void addCapacity() { 
      T* arr_new = new T[capacityArr * 2];
      std::copy(arr, arr + sizeArr, arr_new);
      delete[] arr;
      arr = arr_new;
      capacityArr *= 2;
  }

 public:
  MyVector() : arr(new T[1]), sizeArr(0), capacityArr(1) {}

  // Получение значения по индексу
  T at(int index) {
    if (index < 0 || index > sizeArr) {
      throw std::out_of_range("Index out of range");
    }
    return arr[index];
  }

  // Добавление элемента в конец контейнера
  void push_back(T value) {
    if (sizeArr < capacityArr) {
      arr[sizeArr] = value;
      sizeArr++;
    } else {
      addCapacity();
      arr[sizeArr] = value;
      sizeArr++;
    }
  };

  // Получение количества элементов в контейнере
  int size() { return sizeArr;};

  // Получение емкости контейнера
  int capacity() { return capacityArr; };

  // Печать содержимого контейнера
  void print() {
    for (int i = 0; i < sizeArr; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }

  // Очистка памяти
  ~MyVector() { delete[] arr; }
};

int main() { 
    MyVector<int> myVect;

    std::cout << "MyVector: ";
    myVect.push_back(6);
    myVect.push_back(5);
    myVect.push_back(7);
    myVect.push_back(3);
    myVect.push_back(4);
    myVect.print();
    std::cout << "MyVector.at(0): " << myVect.at(0) << std::endl;
    std::cout << "Size: " << myVect.size() << std::endl;
    std::cout << "Capacity: " << myVect.capacity() << std::endl;

    return 0; }