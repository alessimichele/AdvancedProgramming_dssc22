#ifndef UNIQUE
#define UNIQUE

#include <iostream>
#include <memory>

// no more delete needed
// this object will call delete[] automatically when going out of scope, so you don’t have to worry about freeing the memory manually.
// if you need to pass the pointer to a C-Style function, use p.get() to get the raw pointer. 
// however, you need to trust the function to not try to deallocating the memory as that would crash your program.

#include "vector.hpp" // need this to import "print_address()" function

void unique(){
    std::unique_ptr<int[]> array(new int[5]);

// std::unique_ptr initializes its elements to 0
    // it will create more space if needed (not that clear waht happen if we pass more than 5 value to put inside)
    // probabily it manages internally how to deal with resize
    for(int i=0;i<5;i++){
        std::cout<<array[i]<<" ";
    }
// fill
    for(int i=0;i<5;i++){
        array[i]=i;
        std::cout<<array[i]<<" ";
    }

std::cout<<std::endl;
// pass to C-style function "print_address"
    print_address(array.get());
}

#endif
