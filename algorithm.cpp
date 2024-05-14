#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1(4, 10), v2(5, 10);
  v2[3] = 9;
  if (std::equal(v1.begin(), v1.end(), v2.begin())) {
    std::cout << "igaz\n";
  } else {
    std::cout << "hamis\n";
  }
}
