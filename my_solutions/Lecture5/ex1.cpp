// Rewrite your matrix multiplication exercise using raw pointers to 
// store the data instead of vectors.
// row pointers means "normal pointers"...
// int a=1;
// int* p;
// p = &a;
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
class matrix{
    int size;
public:
    T* data;

    // constructor
    matrix(){};

    matrix(int n);

    // destructor
    ~matrix()

    // copy constructor
    matrix(const matrix& p);

    // assignement operator
    matrix operator=(const matrix& p);

    // overload *
    matrix operator*(const matrix& B);

    // useful functions
    void read_from_file(std::string filename);

    void write_on_file(std::string filename);

    void print();
    
};

// costructor
template <typename T>
    matrix<T>::matrix(const int n){
        size = n;
        data = new T[n*n];
        std::cout<<"constructor called"<<std::endl;
    }

// destructor
template <typename T>
    matrix<T>::~matrix(){
        delete[] data;
        data = nullptr;
        size = 0;
        std::cout<<"destructor called"<<std::endl;
    }

// copy constructor
template <typename T>
    matrix<T>::matrix(const matrix<T>& p){
        
    }