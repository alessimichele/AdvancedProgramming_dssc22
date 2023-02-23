#include <iostream>

int main(){
    int a{77};
    int& c{a}; // c becomes an alias for a
    int* p{nullptr};
    p = &a;
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    
    std::cout<<"address of a is: "<<&a<<std::endl;
    std::cout<<"address of c is: "<<&c<<std::endl;

    std::cout<<"p is: "<<p<<std::endl;
    std::cout<<"*p is: "<<*p<<std::endl;

    a=2;
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    
    std::cout<<"address of a is: "<<&a<<std::endl;
    std::cout<<"address of c is: "<<&c<<std::endl;

    std::cout<<"p is: "<<p<<std::endl;
    std::cout<<"*p is: "<<*p<<std::endl;

    c=100;
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    
    std::cout<<"address of a is: "<<&a<<std::endl;
    std::cout<<"address of c is: "<<&c<<std::endl;

    std::cout<<"p is: "<<p<<std::endl;
    std::cout<<"*p is: "<<*p<<std::endl;

    // let's change a:
    a=a+2;
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    std::cout<<"*p is: "<<*p<<std::endl;
        
    // let's change c:
    c=c+2;
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    
    // what is p
    std::cout<<"p is: "<<p<<std::endl;
    std::cout<<"p points to value "<<*p<<std::endl;
    
    // let's change a with p
    *p=a+2;
    
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    std::cout<<"p points to value "<<*p<<std::endl;
    
    return 0;
}