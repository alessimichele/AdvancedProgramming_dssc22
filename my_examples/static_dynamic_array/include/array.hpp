#ifndef ARR
#define ARR

#include <array>
#include <iostream>

/*
std::array are more static-array like.
they are defined declaring their type and their size and they cannot be resized
*/

// https://stackoverflow.com/questions/4424579/stdvector-versus-stdarray-in-c

/*
std::vector is a template class that encapsulate a dynamic array1, stored in the heap, that grows and shrinks automatically if elements are added or removed. 
It provides all the hooks (begin(), end(), iterators, etc) that make it work fine with the rest of the STL. 
It also has several useful methods that let you perform operations that on a normal array would be cumbersome, like e.g. inserting elements in the middle of a vector (it handles all the work of moving the following elements behind the scenes).

Since it stores the elements in memory allocated on the heap, it has some overhead in respect to static arrays.

std::array is a template class that encapsulate a statically-sized array, stored inside the object itself, which means that, if you instantiate the class on the stack, the array itself will be on the stack.
Its size has to be known at compile time (it's passed as a template parameter), and it cannot grow or shrink.

It's more limited than std::vector, but it's often more efficient, especially for small sizes, because in practice it's mostly a lightweight wrapper around a C-style array.
 However, it's more secure, since the implicit conversion to pointer is disabled, and it provides much of the STL-related functionality of std::vector and of the other containers, so you can use it easily with STL algorithms & co. 
 Anyhow, for the very limitation of fixed size it's much less flexible than std::vector.
*/


void array(){

    // array definition
    std::array<int, 10> array;
    
    // array won't initialize by default its elements, as shown below
    std::cout<<"array not filled is not initialized: ";
    for (int i = 0; i < array.size(); i++)
    {
        std::cout<<array[i]<<" ";
    }

    std::cout<<std::endl;
    // fill
    std::cout<<"array is: ";
    for (int i = 0; i < array.size(); i++)
    {
        array[i]=i;
        std::cout<<array[i]<<" ";
    }
    

    std::cout<<std::endl;
    // array declaration and initialization
    std::array<int, 5> array1={0,1,2,3,4};
    for (int i = 0; i < array1.size() ; i++)
    {
        array[i]=i;
        std::cout<<array1[i]<<" ";
    }
}

#endif