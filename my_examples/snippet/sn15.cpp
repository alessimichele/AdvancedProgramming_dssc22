#include <iostream>
/*
template <typename T, int S>
void add_number(T& var){
    var=var+S;
}

int main(){
  int a=3;;
  add_number<int,5>(a);
  std::cout<<a;

}


template <typename T>
void myPrint(const T& arg){
    std::cout<<arg<<" ";
}

template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}

int main(){
  myPrint(1,'p',3.0);
}
*/


template <typename T>
void print(const T& arg){
  std::cout<<arg<<std::endl;
};

struct MyClass{
  int a;
  int b;
};


int main(){
  MyClass var;

  print<int>(var.a);
}
