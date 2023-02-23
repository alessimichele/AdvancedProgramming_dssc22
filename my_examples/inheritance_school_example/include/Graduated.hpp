#include "Student.hpp"
#include <iostream>
#include <string>
 
// declaration of Graduated Class, child of Student Class
// implementation of contructor and getInfo in Graduated.cpp

class Graduated : public Student{
public:
    std::string researchArea;

    // constructor
    Graduated(std::string name, int id, std::string major, std::string researchArea);

    // function that return the researchArea
    void getInfo() override;
};