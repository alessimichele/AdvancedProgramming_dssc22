#pragma once
#include "shape.hpp"
#include <cmath>

class Circle: protected Shape{
public:
    Circle(const double& r): R(r){}

    double getArea() override{
        return M_PI*R*R;
    }

    double getPerimeter() override{
        return 2*M_PI*R;
    }
private:
    double R;
};