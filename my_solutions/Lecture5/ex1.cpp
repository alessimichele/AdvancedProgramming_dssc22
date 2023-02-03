// Rewrite your Matrix multiplication exercise using raw pointers to 
// store the data instead of vectors.
// row pointers means "normal pointers"...
// int a=1;
// int* p;
// p = &a;
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
class Matrix{
    // int size; // if want size to be private
public:
    int size;
    T* data;

    // default constructor
    Matrix();

    // constructor
    Matrix(int n);

    // destructor
    ~Matrix();

    // copy constructor
    Matrix(const Matrix<T>& p);

    // move constructor
    Matrix( Matrix<T>&& p);

    // assignement operator
    Matrix<T> operator=(const Matrix<T>& p);

    // move assignement operator
    Matrix<T> operator=( Matrix<T>&& p);

    // overload *
    Matrix<T> operator*(const Matrix<T>& B);

    // useful functions
    void read_from_file(std::string filename);

    void write_on_file(std::string filename);

    void print();
    
};

// default constructor
template <typename T>
    Matrix<T>::Matrix(){
        size = 0;
        data = nullptr;
    }

// costructor
template <typename T>
    Matrix<T>::Matrix(const int n){
        size = n;
        data = nullptr;
        std::cout<<"constructor called on: "<<data<<std::endl;
        if (n > 0){
            data = new T[n*n];
        };
    }

// destructor
template <typename T>
    Matrix<T>::~Matrix(){
        // to see on which object I call the destructor
        std::cout<<"destructor called on"<<data<<std::endl;
        if (data != nullptr){
            delete[] data;
            data = nullptr;
            size = 0;
        } 
    }

// copy constructor
template <typename T>
    Matrix<T>::Matrix(const Matrix<T>& p){
        std::cout<<"copy constructor called on"<<data<<std::endl;
        size = p.size;
        data = nullptr;
        if (p.data != nullptr){ 
            data = new T[size*size];
            for (int i = 0; i < size*size; i++)
            {
                data[i] = p.data[i];
            }
        }
    }

// move constructor
template <typename T>
    Matrix<T>::Matrix( Matrix<T>&& p){
        std::cout<<"move constructor called "<<std::endl;
        if (this != &p){
            size = p.size;
            p.size = 0;
            data = p.data;
            p.data = nullptr;
        }
    }

// assignement operator
template <typename T>
    Matrix<T> Matrix<T>::operator=(const Matrix<T>& p){
    std::cout<<"asignement operator called on"<<data<<std::endl;
    if (this != &p){
        size = p.size;
        if (p.data != nullptr){
            if (data != nullptr){delete[] data;} 
            data = new T[size*size];
            for (int i = 0; i < size*size; i++)
            {
                data[i] = p.data[i];
            }
        } else { // p.data == nullptr
            if ( data != nullptr) {delete[] data;}
                data = nullptr;
        }
    }
    return *this;
    }

// move assignement operator
template <typename T>
    Matrix<T> Matrix<T>::operator=( Matrix<T>&& p){
    std::cout<<"move asignement operator called on"<<data<<std::endl;
    if (this != &p){
        size = p.size;
        p.size = 0;
        if (data != nullptr){
            delete[] data;
        }
        data = p.data;
        p.data = nullptr;
    }
    return *this;
    }

// overload *
template <typename T>
    Matrix<T> Matrix<T>::operator*(const Matrix<T>& B){
    if (size != B.size){
        std::cout<<"Error: cannot perform matri multiplication with different size"<<std::endl;
        return 0;
    }
    Matrix<T> C(size);
    T tmp_sum;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            tmp_sum=0;
            for (int k = 0; k < size; k++)
            {
                tmp_sum += data[i*size + k]*B.data[k*size + j];
            }
            C.data[i*size + j] = tmp_sum;
        }
    }
    return C;
    }

// useful functions
template <typename T>
    void Matrix<T>::read_from_file(std::string filename){
        std::ifstream filevar(filename);
        if (filevar){
            filevar>>size;
            data = new T[size*size];
            for (int i = 0; i < size*size; i++)
            {
                filevar>>data[i];
            }
            filevar.close();
        }
    }

template <typename T>
    void Matrix<T>::print(){
        std::cout<<"Matrix:"<<std::endl;
        for (int i = 0; i < size*size; i++)
        {
            std::cout<<data[i]<<" ";
            if ((i+1)%size == 0){
                std::cout<<""<<std::endl;
            }
        }
    }

template <typename T>
    void Matrix<T>::write_on_file(std::string filename){
        std::ofstream filevar(filename);
        if (filevar){
            filevar<<size<<std::endl;
            if (data != nullptr){
                for (int i = 0; i < size*size; i++){
                    filevar<<data[i]<<" ";
                    if ((i+1)%size == 0){
                        filevar<<std::endl;
                    }
                }   
            }
        filevar.close();
        }
    }

int main(){
    Matrix<double> A,B;
    A.read_from_file("A.txt");
    B.read_from_file("B.txt");

    auto C = A*B;
    C.write_on_file("C.txt");
    C.print();

    // assignement operator
    C=A; // call assignement operator
    C.write_on_file("A_copy1.txt"); // should be the same of A.txt
    
    // copy constructor
    Matrix<double> D(A); // call copy constructor
    D.write_on_file("A_copy2.txt"); // shoul be the same of A.txt
    
    // move assignement operator
    C=std::move(A); // call move assignement operator
    C.write_on_file("A_copy3.txt"); // shoul be the same of A.txt
    A.write_on_file("A_test.txt"); // has zero there, as we have destroyed A
    
    // move copy constructor
    Matrix<double> E(std::move(B)); // call move copy constructor
    E.write_on_file("E.txt"); // shoul be the same of B.txt
    B.write_on_file("B_test.txt"); // has zero there, as we have destroyed B
    return 0;

}



/*
main di prova
int main(){
    // Matrix A
    Matrix<int> A(2);
    std::cout<<A.size<<", memory address:"<<A.data;
    A.print();
    // fill Matrix A with 0,1,2,3
    for (int i = 0; i < A.size*A.size; i++)
    {
        A.data[i] = i;
    }
    A.print();
    A.write_on_file("A.txt");
    // Matrix B
    Matrix<int> B(2);
    // fill Matrix B with 1,0,0,1
    B.data[0] = 1;
    B.data[1] = 0;
    B.data[2] = 0;
    B.data[3] = 1;
    B.print();
    auto C = A*B;
    C.print();
    Matrix<int> Z;
    Z=A;
    Z.print();

    
    Matrix<double> D,E;
    std::cout<<D.size<<", memory address:"<<D.data;
    std::cout<<E.size<<", memory address:"<<E.data;
    
    D.read_from_file("D.txt");
    D.print();
    E.read_from_file("E.txt");
    E.print();

    Matrix<double> F = D*E;
    F.write_on_file("result.txt");
    F.print();

    std::cout<<"Experiments with move/copy constructor"<<std::endl;
    A.print();
    Matrix<int> A_1(A); // copy constructor
    A_1.write_on_file("A_1.txt");
    C=A; // assignement operator
    C.write_on_file("A_copy.txt"); 
    return 0;
}
*/

