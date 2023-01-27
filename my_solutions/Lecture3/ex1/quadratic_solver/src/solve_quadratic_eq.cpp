#include "solve_quad_eq.hpp"

void solve_quadratic_eq(double a, double b, double c){
    double delta;
    delta = (pow(b,2) -4*a*c);
    double x1;
    double x2;
    if (delta>=0){
        x1 = (-b + pow(delta, 0.5))/(2*a);
        x2 = (-b - pow(delta, 0.5))/(2*a);
        std::cout<<"Your solutions are: "<<x1<<"; "<<x2<<std::endl;
    }else{
        double x1im;
        double x2im;
        x1 = -b/(2*a);
        x2 = -b/(2*a);
        x1im =  + pow(-delta, 0.5)/(2*a);
        x2im =  - pow(-delta, 0.5)/(2*a);
        std::cout<<"Your solutions are: "<<x1<<" + (i)*"<<x1im<<"; "<<x2<<" + (i)*"<<x2im<<std::endl;
    }
}