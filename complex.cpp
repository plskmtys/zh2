#include <iostream>
#include <sstream>

class Complex {
protected:
  float r, i;

public:
  Complex(float r, float i) : r(r), i(i) {}
  float getR() const { return r; }
  float getI() const { return i; }
};

struct Serializable {
  virtual void write(std::ostream &os) const = 0;
  virtual void read(std::istream &is) = 0;
};

class SComplex : public Complex, public Serializable {
public:
  SComplex(float r, float i) : Complex(r, i) {}
  void write(std::ostream &os) const override {
    os << "SComplex " << r << '+' << i << 'j' << std::endl;
  }

  void read(std::istream &is) override {
    std::string sc;
    is >> sc;
    if (sc != "SComplex")
      throw "wrong";
    char tmp;
    is >> r >> tmp;
    if (tmp != '+')
      throw "wrong";
    is >> i >> tmp;
    if (tmp != 'j')
      throw "wrong";
  }
};

int main() {
  std::stringstream ss;
  ss << "SComplex 3.14+2.71j\nSComplex 2.14+9.71j\n";
  SComplex c1(0, 0);
  c1.read(ss);
  c1.write(std::cout);
  SComplex c2(0, 1);
  c2.read(ss);
  c2.write(std::cout);
  SComplex c3(0, 0);
  c3.read(ss);
}
