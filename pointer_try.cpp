#include <iostream>

int main(){
    int v[10];
    int w[5];
    int* p;
    int* q;
    int* r;
    p = &v[0];
    q = v;
    r = &w[0];
    std::cout<<p<<std::endl;
    std::cout<<q<<std::endl;
    std::cout<<r<<std::endl;
    for (int i = 0; i < 10; i++)
    {
        p[i]=i;
    }
    std::cout<<""<<std::endl;

    for (int i = 0; i < 5; i++)
    {
        *(r+i)=i;
    }
    std::cout<<""<<std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout<<v[i];
    }
    std::cout<<""<<std::endl;
     for (int i = 0; i < 5; i++)
    {
        std::cout<<w[i];
    }
    
}

/*
template <typename T>
class MyClass{
public:
    T* data; // i have a pointer to the type T
    MyClass(){};
    MyClass(const int& N);
};

template<typename T> 
    MyClass<T>::MyClass(const int& N) {
    data=new T[N];
    for(int i=0;i<N;i++){
        data[i]=i;
    }    
}
This is a C++ template class named "MyClass" that takes a template parameter T. The class has a public member variable data which is a pointer to the type T. The class also has a default constructor and a constructor that takes an int reference as input and allocates an array of T with size N. The constructor then initializes the elements of the array with values from 0 to N-1.



alessimichele00@yahoo.it
data is a pointer, so why I do not initialize the value with *data?
data is a pointer, so you can initialize its value with new operator which returns the address of the first element of the dynamically allocated array.

In this case, you're allocating an array of T with new T[N] and storing the address of the first element in the data pointer. So data now points to the first element of the array.

When you want to access an element of the array, you can use the data pointer and an index, like data[i], to get the value at that index. You don't need to use *data because data already holds the address of the first element of the array.



alessimichele00@yahoo.it
so data[i] means "move i positions from the first allocation and tell me the value stored at this allocation?"
Yes, that's correct! data[i] means "go to the i-th element of the array starting from the first element pointed to by data and retrieve its value."

In C++, when you use the [] operator on a pointer, it performs pointer arithmetic by automatically advancing the pointer by the size of the type it's pointing to, so data[i] is equivalent to *(data + i).

This allows you to access the elements of an array using a convenient syntax, as if the pointer were an array.



alessimichele00@yahoo.it
so if I say: int v[10]; //declare an array
int* p; //declare a pointer
p = &v; //pointer points to the vector
for(int i=0, i<10, i++){
	p[i]=i;}

I end up with an array v which is 0 1 2 3 4 5 6 7 8 9?
Yes, that's correct! If you declare an array v with int v[10], and a pointer p with int *p, and then assign the address of v to p with p = &v[0] or p = v, you can use p to access the elements of v as if it were an array. In the for loop, you're using the pointer p and the index i to assign the values 0 to 9 to the elements of the array v. So after the loop, the array v will contain the values 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.*/