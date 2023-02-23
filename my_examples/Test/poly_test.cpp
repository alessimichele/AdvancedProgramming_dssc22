/*
Virtual function: can be overridden by each derived class. It can have its own implementation in each class. 
If not specifically implemented in a derived class, if that function is called on that derived class, it is iused the implementation
available from the base class

Pure virtual function: is a function declared in the base class and HAS to be implemented in each derived class. If the base class has a pure
virtual function, this class become abstract

'Simple' function: it can be declared in a base class and used in a derived class... but could lead to error/unexpected behaviour
*/

#include <iostream>

class Base{
public:
    // member variable
    int A;

    // constructor
    Base(const int& a){
        A = a;
    }

    // virtual function
    virtual void print(){
        std::cout<<A<<std::endl;
    }

    // simple member function
    void naive_print(){
        std::cout<<A<<std::endl;
    }
};

class Derived : public Base{
public:
    // member variable
    int B;

    // constructor
    Derived(const int& a, const int& b): Base(a){
        B = b;
    }

    // override
    void print() override{
        std::cout<<A<<" ";
        std::cout<<B<<std::endl;
    }

    // simple member function
    void naive_print(){
        std::cout<<A<<" ";
        std::cout<<B<<std::endl;
    }
};

int main(){
    Base base(1);
    base.print();
    base.naive_print();

    Derived derived(1,0);
    derived.print();
    derived.naive_print();

    // polymorhpism
    std::cout<<"poly"<<std::endl;
    Base* pbase;
    pbase = &derived;
    std::cout<<pbase->A<<std::endl;
    pbase->print();
    return 0;
}


