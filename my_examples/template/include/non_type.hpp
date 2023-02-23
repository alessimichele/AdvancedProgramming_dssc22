#ifndef NTYPE
#define NTYPE

#include <iostream>
#include <string>
#include <fstream>

template <typename T, int N>
void non_type(const T& val, std::string filename){
    T result = val + N;
    std::cout<<result;
    std::ofstream filevar(filename, std::ios_base::app);
    filevar<<result<<std::endl;
    filevar.close();
}

// non_type<int, 2>(32, "./file/output_ntype.txt");

#endif