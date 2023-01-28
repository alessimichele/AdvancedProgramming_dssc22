#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class complex{
public:
    double re;
    double im;

    complex();

    complex(const double& re0, const double& im0):re(re0), im(im0){};
};

#endif