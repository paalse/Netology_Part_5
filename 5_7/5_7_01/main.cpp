// Ќужно посчитать, сколько раз каждый символ встречаетс¤ в заданном тексте, и
// отсортировать по убыванию частоты.

#include <iostream>
#include <map>
#include <set>

struct comp {
  template <typename T>
  bool operator()(const T &l, const T &r) const {
    if (l.second != r.second) {
      return l.second > r.second;
    }
    return l.first < r.first;
  }
};

int main() {
  std::string str = "Hello world !!";
  std::map<char, int> chars;
  int cnt = 0;

  std::cout << "[IN]: " << str << std::endl;

  for (char c : str) {
    if (chars.count(c)) {
      cnt = chars.find(c)->second;
      chars[c] = cnt + 1;
    } else {
      chars.insert({c, 1});
    }
  }

  std::set<std::pair<char, int>, comp> chars1(chars.begin(), chars.end());

  std::cout << "[OUT]:" << std::endl;
  for (auto &x : chars1) {
    std::cout << x.first << " : " << x.second << std::endl;
  }
  return 0;
}