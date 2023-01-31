#ifndef COEFF_H
#define COEFF_H
#include <iostream>
#include <string>
#include <fstream>

class coeff{
public:
    double a;
    double b;
    double c;

    coeff(){
        a=0;
        b=0;
        c=0;
    };

    void ask_for_input();

    void print();

    void coeff_from_file(std::string filename);

};

void coeff::ask_for_input(){
    std::cout<<"Insert your coefficients:"<<std::endl;
    std::cin>>a>>b>>c;
    if (a==0)
    {
        std::cout<<"a must be not 0"<<std::endl;
        exit(1);
    };
}

void coeff::print(){
    std::cout<<"Your coefficients are: "<<a<<", "<<b<<", "<<c<<std::endl;
}


void coeff::coeff_from_file(std::string filename){
    std::ifstream filevar(filename);
    if (filevar)
    {
        filevar >> a>> b>> c;
    };
}

#endif