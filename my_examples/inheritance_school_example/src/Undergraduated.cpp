#include "../include/Undergraduated.hpp"

// constructor (using constructor of Student for shared attributes)
// syntax to implement the constructor of a child class, using the constructor of the parent class and adding 
// eventuali other attributes (member variable) that belongs only to the child class

Undergraduated::Undergraduated(std::string name, int id, std::string major, int year) : Student(name, id, major){
    this->year = year;
}

void Undergraduated::getInfo(){
    std::cout<< year<<std::endl;
}