#include <iostream>


class complex{
public:
    double re;
    double im;
    
    // default constructor
    complex();

    // parameter constructor
    complex(const double& re0, const double& im0):re(re0),im(im0){};

    /* 
    // analogo al precedente ma meno efficiente
    // si dichiara: complex z(re,im);

    complex(const double& re0, const double& im0){
        re = re0;
        im = im0;
    };

    */

    // declare operator as a friend function
    friend complex operator+(const complex& z1, const complex& z2);
};


// define the friend function. This is not a member function.
complex operator+(const complex& z1, const complex& z2){
    // use the complex constructor and operator+(int, int)
	// we can access complex directly because this is a friend function
    return complex(z1.re + z2.re, z1.im + z2.im);
};

// alternative to define +
/*
complex operator+(const Complex &z1, const Complex &z2){
    complex res;
    res.re = z1.re + z2.re;
    res.im = z1.im + z2.im;
    return res;
};
*/

int main(){
    complex z1(2,3);
    complex z2(0,1);
    complex res = z1 + z2;
    std::cout<<"re:"<<res.re <<" im:"<<res.im<<std::endl;
    return 0;
}

// it is possible to define the friend function inside the class. But still it is not a member function
/*
class complex{
public:
    double re;
    double im;
    
    // default constructor
    complex();

    // parameter constructor
    complex(const double& re0, const double& im0):re(re0),im(im0){};

    // declare friend function inside, but it is not a member function
    friend complex operator+(const complex& z1, const complex& z2){
        return complex(z1.re + z2.re, z1.im + z2.im);
    };
};
*/

// another option is normal function: just outside class scope as each function