#include <iostream>
#include <vector>

template <class T>
T squaring(T num) {
  return num * num;
}

template <class T>
void squaringVect(std::vector<T>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    arr[i] *= arr[i];
  }
}

template<class T>
void printVect(std::vector<T>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    if (i == 0)
      std::cout << arr[i];
    else
      std::cout << ", " << arr[i];
  }
  std::cout << std::endl;
}


int main() {
 
  int num = 4;
  std::cout << "[IN]: " << num << std::endl;
  std::cout << "[OUT]: " << squaring(num) << std::endl;

  std::vector<int> arr{-1, 4, 8};
  std::cout << "[IN]: ";
  printVect(arr);
  squaringVect(arr);
  std::cout << "[OUT]: ";
  printVect(arr);

  return 0;
}