#include "coeff.hpp"
#include "Complex.hpp"
#include "CQuadraticEq.hpp"

void coeff::print(){
    std::cout<<"Hai inserito la seguente equazione"<<std::endl;
    std::cout<<a<<"x^2 + "<<b<<"x + "<<c<<std::endl;
};

void coeff::ask_for_input(){
    std::cout<<"Insert 3 real parameters"<<std::endl;
    std::cin>> a >> b >> c;

    if(a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
};