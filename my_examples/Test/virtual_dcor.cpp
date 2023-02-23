#include <iostream>

class CBase1{
public:    
    // member variable
    int field1; 

    // cosntructor
    CBase1(const int& f0) : field1(f0){};

    // destructor
    virtual ~CBase1(){
        std::cout<<"base dctor called"<<std::endl;
    };
};

class CDerived1:public CBase1{
public:
    // member variable (a pointer)
    int* arr;

    // constructor (define a dynamic array on the heap of size 10)
    CDerived1(const int& f0) : CBase1(f0){
        arr = new int[10];
    };

    // destructor (free array)
   ~CDerived1(){
        delete[] arr; 
        std::cout<<"derived dctor called"<<std::endl;
    }
};

//examples of dynamic polymoprhism
 
class Polygon {
  public:
    // member variable
    int width, height;

    // member base function 
    void set_values (int a, int b){ 
        width=a; height=b; 
    }

    // virtual base function (ready to be overridden by the derived class)
   virtual int area (){ 
        return 0; 
    }
};

class Rectangle: public Polygon {
  public:
    
    //override helps compiler and makes sure you don't type anything wrong
    int area() override{ 
        return width * height;
    }
};

class Triangle: public Polygon {
  public:
    int area() override{ 
        return (width * height / 2); 
    }
};

int main () {
    Rectangle rect;
    Triangle trgl;
    Polygon poly;

    // access instance of derived clas (rect) through a pointer to the base class ppoly1
    Polygon* ppoly1 =  &rect;
    Polygon* ppoly2 = &trgl;
    Polygon* ppoly3 = &poly;
    ppoly1->set_values (4,5);
    //ppoly2->set_values (4,5);
    trgl.set_values(4,5);
    ppoly3->set_values (4,5);
    std::cout << ppoly1->area() << std::endl;
    std::cout << trgl.area() << std::endl;
    std::cout << ppoly3->area() << std::endl;

    // CBase1 CDerived1 example
    
    // derived dctor called and base dctor called when program goes out of scope (at the end of the main)
    CDerived1 cderived1(7);
    // with the following syntax, I manage a CDerived1 object through a pointer (called 'pointer') to CBase1 class (base class)
    CBase1* pointer = &cderived1;
    // in this case, no need to free the memory, because it is freed automatically by the program when go out of scope


    // This line of code creates a new object of the CDerived1 class, with the argument 7 passed to its constructor, and returns a pointer to the base class CBase1. 
    // This is possible because CDerived1 is a derived class of CBase1, and therefore an object of type CDerived1 can be used as an object of type CBase1.
    // The new operator allocates memory on the heap to store the object, and returns a pointer to the first byte of that memory block. 
    // The pointer is then assigned to the variable pointer_quick, which is of type CBase1*.
    // As a result, pointer_quick now points to the object of type CDerived1 created on the heap. 
    // Because CDerived1 is a derived class of CBase1, you can use pointer_quick to call any of the public member functions of CBase1, as well as any public member functions of CDerived1 that are not overridden by CBase1. 
    // If you want to call a member function that is overridden by CDerived1, you can use virtual functions, which ensure that the correct implementation is called at runtime.
    CBase1* pointer_quick = new CDerived1(7);

    // we define a new object of type CDerived1 on the heap (using keyword 'new') and we return a pointer to that object,
    // which is then assigned to c1. This pointer can be used to access the object and invoke its methods.
    // in other words...
    // we dynamically allocates an object of CDerived1 on the heap and initializes it with the value 12. 
    // The "new" operator returns a pointer to the newly created object, which is then stored in the variable c1.
    CDerived1* c1 = new CDerived1(12);
    CBase1* ptr=c1;

    //delete pointer; // dosent make sense because nothing pointer is pointint to is allocated on the heap
    delete pointer_quick; 
    delete ptr;

    return 0;   
} 
