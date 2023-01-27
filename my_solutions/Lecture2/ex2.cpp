#include <iostream>
#include <string>
#include <cmath>


class Complex{
public:
    double re;
    double im;
};

class coeff{
public:
    double a;
    double b;
    double c;
    coeff(){a=0;b=0;c=0;};
    void print();
    void ask_for_input();
};

void coeff::print(){
    std::cout<<"Hai inserito la seguente equazione"<<std::endl;
    std::cout<<a<<"x^2 + "<<b<<"x + "<<c<<std::endl;
}

void coeff::ask_for_input(){
    std::cout<<"Insert 3 real parameters"<<std::endl;
    std::cin>> a >> b >> c;

    if(a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
}



class CQuadraticEq{
public:
    coeff coefficients;
    Complex sol1;
    Complex sol2;

    void solve();

    void print_solution();
};

void CQuadraticEq::solve(){
    double delta{pow(coefficients.b,2) -4*coefficients.a*coefficients.c};
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
}

void CQuadraticEq::print_solution(){
    std::cout<<"First solution: "<<sol1.re<< " + "<<sol1.im <<"i" <<std::endl;
    std::cout<<"Second solution: "<<sol2.re<< " + "<<sol2.im<<"i" <<std::endl;

}

int main(){
    CQuadraticEq eq;
    eq.coefficients.ask_for_input();
    eq.coefficients.print();
    eq.solve();
    eq.print_solution();
}