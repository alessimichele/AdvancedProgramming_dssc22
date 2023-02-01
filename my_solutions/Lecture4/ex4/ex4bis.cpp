/*
Write a square matrix class that:
    uses std::vector to store the data
    is templated on the type of the data
    can read/write a matrix to/from file
    has operator * overloaded
    You main function should look similar to
*/
#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>

template <typename T>
class CMatrix{
    int size; // should not be modifiable
public:
    // Default constructor initializes a 2x2 matrix
    CMatrix(){
        size = 2;
        data.resize(4);
    }
    std::vector<T> data;
    // Constructor specified with N elements, allocates a sufficient amount of memory.
    CMatrix(int N){
        size = N;
        data.resize(N*N);
    }
    void print_matrix() const;
    void read_from_file(std::string filename);
    void print_to_file(std::string filename) const;

    // Need to overload the multiplication operator, can make it const
    CMatrix operator*(const CMatrix& B) const;

    template <typename O>
    friend std::ostream& operator<<(std::ostream& os, const CMatrix<O>& A);
};

int main(){
    CMatrix<double> A,B;
    A.read_from_file("A.txt");
    B.read_from_file("B.txt");
    A.print_to_file("test.txt");
    auto C=A*B;
    std::cout<<C;
    C.print_to_file("C.txt");
}

template <typename O>
std::ostream& operator<<(std::ostream& os, const CMatrix<O>& A){
    for(int i = 0; i < A.size; i++){
        for(int j = 0; j < A.size; j++){
            os<<A.data[j+i*A.size]<<" ";
        }
        os<<std::endl;
    }
    return os;
}

template <typename T>
void CMatrix<T>::print_matrix() const{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout<<data[j + i*size]<<" ";
        }
        std::cout<<""<<std::endl;
    }
}

template <typename T>
void CMatrix<T>::read_from_file(std::string filename){
    std::ifstream filevar(filename);
    filevar >> size;
    int n_elements = size * size;
    data.resize(n_elements);
    for (int i = 0; i < n_elements; i++){
        filevar>>data[i];
    }
    filevar.close();
}


template <typename T>
void CMatrix<T>::print_to_file(std::string filename) const{
    std::ofstream filevar(filename);
    filevar << size << std::endl;
    int n_elements = size*size;
    for (int i = 0; i < n_elements; i++){
        filevar << data[i] << " ";
        if ((i+1)%size == 0)
            filevar << std::endl;
    }
    filevar.close();
}

template <typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& B) const{
    if(size != B.size){
        std::cout<<"Can't perform matrix multiplication on square matrices of different sizes"<<std::endl;
        return 0;
    }
    CMatrix<T> C(size);
    T sum;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            sum = 0;
            for(int k = 0; k < size; k++){
                sum += data[k + i*size] * B.data[j + k*size];
            }
            C.data[j + i*size] = sum;
        }

    }
    return C;
}