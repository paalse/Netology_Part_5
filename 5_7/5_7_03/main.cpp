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

  MyVector(const MyVector<T>& myVec)
      : sizeArr(myVec.sizeArr), capacityArr(myVec.capacityArr) {
    arr = new T[myVec.capacityArr];
    std::copy(myVec.arr, myVec.arr + myVec.sizeArr, arr);
  }

  // Перегрузка оператора =
  MyVector& operator=(MyVector& other) {
    if (this != &other) {
      sizeArr = other.sizeArr;
      capacityArr = other.capacityArr;
      std::copy(other.arr, other.arr + other.sizeArr, arr);
    }
    return *this;
  }

  // Получение значения по индексу
  T at(size_t index) {
    if (index > sizeArr) {
      throw std::out_of_range("Index out of range");
    }
    return arr[index];
  }

  // Добавление элемента в конец контейнера
  void push_back(T value) {
    if (sizeArr == capacityArr) {
      addCapacity();
    }
    arr[sizeArr] = value;
    sizeArr++;
  };

  // Получение количества элементов в контейнере
  int size() { return sizeArr; };

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

  myVect.push_back(6);
  myVect.push_back(5);
  myVect.push_back(7);
  myVect.push_back(3);
  myVect.push_back(4);
  std::cout << "MyVector: ";
  myVect.print();
  std::cout << "MyVector.at(0): " << myVect.at(0) << std::endl;
  std::cout << "Size: " << myVect.size() << std::endl;
  std::cout << "Capacity: " << myVect.capacity() << std::endl;
  std::cout << std::endl;

  // Использование конструктора копирования
  MyVector<int> myVect1(myVect);
  myVect1.push_back(2);
  std::cout << "MyVector1: ";
  myVect1.print();
  std::cout << "MyVector1.at(5): " << myVect1.at(5) << std::endl;
  std::cout << "Size: " << myVect1.size() << std::endl;
  std::cout << "Capacity: " << myVect1.capacity() << std::endl;
  std::cout << std::endl;

  // Переопределение оператора присвоения
  myVect = myVect1;
  std::cout << "MyVector: ";
  myVect.print();
  std::cout << "MyVector.at(0): " << myVect.at(0) << std::endl;
  std::cout << "Size: " << myVect.size() << std::endl;
  std::cout << "Capacity: " << myVect.capacity() << std::endl;
  std::cout << std::endl;

  return 0;
}