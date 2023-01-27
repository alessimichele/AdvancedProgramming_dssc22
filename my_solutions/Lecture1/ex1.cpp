#include <iostream>
#include <string>
#include <cmath>

int main(){
    double a;
    double b;
    double c;
    std::cout<<"Insert 3 real parameters"<<std::endl;
    std::cin>> a;
    std::cin>> b;
    std::cin>> c;
    if (a==0){
        std::cout<<"You don't enter a quadratic equation"<<std::endl;
        exit(1);
    }
    std::cout<<"Your equation is: "<<a<<"x^2 + "<<b<<"x + "<<c<<std::endl;
    double delta{pow(b,2) -4*a*c};
    double x1;
    double x2;
    if (delta>=0){
        x1 = (-b + pow(delta,0.5))/(2*a);
        x2 = (-b - pow(delta,0.5))/(2*a);

        // altro modo per fare la radice è std::sqrt(n)


        std::cout<<"Your solutions are: "<<x1<<"; "<<x2<<std::endl;
    }else{
        double x1im;
        double x2im;
        x1 = -b/(2*a);
        x2 = -b/(2*a);
        x1im =  + pow(-delta,0.5)/(2*a);
        x2im =  - pow(-delta,0.5)/(2*a);
        std::cout<<"Your solutions are: "<<x1<<" + (i)*"<<x1im<<"; "<<x2<<" + (i)*"<<x2im<<std::endl;
    }
    return 0;
}