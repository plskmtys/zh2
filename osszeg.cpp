#include <algorithm>
#include <iostream>
#include <vector>

class Osszead {
  int &osszeg;

public:
  Osszead(int &i) : osszeg(i) {}
  void operator()(int &s) { osszeg += s; }
};

int main() {
  std::vector<int> test;
  for (int i = 0; i < 4; ++i) {
    test.push_back(i);
  }
  int sum = 0;
  std::for_each(test.begin(), test.end(), Osszead(sum));
  std::cout << sum << std::endl;
}
