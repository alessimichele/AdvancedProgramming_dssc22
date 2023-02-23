#pragma once

#include "Student.hpp"
#include <string>
#include <iostream>

// declaration of Undergraduated Class, child of Student Class
// implementation of contructor and getInfo in Undergraduated.cpp

class Undergraduated : public Student{
public:
    int year;

    // constructor
    Undergraduated(std::string name, int id, std::string major, int year);

    // function that return the year 
    void getInfo() override;
};