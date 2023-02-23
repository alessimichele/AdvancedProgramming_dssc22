#pragma once

class Shape{
protected:
    // pure virtual function (i.e. it mustbe overridden by each child class)
    virtual double getArea()=0;
    virtual double getPerimeter()=0;
};

class RegularPolygon: protected Shape{
public:
    virtual double getApothem()=0;
};