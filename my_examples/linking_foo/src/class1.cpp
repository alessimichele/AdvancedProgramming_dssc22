#include "../include/class1.hpp"

Class1::Class1(const int& a1, const int& a2){
    var1 = a1;
    var2 = a2;
}

int Class1::sum(const int& a){
    return var1 + var2 +a;
}