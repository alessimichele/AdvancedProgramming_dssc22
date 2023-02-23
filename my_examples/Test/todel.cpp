#include <iostream>
#include <fstream>



template <typename T>
void print(std::ostream& os, const T& val ){
    os<<val<<std::endl;
    //return os;
};

int main(){
    std::ofstream ofilevar("faciu.txt");
    print<int>(ofilevar, 3);
    print<int>(std::cout,3);
    return 0;
}