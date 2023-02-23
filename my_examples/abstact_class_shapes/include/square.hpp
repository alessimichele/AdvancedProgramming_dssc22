#pragma once
#include "shape.hpp"
#include <cmath>

class Square: protected RegularPolygon{
public:
    Square(const double& l){
        L = l;
    }

    double getApothem() override{
        return L/(2*std::tan(M_PI/4));
    }

    double getArea() override{
        return L*L;
    }

    double getPerimeter() override{
        return 4*L;
    }
private:
    double L;
};