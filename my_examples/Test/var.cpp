#include <iostream>

int add_two(int a){
    return a+2;
}

int main(){
    int a;
    a = 1;
    std::cout<<"inizio"<<a<<std::endl;
    int *p = &a;
    std::cout<<p<<std::endl;
    add_two(a);
    std::cout<<"dopo"<<a<<std::endl;
    std::cout<<p<<std::endl;
    return 0;
}

//output
//inizio1
//0x16fd73428
//dopo1
//0x16fd73428