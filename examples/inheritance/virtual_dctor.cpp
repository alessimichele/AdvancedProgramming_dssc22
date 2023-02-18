#include <iostream>
//TL;DR: if destructor is not virtual, you risk leaking memory

// if a function is not override, the base one gets called. So if we don't make the destructor in the base class virtual, can happen that 
// destructor of derived class is not called when it should be. 

// the problem is that when an object (an instance) of a derived class is deleted trough a pointer to a base class, if base destructor 
// is not virtual, the derived destructor don't get called, and this can cause memory leaks or other issues.


/*
the base destructor is not declared as virtual, and this can cause issues when deleting objects of the derived class through a pointer to the base class. 
When a derived class object is deleted through a pointer to the base class, if the destructor of the base class is not virtual, 
then only the destructor of the base class will be called, and the destructor of the derived class will not be called. 
This can lead to memory leaks or other issues, particularly if the derived class has dynamically allocated resources that need to be freed.
*/

template <typename T>
class CBase1{
public:    
    T field1; 
    CBase1(const T& f0):field1(f0){};
   // virtual 
    ~CBase1(){std::cout<<"base dctor called"<<std::endl;};
};

template <typename T>
class CDerived1:public CBase1<T>{
public:
    T field2; 
    T* arr;
    CDerived1(const T& f0):CBase1<T>(f0){
        field2=f0;
        arr=new int[10];
    };
   ~CDerived1(){delete[] arr; std::cout<<"derived dctor called"<<std::endl;}
};


int main(){
    
// CDerived1<int> c(11);
// std::cout<<c.field1<<" "<<c.field2<<std::endl;

//this is how it's written in most examples/tutorials, but it hardly makes sense like that:
//CBase1<int>* ptr=new CDerived1<int>(7);
//instead: 
CDerived1<int>* c1 = new CDerived1<int>(12);
CBase1<int>* ptr=c1;
delete ptr;

return 0;   
} 
