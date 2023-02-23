#pragma once
#include "shape.hpp"
#include <cmath>

class Rectangle: protected Shape{
public:
    Rectangle(const double& b,const double& h ): B(b), H(h){}

    double getArea() override{
        return B*H;
    }

    double getPerimeter() override{
        return 2*B + 2*H;
    }
private:
    double B;
    double H;
};