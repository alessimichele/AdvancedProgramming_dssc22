#include <iostream>

class complex{
public:
    double re;
    double im;
    
    // default constructor
    complex();

    // parameter constructor
    complex(const double& re0, const double& im0):re(re0),im(im0){};

    // declare operator as a member function
    complex operator+(const complex& z);
};

/*
Differences:
    in declaring the member function i use only one parameter, that is why:
    - The overloaded operator must be added as a member function of the left operand.
    - The left operand becomes the implicit *this object
    - All other operands become function parameters.

    Converting a friend overloaded operator to a member overloaded operator is easy:

    The overloaded operator is defined as a member instead of a friend (Cents::operator+ instead of friend operator+)
    The left parameter is removed, because that parameter now becomes the implicit *this object.
    Inside the function body, all references to the left parameter can be removed.
*/

// define the member function.
complex complex::operator+(const complex& z){
    complex result(0,0);
    result.re=re+z.re;
    result.im=im+z.im;
    return result;
};


int main(){
    complex z1(2,3);
    complex z2(0,1);
    complex res = z1 + z2;
    std::cout<<"re:"<<res.re <<" im:"<<res.im<<std::endl;
    return 0;
}
