#ifndef EQ_H
#define EQ_H

#include <cmath>
#include "coeff.hpp"
#include "complex.hpp"
#include <string>
#include <fstream>

class Equation{
public:
    coeff coeff;
    complex sol1;
    complex sol2;
    
    void print_solution();

    void solve();

    void solution_to_file(std::string filename);

};

void Equation::solve(){
    double delta{coeff.b*coeff.b - 4*coeff.a*coeff.c};
    if (delta>=0){
        sol1.re = (-coeff.b + pow(delta, 0.5))/(2*coeff.a);
        sol1.im = 0;
        sol2.re = (-coeff.b - pow(delta, 0.5))/(2*coeff.a);
        sol2.im = 0;
    }else{
        sol1.re = -coeff.b/(2*coeff.a);
        sol2.re = -coeff.b/(2*coeff.a);
        sol1.im =  + pow(-delta, 0.5)/(2*coeff.a);
        sol2.im =  - pow(-delta, 0.5)/(2*coeff.a);
    }
}

void Equation::print_solution(){
    std::cout<<"First solution: "<<sol1.re<< " + "<<sol1.im <<"i" <<std::endl;
    std::cout<<"Second solution: "<<sol2.re<< " + "<<sol2.im<<"i" <<std::endl;
}


void Equation::solution_to_file(std::string filename){
    std::ofstream filevar;
    filevar.open(filename, std::ios_base::app);
    filevar << sol1.re<<" + "<<sol1.im<<"i,   "<<sol2.re<<" + "<<sol2.im<<"i"<< std::endl;
    filevar.close();
}


#endif