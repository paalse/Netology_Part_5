#include <algorithm>
#include <iostream>

class MyFunctor {
 private:
  int sum;
  int count;

 public:
  MyFunctor() : sum(0), count(0) {};
  void operator()(int num) {
    if (num % 3 == 0) {
      count++;
      sum += num;
    }
  }

  int get_sum() { return sum; }
  int get_count() { return count; }
};

int main() {
  MyFunctor myF;

  int arr[] = {4, 1, 3, 6, 25, 54};
  std::cout << "[IN]: ";
  for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  myF = std::for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), myF);

  std::cout << "[OUT]: get_sum() = " << myF.get_sum() << std::endl;
  std::cout << "[OUT]: get_count() = " << myF.get_count() << std::endl;

  return 0;
}