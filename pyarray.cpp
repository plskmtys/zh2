#include <iostream>
#include <vector>

template <typename T>
class PyTomb : public std::vector<T> {
public:
  PyTomb() : std::vector<T>() {}
  PyTomb(int n) : std::vector<T>(n) {}
  PyTomb(T* begin, T* end) : std::vector<T>(begin, end) {}

  T& operator[](const int i){
    if(i >= 0) return std::vector<T>::operator[](i);
    else return std::vector<T>::operator[](this->size()+i);
  }
};

int main(){
  PyTomb<int> vi(3);
  vi[0] = 1; vi[1] = 2; vi[2] = 3;
  std::cout << vi[-1] << vi[-2] << vi[-3]; //321
  
  int t[] = { 1, 2, 3, 4, 5 };
  PyTomb<int> vt(t, t+5);

  std::vector<int> v = vi; //kompat
  PyTomb<double> dd;
  dd.insert(dd.begin(), 3.14);
  std::cout << dd[0] << ' ' << dd[-1]; //3.14 3.14
  
  dd[-2]; //exception: std::out_of_range
}