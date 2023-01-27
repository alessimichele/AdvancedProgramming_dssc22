#include <iostream>
#include <string>
#include <cmath>

class coeff{
public:
    double a;
    double b;
    double c;
    coeff(){a=0;b=0;c=0;}
    
    void print(){std::cout<<a<<" "<<b<<" "<<c<<" "<<std::endl;}
    
    void ask_for_input(){
        std::cout<<"Insert 3 real parameters"<<std::endl;
        std::cin>> a;
        std::cin>> b;
        std::cin>> c;
    }
};

void solve_quadratic_eq(double a, double b, double c){
    if (a==0){
        std::cout<<"You don't enter a quadratic equation"<<std::endl;
        exit(1);
    }
    double delta{pow(b,2) -4*a*c};
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


int main(){
    coeff C;
    C.ask_for_input();
    C.print();
    solve_quadratic_eq(C.a, C.b, C.c);
}