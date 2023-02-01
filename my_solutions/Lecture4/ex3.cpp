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






















/*
how variadic template works in c++?
Variadic templates in C++ allow a function or class to accept a variable number of arguments of any type. They are implemented using template recursion and provide a way to write flexible and generic code.

The basic syntax for a variadic template function is as follows:

cpp
Copy code
template <typename T, typename... Args>
void func(T first, Args... args) {
  // processing for the first argument
  ...

  // recursively call the function with the remaining arguments
  func(args...);
}
In this example, T is the type of the first argument, and Args... is a pack of remaining argument types. The function processes the first argument, then calls itself with the remaining arguments. This recursion continues until there are no more arguments to process.

To terminate the recursion, a base case must be provided:

cpp
Copy code
template <typename T>
void func(T t) {
  // processing for the last argument
  ...
}
This function is called when there is only one argument left, and it provides a way to process the final argument.

Variadic templates are useful in several scenarios, such as creating flexible functions that can accept a varying number of arguments, or creating classes that can store a collection of objects of different types. They are a powerful tool for creating generic, reusable code in C++.



alessimichele00@yahoo.it
sum using variadic templates
Here's an example of a variadic template function that calculates the sum of its arguments:

r
Copy code
template <typename T>
T sum(T t) {
  return t;
}

template <typename T, typename... Args>
T sum(T first, Args... args) {
  return first + sum(args...);
}
In this example, sum is a variadic template function that takes a variable number of arguments of any type. The first function, sum(T t), is the base case that terminates the recursion. It simply returns the single argument. The second function, sum(T first, Args... args), is the recursive step. It adds the first argument to the sum of the remaining arguments, which is calculated by calling sum(args...). This recursion continues until there are no more arguments to process, at which point the base case is called.

You can use this function like this:

c
Copy code
int main() {
  std::cout << sum(1, 2, 3, 4, 5) << std::endl; // Output: 15
  return 0;
}
In this example, sum is called with five arguments, and the output is the sum of those arguments.



alessimichele00@yahoo.it
why are you not passing "first" parameter to the function by reference?
Passing first by reference is an option in this case, but it may not always be necessary. The reason for this is that the value of first is only used to calculate the sum and does not need to be modified.

Passing by value incurs a small performance overhead in terms of copying the argument, but it makes the code simpler and easier to understand, since there's no need to worry about any side effects.

If the argument is a large object or if the performance is critical, passing by reference would be a good option to reduce the overhead of copying. But in general, passing by value is a safe and simple approach for small or primitive types like int.

Here's how you would modify the code to pass first by reference:

r
Copy code
template <typename T>
T sum(T& t) {
  return t;
}

template <typename T, typename... Args>
T sum(T& first, Args&... args) {
  return first + sum(args...);
}
*/