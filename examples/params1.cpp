#include <iostream>


int main( int argc, char *argv[] ){
    //argc - number of command line input parameters: when i want to wrtie some function and 
    //passa parameter as: ./a.out 2. Even the name of the program is a parameter.
    // argv[0] is the name of the program
    
    // char *argv[] is a pointer to a vector of c-style string
    //argv - contains the parameters

    //
    
    //you can check if the user forgot to pass an expected parameter:
    if (argc<2){
        std::cout<<"USAGE: "<<argv[0]<<" SOME NUMBERS"<<std::endl;
        
    }
    
    for (int i=0;i<argc;i++){
        std::cout<<argv[i]<<" "; 
    }
    std::cout<<std::endl;
    
    //note that the parameters passed like this are c-strings, so you might need to convert them to something else
    // atoi: transform the string-style parameter nto integer init
    // atof: transofrm the string-style parameter into float (double)
    int a =atoi(argv[1]);
    double b = atof(argv[1]);
    
    std::cout<<a<< " "<<b<<std::endl;
    
    return 0;
} 
