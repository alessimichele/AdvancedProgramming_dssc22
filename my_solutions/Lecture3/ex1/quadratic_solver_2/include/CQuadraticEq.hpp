#ifndef CQUADRATICEC_H
#define CQUADRATICEC_H

#include <iostream>
#include <string>
#include <cmath>

class CQuadraticEq{
public:
    coeff coefficients;
    Complex sol1;
    Complex sol2;

    void solve();

    void print_solution();
};

#endif