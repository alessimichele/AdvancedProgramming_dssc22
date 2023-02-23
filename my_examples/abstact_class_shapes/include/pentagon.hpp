#pragma once
#include "shape.hpp"
#include <cmath>

class Pentagon: protected RegularPolygon{
public:
    Pentagon(const double& l){
        L = l;
    }

    double getApothem() override{
        return L/(2*std::tan(M_PI/5));
    }

    double getArea() override{
        return (L/(2*std::tan(M_PI/5)))*5*(L/2);
    }

    double getPerimeter() override{
        return 5*L;
    }
private:
    double L;
};