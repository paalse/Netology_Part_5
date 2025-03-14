#include <iostream>

template <class T>
class Table {
 private:
  T** arr;
  int rowNum = 0;
  int colNum = 0;

 public:
  // Конструктор создает двумерный массив
  Table(int arrSizeRow, int arrSizeCol)
      : rowNum{arrSizeRow}, colNum(arrSizeCol) {
    arr = new T* [rowNum] {};
    for (int i = 0; i < rowNum; i++) {
      arr[i] = new T[colNum]{};
    }
  };

  // реализация operator[] для двумерного массива
  class ArrRow {
   private:
    T* arrRow;
    int colNum = 0;

   public:
    ArrRow(T* arrRow, const int arrCol) : arrRow(arrRow), colNum(arrCol) {}

    T& operator[](int i) {
      std::cout << "pas1: " << i << std::endl;
      if (i >= colNum || i < 0) throw std::out_of_range("Index out of range");
      return arrRow[i];
    }
  };

  ArrRow operator[](const int i) const {
    std::cout << "pas: " << i << " " << colNum << std::endl;
    if (i >= rowNum || i < 0) throw std::out_of_range("Index out of range");
    return ArrRow(arr[i], colNum);
  };

  // Получение размера массива
  void getSize() const {
    std::cout << "Size Of Array: " << rowNum << " x " << colNum << std::endl;
  };

  ~Table() {
    for (int j = 0; j < this->rowNum; j++) {
      delete[] this->arr[j];
    }
    delete[] this->arr;
    this->arr = nullptr;
  }
};

int main() {
  auto test = Table<int>(2, 3);
  try {
    test[1][2] = 4;
    std::cout << test[0][1] << std::endl;
    test.getSize();
  } catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  };
};