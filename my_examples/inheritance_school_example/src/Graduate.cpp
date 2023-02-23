#include "../include/Graduated.hpp"

// syntax to implement the constructor of a child class, using the constructor of the parent class and adding 
// eventuali other attributes (member variable) that belongs only to the child class

Graduated::Graduated(std::string name, int id, std::string major, std::string researchArea) : Student(name, id, major){
    this->researchArea = researchArea;
}

void Graduated::getInfo(){
    std::cout<<researchArea<<std::endl;
}