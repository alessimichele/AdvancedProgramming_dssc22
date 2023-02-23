#pragma once

#include "Student.hpp"
#include <iostream>
#include <string>

// different way to define the constructor.

// now in the .cpp file we dont need the definition of the constructr anymore. We need only the definition of getInfo()
class SomeOther : public Student {
public:
    SomeOther(std::string name, int id, std::string major, std::string thesis) : Student(name, id, major), thesis(thesis) {}
    
    // new attribute for SomeOther, which is not in Student class
    std::string thesis;
    void getInfo() override; 
};