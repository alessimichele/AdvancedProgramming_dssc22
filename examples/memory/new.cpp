#include <iostream>

template <typename T>
class MyClass{
public:
    T* data; // i have a pointer to the type T
    MyClass(){};
    MyClass(const int& N);
    ~MyClass(); // destructor is used to call delete
};

template<typename T> 
    MyClass<T>::MyClass(const int& N) {
    data=new T[N];
    for(int i=0;i<N;i++){
        data[i]=i;
    }    
}


template<typename T> 
    MyClass<T>::~MyClass() {
    delete[] data;
    data=nullptr;
    std::cout<<"destructor called"<<std::endl;
}

// memory leak: allocate memory but not deallocate
// new ~ malloc
// delete ~ free
int main(){
   int N{12};
    int* p0 = new int; // "give me enough space for one integer on the heap"
    int* p =new int[N]; 
    for(int i=0;i<N;i++){
        p[i]=i;
        std::cout<<p[i]<<" ";
    }
    std::cout<<std::endl;

    delete p0;
    delete[] p; 
    
    MyClass<int> obj(10);
    
    
    return 0;
}
