// Rewrite your Matrix multiplication exercise using smart 
// (unique) pointers to store the data instead of vectors.

// the following are equivalent:
// data.reset(new T[N])  
// data = std::make_unique<T[]>(N) 

#include <iostream>
#include <memory>
#include <fstream>
#include <string>

template <typename T>
class Matrix{
public:
    int size;
    std::unique_ptr<T[]> data;
    
    // default constructor
    Matrix();

    // constructor
    Matrix(int N);

    // copy constructor
    Matrix(const Matrix<T>& p);

    // move copy constructor
    Matrix(Matrix<T>&& p);

    // assignement operator
    Matrix<T> operator=(const Matrix<T>& p);

    // move assignement operator
    Matrix<T> operator=(Matrix<T>&& p);

    // overload *
    Matrix<T> operator*(const Matrix<T>& p);

    // useful functions
    void read_from_file(std::string filename);

    void write_on_file(std::string filename);

    void print();
};

// default constructor
template <typename T>
    Matrix<T>::Matrix(){}

// constructor
template <typename T>
    Matrix<T>::Matrix(int N){
        data = std::make_unique<T[]>(N*N);
        size = N;
        std::cout<<"Constructor called"<<std::endl;
    }

// copy constructor
template <typename T>
    Matrix<T>::Matrix(const Matrix<T>& p){
        if (this != &p){
            size = p.size;
            if (p.data == nullptr){
                data.reset(nullptr);
            }else{
                data = std::make_unique<T[]>(size*size);
                for (int i = 0; i < size*size; i++)
                {
                    data[i] = p.data[i];
                }
            }
        }
    }

 // move copy constructor
 template <typename T>
    Matrix<T>::Matrix(Matrix<T>&& p){
        if (this != &p){
            size = p.size;
            p.size = 0;
            data = std::move(p.data);
        }
    }

// assignement operator
template <typename T>
    Matrix<T> Matrix<T>::operator=(const Matrix<T>& p){
        if (this != &p){
            size = p.size;
            if (p.data.get() == nullptr){
                data.reset(nullptr);
            }else{
                data = std::make_unique<T[]>(size*size);
                for (int i = 0; i < size*size; i++)
                {
                    data[i] = p.data[i];
                }
            }
        }
    return *this;
    }

// move assignement operator
template <typename T>
    Matrix<T> Matrix<T>::operator=(Matrix<T>&& p){
        if (this != &p){
            size = p.size;
            p.size = 0;
            data = std::move(p.data);
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
            data = std::make_unique<T[]>(size*size);
            for (int i = 0; i < size*size; i++)
            {
                filevar>>data[i];
            }
            filevar.close();
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
    // Matrix<double> E=std::move(B); // same as line above?
    E.write_on_file("E.txt"); // shoul be the same of B.txt
    B.write_on_file("B_test.txt"); // has zero there, as we have destroyed B
    return 0;

}