#ifndef coeff_f
#define coeff_f

#include <iostream>
#include <string>
#include <cmath>

template <typename T>
class coeff{
public:
    T a;
    T b;
    T c;
    coeff(){
    a=0;b=0;c=0;
    };
    
    /*
    coeff(const T& a0, const T& b0, const T& c0 ){
    a=a0; b=b0; c=c0;
    };
    */

    // coeff(const T& a0, const T& b0, const T& c0 );
    void print();
    void ask_for_input();
};

/*
template<typename T>
coeff<T>::coeff(const T& a0, const T& b0, const T& c0){
    a=a0;
    b=b0;
    c=c0;
}
*/

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



#endif