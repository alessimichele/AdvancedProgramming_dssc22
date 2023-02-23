#ifndef VECTOR
#define VECTOR

// https://www.tutorialspoint.com/difference-between-std-vector-and-std-array-in-cplusplus

// https://stackoverflow.com/questions/13029299/stdvectorresize-vs-stdvectorreserve

/*
reserve does not add any elements to the vector; it only changes the capacity(), 
which guarantees that adding elements will not reallocate (and e.g. invalidate iterators).

resize adds elements immediately. If you want to add elements later (insert(), push_back()), use reserve. 
if you want to access elements later (using [] or at()), use resize. So youre MyClass::my_method can be either:
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

#include <vector>
#include <iostream>

// this function is used at the end of the example to show how to pass vector to C-syle function
void print_address(int* pointer){
    std::cout<<"pointer: "<<pointer<<std::endl;
}

void vector(){

    // define an object from the vector library, which acts as a dynamic array
    std::vector<int> vector1;
    // note:
        // vector is a sequential container to store elements and not index based
        // vector is dynamic in nature so its size increases with insertion of elements (push_back)
        // vector occupies more memory (than std::array)
        // vector takes more time in accessing elements (than std::array)

    
    

// std::vector::resize will actually modify the size of your vector and will fill any space with objects in their default state. If they are ints, they will all be zero.
    // note: resize() actually change the size of the vector AND add elements, which are initializated with 0
    vector1.resize(10);
    // note: vector has default status. If type is int, default is 0
    std::cout<<"note that size actually change after resize(): "<<vector1.size()<<std::endl;
    
    // fill using index give error
    std::cout<<"show first 2 elements are initialized with 0 (actually all elements are init with 0): "<<vector1[0]<<vector1[1]<<std::endl;
    for (int i = 0; i < vector1.size(); i++)
    {
        vector1[i] = i;
        std::cout<<vector1[i]<<std::endl;
    }

// std::vector::reserve will allocate the memory but will not resize your vector, which will have a logical size the same as it was before.
    std::vector<int> vector2;
    // after reserve, in your case, you will need a lot of push_backs to write elements. 
    // if you don't wish to do that then in your case you should use resize.     
    vector2.reserve(10); // reserve enough contiguous space for storing 10 int
    std::cout<<"note that size is not changed, since reserve just allocate enough memory but don't actually modify the size: "<<vector2.size()<<std::endl;
    // fill
    // using push_back build-in method
    for (int i = 0; i < 10; i++)
    {
        vector2.push_back(i);
        std::cout<<vector2[i]<<std::endl;
    }
    

// vector declaration
std::vector<int> vector3{1,1,2,2,3,3,4,4,5,5};
std::cout<< "vector3 is: ";
for (int i = 0; i < vector3.size(); i++)
{
    std::cout<< vector3[i]<<" ";
}

// When you work with C-style functions that require a pointer, you can pass vector’s contents either as &myvec[0] or myvec.data().

// pass "vector3" to a C-style function
    // this won't work
    // >>> print_address(&vector3);

    // these work
    print_address(&vector3[0]);
    print_address(vector3.data());
}



#endif


/*
Getting or setting an item by position in a list (vector) gets or sets the value at the position relative to the beginning of the list. 
Getting or setting the value in an array gets or sets the value at that array position. 
The difference is in the other operations on the list and array.

When you add an item to a list at a position, items after it change their positions relative the the beginning of the list. 
Arrays do not support the add operation. Setting the value of a position in an array changes the value at that position but it does not change the position of items after it.

When you remove an item from a list at a position, items after it change their positions in the list relative to the beginning of the list. 
Arrays do not support the remove operation. You can only set a new value at that position.

The size of a list changes when you add or remove an item. 
With a fixed-length array, setting the value at a position does not change the size of the array.
 With a variable-length array, setting the value at a position beyond the current array size extends the array to encompass that position, and the values of extended positions are either undefined or the ground value of the array element type (e.g. 0, 0.00, or null).

So while both allow getting or setting an item by position, the position of an item in a list (vector) changes when adding or removing items before it. 
The array does not support adding or removing an item so the value at a position only changes by setting it to a new value, and that does not change the position of other items in the array.
*/