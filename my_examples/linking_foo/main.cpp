#include "./include/class1.hpp"
#include "./include/class2.hpp"

#include <iostream>

int main(){
    Class1 c1(2,3);
    Class2 c2(2.0);
    int result = c1.sum(4);
    std::cout<<result<<std::endl;
    std::cout<<c2.sum(5.0)<<std::endl;
    Class1 c3(1,0);
    std::cout<<c3.sum(3);
    return 0;
}