#include <iostream>
#include <cmath>

bool check(double& a, double& b){
    return a==b;
}



bool truecheck(double& a, double& b){
    double epsilon= 0.01;
    return fabs(a-b)< epsilon;
}

int main(){
    double a = 0.1 + 0.2;
    double b = 0.3;
    std::cout<<check(a,b);
    std::cout<<truecheck(a,b);
}