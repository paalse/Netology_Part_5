// ����� ����������� �������, ������� ������� ��� ���������, � �� ������ ������
// ������, �� std::vector. [IN] : 1 1 2 5 6 1 2 4 [OUT] : 1 2 4 5 6

#include <algorithm>
#include <iostream>
#include <vector>

// ����� ����������� ���������� �� �������
void print(std::vector<int>& vec) {
  std::vector<int>::const_iterator i = vec.cbegin();
  while (i != vec.cend()) {
    std::cout << *i << " ";
    i++;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> myVect{1, 1, 2, 5, 6, 1, 2, 4};

  std::cout << "[IN]: ";
  print(myVect);


  // ���������� ��������� ����������
  std::sort(myVect.begin(), myVect.end());

  // �������� �� ���������� ��������� ����������
  auto it = std::unique(myVect.begin(), myVect.end());
  myVect.erase(it, myVect.end());

  std::cout << "[OUT]: ";
  print(myVect);

  return 0;
}