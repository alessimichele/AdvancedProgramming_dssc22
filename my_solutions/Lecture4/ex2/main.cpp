#include "complex.hpp"


int main(){
  complex<double> a(1,2),b(3,4);  
  std::cout<<a+b<<std::endl;
  std::cout<<a-b<<std::endl;  
  std::cout<<a*b<<std::endl;
  return 0;  
}

/*
per runnare:

g++ -c main.cpp -Iinclude
g++ -o main main.o
*/
