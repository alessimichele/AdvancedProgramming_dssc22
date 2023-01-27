#include <iostream>
#include <string>
#include <cmath>

struct coeff{
    double a;
    double b;
    double c;
};

int main(){
    coeff C;
    std::cout<<"Insert 3 real parameters"<<std::endl;
    std::cin>> C.a;
    std::cin>> C.b;
    std::cin>> C.c;
    if (C.a==0){
        std::cout<<"You don't enter a quadratic equation"<<std::endl;
        exit(1);
    }
    std::cout<<"Your equation is: "<<C.a<<"x^2 + "<<C.b<<"x + "<<C.c<<std::endl;
    double delta{pow(C.b,2) -4*C.a*C.c};
    double x1;
    double x2;
    if (delta>=0){
        x1 = (-C.b + pow( delta,0.5))/(2*C.a);
        x2 = (-C.b - pow( delta, 0.5))/(2*C.a);
        std::cout<<"Your solutions are: "<<x1<<"; "<<x2<<std::endl;
    }else{
        double x1im;
        double x2im;
        x1 = -C.b/(2*C.a);
        x2 = -C.b/(2*C.a);
        x1im =  + pow( -delta,0.5)/(2*C.a);
        x2im =  - pow( -delta,0.5)/(2*C.a);
        std::cout<<"Your solutions are: "<<x1<<" + (i)*"<<x1im<<"; "<<x2<<" + (i)*"<<x2im<<std::endl;
    }
    return 0;
}