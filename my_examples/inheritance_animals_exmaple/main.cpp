#include "./include/animal.hpp"
#include "./include/cat.hpp"
#include "./include/dog.hpp"

int main(){
    Animal animal;
    Dog dog;
    Cat cat;

    Animal* p1;
    Animal* p2;
    p1 = &dog;
    p2 = &cat;
   

    p1->voice();
    p2->voice();
}