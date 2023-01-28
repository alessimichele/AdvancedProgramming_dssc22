#include <iostream>

template <typename T>
class complex{
public:
    T re;
    T im;

    // default constructor
    complex();

    // parameter constructor
    complex(const T& re0, const T& im0):re(re0),im(im0){};

    complex operator+(const complex& z);
    complex operator-(const complex& z);
    complex operator*(const complex& z);

    // this is not a member function
    template <typename O>
    friend std::ostream& operator<<(std::ostream& os, const complex<O>& z);
    

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const complex<T>& z){
    if(z.im>0){
        os<<z.re<<" + i*"<<z.im;
    }else if (z.im<0){
        os<<z.re<<" - i*"<<-z.im;
    }else{
        os<<z.re;
    }
    return os;
};

template <typename T>
complex<T> complex<T>::operator+ (const complex<T>& z){
    complex result(0,0);
    result.re = re + z.re;
    result.im = im + z.im;
    return result;
};

template <typename T>
complex<T> complex<T>::operator- (const complex<T>& z){
    complex result(0,0);
    result.re = re - z.re;
    result.im = im - z.im;
    return result;
};

template <typename T>
complex<T> complex<T>::operator* (const complex<T>& z){
    complex result(0,0);
    result.re=re*z.re-im*z.im;
    result.im=re*z.im+im*z.re;
    return result;
};

