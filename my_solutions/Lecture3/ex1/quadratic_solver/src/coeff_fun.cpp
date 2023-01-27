#include "coeff_fun.hpp"

void coeff::print(){
    std::cout<<a<<" "<<b<<" "<<c<<" "<<std::endl;
};

void coeff::ask_for_input(){
    std::cout<<"Insert 3 real parameters"<<std::endl;
    std::cin>> a >> b >> c;

    if(a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
};