#include <iostream>

class Test {
  int a;

public:
  Test(int a = 0) : a(a) { std::cout << "K" << a; }

  Test &operator=(const Test &rhs) {
    a = rhs.a;
    std::cout << "=" << a;
    return *this;
  }

  ~Test() { std::cout << "d" << a; }
};

int main() {
  Test a0[2];
  Test a00 = a0[0];
  return 0;
}
