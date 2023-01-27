#include <iostream>

class Complex{
public:    
    double re;
    double im;

    Complex(){re=0; im=0;}
    
    Complex(const double x, const double y){
      re=x;im=y;  
    }  

     // senza il friend davanti, ho un operatore definito dentro, che prede un solo parametro 
     // con friend avevo era come se fosse una funzione non class-member con accesso alle variabili della classe pero, quindi prendeva 2 parametri
    Complex operator+(const Complex &z){
        Complex res;
        res.re = re + z.re;
        res.im = im + z.im;
        return res;
    };

    Complex operator-(const Complex &z);
    Complex operator*(const Complex &z);
    Complex operator/(const Complex &z);

    friend std::ostream& operator<<(std::ostream& os, const Complex& z);
};

/* //cosi dichiaravo operator come member class function fuori dalla classe
Complex operator+(const Complex &z){
    Complex res;
    res.re = re + z.re;
    res.im = im + z.im;
    return res;
};*/

// cosi invece dichiaro 
Complex Complex::operator-(const Complex &z){
    Complex res;
    res.re = re - z.re;
    res.im = im - z.im;
    return res;
};

Complex Complex::operator*(const Complex &z){
    Complex res;
    res.re = re*z.re - im*z.im;
    res.im = re*z.im + im*z.re;
    return res;
};

Complex Complex::operator/(const Complex &z){
    Complex res;
    res.re = (re*z.re + im*z.im)/(re*re + im*im);
    res.im = (re*z.im - im*z.re)/(re*re + im*im);
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