#include "coeff.hpp"
#include "Complex.hpp"
#include "CQuadraticEq.hpp"

void CQuadraticEq::solve(){
    double delta;
    delta = (pow(coefficients.b,2) -4*coefficients.a*coefficients.c);
    if (delta>=0){
        sol1.re = (-coefficients.b + pow(delta, 0.5))/(2*coefficients.a);
        sol1.im = 0;
        sol2.re = (-coefficients.b - pow(delta, 0.5))/(2*coefficients.a);
        sol2.im = 0;
    }else{
        sol1.re = -coefficients.b/(2*coefficients.a);
        sol2.re = -coefficients.b/(2*coefficients.a);
        sol1.im =  + pow(-delta, 0.5)/(2*coefficients.a);
        sol2.im =  - pow(-delta, 0.5)/(2*coefficients.a);
    }
};

void CQuadraticEq::print_solution(){
    std::cout<<"First fucking solution: "<<sol1.re<< " + "<<sol1.im <<"i" <<std::endl;
    std::cout<<"Second solution: "<<sol2.re<< " + "<<sol2.im<<"i" <<std::endl;

};