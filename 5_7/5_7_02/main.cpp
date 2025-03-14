// Вам поступают числа из стандартного потока ввода.Первым числом вводится
// количество элементов, далее сами значения. Нужно вывести все эти числа без
// дубликатов в порядке убывания.

#include <iostream>
#include <set>

bool cmp(int a, int b) { return a > b; }

int main() {
  int size = 0;
  int tmp = 0;
  std::set<int, decltype(&cmp)> my_set(&cmp);

  std::cout << "[IN]: " << std::endl;
  std::cin >> size;
  for (int i = 0; i < size; i++) {
    std::cin >> tmp;
    my_set.insert(tmp);
  }

  std::cout << "[OUT]: " << std::endl;
  for (auto& elem : my_set) {
    std::cout << elem << std::endl;
  }
  return 0;
}