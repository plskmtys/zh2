#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> class func {
  T index;

public:
  func(const T i) : index(i) {}
  T operator()() { return index++; }
};

template <typename T> std::vector<T> indexgen(T also, T felso) {
  std::vector<T> vec(felso - also);
  std::generate(vec.begin(), vec.end(), func<T>(also));
  return vec;
}

int main() {
  std::vector<int> v1 = indexgen(0, 4);
  for (const auto &i : v1) {
    std::cout << i << "\n";
  }
}
