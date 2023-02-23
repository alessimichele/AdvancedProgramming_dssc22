#include <iostream>
int main(){
float epsilon{0.0000000001};
double x{7.0},y{7.0};
if(x-y < epsilon){
    std::cout<<"x is equal to y"<<std::endl;
}
}