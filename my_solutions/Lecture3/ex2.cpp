// overload w/ friend non member function

#include <iostream>

class Complex{
public:    
    double re;
    double im;

    Complex(){
      re=0;im=0;  
    }  
    Complex(const double& x0, const double& y0):re(x0),im(y0){}

    friend Complex operator+(const Complex &z1, const Complex &z2);
    friend Complex operator-(const Complex &z1, const Complex &z2);
    friend Complex operator*(const Complex &z1, const Complex &z2);
    friend Complex operator/(const Complex &z1, const Complex &z2);

    friend std::ostream& operator<<(std::ostream& os, const Complex& z);
};

Complex operator+(const Complex &z1, const Complex &z2){
    Complex res;
    res.re = z1.re + z2.re;
    res.im = z1.im + z2.im;
    return res;
};

Complex operator-(const Complex &z1, const Complex &z2){
    Complex res;
    res.re = z1.re - z2.re;
    res.im = z1.im - z2.im;
    return res;
};

Complex operator*(const Complex &z1, const Complex &z2){
    Complex res;
    res.re = z1.re*z2.re - z1.im*z2.im;
    res.im = z1.re*z2.im + z1.im*z2.re;
    return res;
};

Complex operator/(const Complex &z1, const Complex &z2){
    Complex res;
    res.re = (z1.re*z2.re + z1.im*z2.im)/(z1.re*z1.re + z1.im*z1.im);
    res.im = (z1.re*z2.im - z1.im*z2.re)/(z1.re*z1.re + z1.im*z1.im);
    return res;
};

std::ostream& operator<<(std::ostream& os, const Complex& z){
    os<<z.re<<" + i"<<z.im<<std::endl;
    return os;
};


int main(){
    
    Complex z1;
    Complex z2;
    z1.re = 2;
    z1.im = 3;
    z2.re = 1;
    z2.im = 2;
    std::cout<<"z1: "<<z1<<" "<<"z2: "<<z2<<std::endl;
    std::cout<<z1+z2<<std::endl;
    std::cout<<z1-z2<<std::endl;
    std::cout<<z1*z2<<std::endl;
    std::cout<<z1/z2<<std::endl; 
    return 0;
}