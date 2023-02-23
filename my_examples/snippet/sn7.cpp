#include <iostream>


void add_two(int* a){
    *a=*a+2;
}
int main(){
    int var = 0;
    add_two(&var);
    std::cout<<var<<std::endl;

    return 0;
}