#include "include/circle.hpp"
#include "include/pentagon.hpp"
#include "include/rectangle.hpp"
#include "include/shape.hpp"
#include "include/square.hpp"
#include "include/triangle.hpp"
#include <iostream>


int main(){
    Triangle t(1);
    Square s(1);
    Rectangle r(2,3);
    Circle c(1);
    Pentagon p(1);
    std::cout<<t.getApothem()<<std::endl;
    std::cout<<t.getArea()<<std::endl;
    std::cout<<t.getPerimeter()<<std::endl;
    std::cout<<s.getArea()<<std::endl;
    std::cout<<s.getApothem()<<std::endl;
    std::cout<<s.getPerimeter()<<std::endl;
    std::cout<<p.getArea()<<std::endl;
    std::cout<<p.getApothem()<<std::endl;
    std::cout<<p.getPerimeter()<<std::endl;
    std::cout<<r.getArea()<<std::endl;
    std::cout<<r.getPerimeter()<<std::endl;
    std::cout<<c.getArea()<<std::endl;
    std::cout<<c.getPerimeter()<<std::endl;
}