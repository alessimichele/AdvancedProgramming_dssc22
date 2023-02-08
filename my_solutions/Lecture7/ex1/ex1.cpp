/*
Instead of reading the matrix from a file, get the matrix size 
from the command line parameters and use the random_fill function 
provided in the lecture to fill in a large matrix (around a 1000). 
Add the timing to the matrix multiplication program 
(you can use the easier version of it, the one with std::vector).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <getopt.h>
#include <random>
#include <chrono>

template <typename T>
class matrix{
public:
    int size;
    std::vector<T> data;
    
    // default constructor: initialize 1x1 matrix
    matrix();

    // constructor
    matrix(int n);

    // random fill with given size
    void random_fill();
    
    // * overload
    matrix<T> operator*(const matrix<T>& B);

    // copy matrix content on a file
    void write_on_file(std::string filename);

    // print matrix
    void print();
};

// default constructor: initialize 1x1 matrix
template <typename T>
matrix<T>::matrix(){
        size = 1;
        data.resize(1);
    };

// constructor
template <typename T>
matrix<T>::matrix(int n){
    size = n;
    data.resize(n*n);
}

// random fill with given size
template <typename T>
void matrix<T>::random_fill(){
	constexpr auto low_bound = 0;
	constexpr auto up_bound = 100;

    //take the seed from current time 
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
   
    std::default_random_engine dre(seed);//engine
    std::uniform_int_distribution<int> di(low_bound,up_bound);//distribution
    std::generate(data.begin(), data.end(), [&](){ return di(dre);});//fill
};


// * overload
using CHRONO = std::chrono::steady_clock;

template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T>& B){
    if (size != B.size)
    {
        std::cout<<"Error: impossible matrix multiplication with different size"<<std::endl;
        return 0;
    }
    
    matrix<T> C(size);
    
    std::chrono::time_point<CHRONO> t_start;
    t_start = CHRONO::now();

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
    
    auto t_end = CHRONO::now();
    auto total = std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_start).count();

    std::cout<<"time: "<<total<<std::endl;
    
    std::ofstream filevar("time.txt", std::ios_base::app);
    filevar<<total<<std::endl;

    return C;
}

// copy matrix content on a file
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

// print matrix
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


int main(int argc, char * const argv[]) { 
    // store size of matrix A and B into size_a and size_b
    int size_a{0}, size_b{0};
    int opt{0};
    while( (opt = getopt(argc, argv, "a:b:" )) != -1 ) {
        switch (opt) {
            // if pass -s to the command line, do the following
            case 'a':
                size_a = std::atoi(optarg);
                break;
            case 'b':
                size_b = std::atoi(optarg);
                break;

            // error handling
            default:
                std::cerr << "Usage: " << argv[0] << "[-a value] [-b value]" << std::endl;
                return 1;
        }
    }

    if (size_a != size_b)
    {
        std::cerr<<"Error: size A and size B must be equal"<<std::endl;
        return 1;
    }
    

    // print inserted size
    std::cout<< "Size A: " <<size_a<<", Size B: " <<size_b<<std::endl;

    // build the object
    matrix<int> A(size_a);
    matrix<int> B(size_b);
    A.random_fill();
    B.random_fill();
    A.write_on_file("A.txt");
    B.write_on_file("B.txt");
    auto C = A*B;
    C.write_on_file("C.txt");
    
    return 0;   
}   