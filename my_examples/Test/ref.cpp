#include <iostream>

void add_two(int &a){
    a = a+2;
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

//output:
//inizio1
//0x16b30f428
//dopo3
//0x16b30f428