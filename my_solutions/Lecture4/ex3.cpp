#include <iostream>

/*
// normal print function, needed for the base case of the recursion in variadic template

template <typename T>
void normal_print(const T& arg){
    std::cout<<arg<<" ";
}

// we only need << to be overloaded for our type
*/

/*
Passing a const parameter to a function in C++ ensures that the value of the argument won't be 
modified inside the function, making the code safer and more predictable. 
It also allows the compiler to make certain optimizations, since it knows that the value won't 
change. On the other hand, a non-const parameter could be accidentally modified inside the function,
leading to potential bugs or unexpected behavior. Additionally, passing a non-const argument may  
limit the type of arguments that can be passed to the function, as some objects may only be passed 
as const.
*/

// base case
template <typename T>
void my_print(const T& arg){
    std::cout<<arg<<" ";
}

// variadic template

template <typename T, typename... Types>
void my_print(const T& arg, const Types... args){
    std::cout<<arg<<" "<<std::endl;
    my_print(args...);
}

// base case
template <typename T>
T my_sum(const T& arg){
    return arg;
}

// variadic template

template <typename T, typename... Types>
T my_sum(const T& arg, const Types&... args){
    return arg + my_sum(args...);
}

int main(){
    my_print(1,2,3);
    std::cout<<my_sum(1,2,3);
    return 0;
}