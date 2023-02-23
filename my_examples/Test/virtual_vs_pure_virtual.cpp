/*
Virtual function: can be overridden by each derived class. It can have its own implementation in each class. 
If not specifically implemented in a derived class, if that function is called on that derived class, it is iused the implementation
available from the base class

Pure virtual function: is a function declared in the base class and HAS to be implemented in each derived class. If the base class has a pure
virtual function, this class become abstract

'Simple' member function: it can be declared in a base class and used in a derived class... ok if we declare and implent it 
in the base class and use it with the derived ones, without redefining it in the derived class. If we redefine it could lead to error/unexpected behaviour
*/

#include <iostream>

class Base{
public:
    // member variable
    int A;
    int B;

    // constructor
        // unuseful for initialize Base's instances (cause we cant' have ones)
        // still "logically" useful to initialized derived class instances
    Base(const int& a, const int& b){
        A = a;
        B = b;
    }

    // pure virtual function
    virtual void print()=0;

    // virtual function
        // it can be never being called on Base objects, cause Base can't have instances
        // anyway, it can be called by instance of derived class
    virtual void naive_print(){
        std::cout<<"virtual function called"<<std::endl;
        std::cout<<A<<std::endl;
    }
};

class Derived : public Base{
public:
    // constructor
    Derived(const int& a, const int& b) : Base(a,b) {}

    // override pure virtual function
    void print() override{
        std::cout<<"pure virtual function overridden"<<std::endl;
        std::cout<<A<<" "<<B<<std::endl;
    }
};

int main(){
    Derived derived(0,0);
    derived.print();
    derived.naive_print();

    // polymorhpism
    std::cout<<"poly"<<std::endl;
    Base* pbase;
    pbase = &derived;
    std::cout<<pbase->A<<std::endl;
    std::cout<<pbase->B<<std::endl;
    pbase->print();
    pbase->naive_print();

    std::cout<<"not poly"<<std::endl;
    Derived* pderived;
    pderived = &derived;
    std::cout<<pderived->A<<std::endl;
    std::cout<<pderived->B<<std::endl;
    pderived->print();
    pderived->naive_print();
    return 0;
}


