#include <iostream>
template <typename T, short int N>
void add_number(T& var){
    var=var+N;
}

int main(){
    double b{4.7};
    add_number<double,7>(b);
    std::cout<<b<<std::endl;
    return 0;
}