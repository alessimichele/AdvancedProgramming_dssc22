#ifndef COEFF_H
#define COEFF_H

#include <iostream>
#include <string>
#include <cmath>

class coeff{
public:
    double a;
    double b;
    double c;
    coeff(){a=0;b=0;c=0;};
    void print();
    void ask_for_input();
};

#endif