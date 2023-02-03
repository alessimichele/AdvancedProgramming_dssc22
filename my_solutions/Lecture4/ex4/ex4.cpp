#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
class matrix{
    int size;
public:
    std::vector<T> data;
    
    // default constructor: initialize 1x1 matrix
    matrix(){
        size = 1;
        data.resize(1);
    };

    // parameters constructor
    matrix(int n){
        size = n;
        data.resize(n*n);
    }

    void read_from_file(std::string filename);
    
    matrix<T> operator*(const matrix<T>& B);

    void write_on_file(std::string filename);

    void print();
};

template <typename T>
void matrix<T>::read_from_file(std::string filename){
    std::ifstream filevar(filename);
    filevar>>size;
    int number=size*size;
    data.resize(number); // gli alloco la memoria necessaria
    for (int i = 0; i < number; i++)
    {
        filevar>>data[i];
    }
    filevar.close();
    
}

template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T>& B){
    if (size != B.size)
    {
        std::cout<<"Error: impossible matrix multiplication with different size"<<std::endl;
        return 0;
    }
    
    matrix<T> C(size);
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

template <typename T>
void matrix<T>::write_on_file(std::string filename){
    std::ofstream filevar(filename);
    filevar << size << std::endl;
    int number = size*size;
    for (int i = 0; i < number; i++){
        filevar << data[i] << " ";
        if ((i+1)%size == 0)
            filevar << std::endl;
    }
    filevar.close();
}

template <typename T>
void matrix<T>::print(){
    std::cout<<"Matrix:"<<std::endl;
    for (int i = 0; i < size*size; i++)
    {
        std::cout<<data[i]<<" ";
        if ((i+1)%size==0)
        {
            std::cout<<""<<std::endl;
        } 
    }
}

/*
alternativa al ciclo for:
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout<<data[j + i*size];
        }
        std::cout<<std::endl;
    }
*/

int main(){
    matrix<double> A,B;
    A.read_from_file("A.txt");
    A.print();
    A.write_on_file("prova.txt");
    B.read_from_file("B.txt");
    B.print();
    auto C=A*B;
    C.write_on_file("C.txt");
    C.print();
}