#include <iostream>

class A {
public:
  virtual void foo() { std::cout << "A\n"; }
};

class B : public A {
  void foo() { std::cout << "B\n"; }
};

int main() {
  A *ap = new B;
  ap->foo();
}
