/*
Virtual function: can be overridden by each derived class. It can have its own implementation in each class. 
If not specifically implemented in a derived class, if that function is called on that derived class, it is iused the implementation
available from the base class

Pure virtual function: is a function declared in the base class and HAS to be implemented in each derived class. If the base class has a pure
virtual function, this class become abstract

'Simple' function: it can be declared in a base class and used in a derived class... ok if we declare and implent it 
in the base class and use it with the derived ones, without redefining it in the derived class. If we redefine it could lead to error/unexpected behaviour
*/

#include <iostream>

class Base{
public:
    // member variable
    int A;
    int B;

    // constructor
    Base(const int& a, const int& b){
        A = a;
        B = b;
    }

    // virtual function
    virtual void print(){
        std::cout<<"virtual function called"<<std::endl;
        std::cout<<A<<std::endl;
    }

    // virtual function 1
        // we don't overrid this one in derived class, to check the compiler correctly calls the base implementation
    virtual void print1(){
        std::cout<<"virtual function 1 called"<<std::endl;
        std::cout<<B<<std::endl;
    }

    // simple member function
    void naive_print(){
        std::cout<<"base naive print called"<<std::endl;
        std::cout<<A<<std::endl;
    }
};

class Derived : public Base{
public:
    // constructor
    Derived(const int& a, const int& b) : Base(a,b) {}

    // override
    void print() override{
        std::cout<<"virtual function ovverridden"<<std::endl;
        std::cout<<A<<" "<<B<<std::endl;
    }

    // simple member function
    void naive_print(){
        std::cout<<"derived naive print called"<<std::endl;
        std::cout<<A<<" "<<B<<std::endl;
    }
};

int main(){
    Base base(1,1);
    base.print();
    base.print1();
    base.naive_print();

    Derived derived(0,0);
    derived.print();
    derived.print1();
    derived.naive_print();

    // polymorhpism
    std::cout<<"poly"<<std::endl;
    Base* pbase;
    pbase = &derived;
    std::cout<<pbase->A<<std::endl;
    std::cout<<pbase->B<<std::endl;
    std::cout<<"print() is overridden: it is used the 'right' implementation"<<std::endl;
    pbase->print();
    pbase->print1();
    std::cout<<"naive_print() is not virtual: it is used the 'wrong' implementation"<<std::endl;
    pbase->naive_print();

    std::cout<<"not poly"<<std::endl;
    Derived* pderived;
    pderived = &derived;
    std::cout<<pderived->A<<std::endl;
    std::cout<<pderived->B<<std::endl;
    pderived->print();
    pderived->print1();
    pderived->naive_print();
    return 0;
}


