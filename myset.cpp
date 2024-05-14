#include <iostream>
#include <cstddef>

template <typename T, std::size_t S = 10>
class MySet{
private:
  std::size_t ssize;
  std::size_t msize = S;
  T elements[S];
public:
  MySet(): ssize(0) {}

  std::size_t size() const { return ssize; }
  std::size_t capacity() const { return msize; }

  bool contains(const T& item){
    for(std::size_t i = 0; i < ssize; ++i){
      if(elements[i] == item) return true;
    }
    return false;
  }

  void insert(const T& item){
    if(contains(item)) return;
    if(ssize == msize) throw "tele van xd";
    elements[ssize++] = item;
  }
};

int main(){
    MySet<char, 5> t;
    std::cout << t.contains('a'); // false
    t.insert('a');
    std::cout << t.contains('a'); //true 
}