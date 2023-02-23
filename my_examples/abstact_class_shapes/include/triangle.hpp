#pragma once
#include "shape.hpp"
#include <cmath>

class Triangle: protected RegularPolygon{
public:
    Triangle(const double& l):L(l){}

    double getApothem() override{
        return L/(2*std::tan(M_PI/3));
    }

    double getArea() override{
        return (std::sqrt(3)/4)*L*L;
    }

    double getPerimeter() override{
        return 3*L;
    }
private:
    double L;
};
