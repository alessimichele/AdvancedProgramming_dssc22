#include <iostream>

class MyClass{
public:
  int x;
  MyClass():x(0){};

  friend std::ostream& operator<<(std::ostream& os, const MyClass& m);
};

std::ostream& operator<<(std::ostream& os, const MyClass& m){
    os<<m.x<<std::endl;
    return os;
};

int main(){
    MyClass m;
    std::cout<<m<<std::endl;
}