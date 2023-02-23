#pragma once

#include <string>

class Student{
public:
    std::string name;
    int id;
    std::string major;

    // student is a virtual class but we define a constructor anyway, beacuase we use this constructor as
    // base point constructor for constructor of the child class

    // nb since it is an abstract class, we cannot have instances of this class, but we can have a constructor anyway
    // constructor
    Student(std::string name, int id, std::string major);

    virtual void getInfo()=0;
};