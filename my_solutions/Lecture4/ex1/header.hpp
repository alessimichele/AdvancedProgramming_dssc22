#include <iostream>
#include <string>
#include <cmath>

template <typename T>
class coeff{
public:
    T a;
    T b;
    T c;
    coeff(const T& a0, const T& b0, const T& c0 );
    void print();
    void ask_for_input();
};

template<typename T>
coeff<T>::coeff (const T& a0, const T& b0, const T& c0){
    a=a0;
    b=b0;
    c=c0;
}

template<typename T>
void coeff<T>::print(){
    std::cout<<a<<" "<<b<<" "<<c<<" "<<std::endl;
}


template<typename T>
void coeff<T>::ask_for_input(){
    std::cout<<"Insert 3 real parameters"<<std::endl;
    std::cin>> a >> b >> c;

    if(a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
}

template<typename T>
void solve_quadratic_eq(double a, double b, double c){
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