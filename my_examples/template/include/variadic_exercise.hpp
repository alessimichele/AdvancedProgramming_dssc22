#ifndef VAREX
#define VAREX

// Write a variadic template function called largest that takes any number of arguments of any type, 
//and returns the largest value.

#include <iostream>

template <typename T>
T largest(const T& val){
        return val;
}

template <typename T, typename... Types>
T largest(const T& first, const Types... args){
    T rest = largest(args...);
    if (first > rest)
    {
        return first;
    }else
    {
        return rest;
    }    
}

#endif