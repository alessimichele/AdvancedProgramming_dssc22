#ifndef DYN_ARR
#define DYN_ARR

#include <iostream>


void dynamic_array(){

    // note: dynamic arrays live in the heap. This means slightly slower performance but we can store big data and resize.
    // to resize we need 'new' and 'delete' keywords (malloc and free like C).

// definition of dynamic array
    // declare a pointer (it will point to the dynamic array)
    int* dynamic_array;
    // use 'new' to get the pointer pointing to a memory address in the heap
    dynamic_array = new int[10]; 
    // note: the 'dynamic_array' as a variable lives in the stack. Its content (a memory address) is in the heap.

    // often this is defined in one line >>> int* dynamic_array = new int[10];
// Initializing dynamically allocated arrays
    //int *array{ new int[5]{ 10, 7, 15, 3, 11 } };


// fill the array
    // 1. using index aritmetic
    for (int i = 0; i < 10; i++)
    {
        dynamic_array[i] = i;
    }
    // print using index
    for (int i = 0; i < 10; i++)
    {
        std::cout<< dynamic_array[i]<< " ";
    }
    std::cout<<std::endl;

    // 3. using pointer aritmetic (we'll overwrite 1.)
    for (int i = 0; i < 10; i++)
    {
        *(dynamic_array + i) = i*i;
    }
    // print using pointer aritmetic
    for (int i = 0; i < 10; i++)
    {
        std::cout<< *(dynamic_array + i)<< " ";
    }
    std::cout<<std::endl;


// resize
    const int new_size = 20; // always good practice to make const the size of array
    
    // allocate a new dynamic array with 20 elements
    int* new_dynamic_array = new int[new_size]; 

    // see that dynamic_array and new_dynamic_array are two pointers pointing to DIFFERENT memory areas in the heap.
    // new_dynamic_array is pointing to an area that can store 20 int contiguously, dynamic_array is pointing to an area that can store 10 int contiguously
    std::cout<<"dynamic_array: "<<dynamic_array<<std::endl;
    std::cout<<"new_dynamic_array: "<<new_dynamic_array<<std::endl;

    // copy the elements from the old array to the new array
    // note: this step makes a bit inefficient the resizing phase, but it is the only way to do it
    for (int i = 0; i < 10; i++) {
        new_dynamic_array[i] = dynamic_array[i];
    }

    // delete the old array
    // note: this step is necessary. 'delete' free the memory, in the sense that for the operating system that area of the heap is free again i.e. it is possibile to overwrite that area and store data.
    // if don't delete, that area of the heap beacame totally unuseful:
        // it is no longer used by the program because we've resized
        // it is no accessible by the operating system anymore
    delete[] dynamic_array;

    // difference with respect to static arrays:
    // we freed the memory area that was occupated by dyamic_array at the beginning 
    std::cout<<"after delete dynamic_array area"<<std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout<< *(dynamic_array + i)<< " ";
    }
    std::cout<<std::endl;

    // assign the new array to the original array pointer
    // from now on, we have no longer access to the memory area that was occupated by dyamic_array at the beginning AND
    // since we have deleted (freed) 'dynamic_array', that area of the heap is available again to the operating system
    dynamic_array = new_dynamic_array;

    // print the array: we see now we have more space
    std::cout<<"print the dynamic_array resized: we see now we have more space"<<std::endl;
    for (int i = 0; i < new_size; i++)
    {
        std::cout<< *(dynamic_array + i)<< " ";
    }
    std::cout<<std::endl;

    // we can see that dynamic_array and new_dynamic_array are two pointers pointing to the same thing
    std::cout<<"we can see that dynamic_array and new_dynamic_array are two pointers pointing to the same thing:"<<std::endl;
    std::cout<<dynamic_array<<" "<<new_dynamic_array<<std::endl;

    // because new_dynamic_array was used only to store the new space, it is no longer useful so make it pending
    new_dynamic_array = nullptr;
    std::cout<<dynamic_array<<" "<<new_dynamic_array;
 
}

/*
int* arr = new int[5];
The code you've provided is dynamically allocating an array of 5 integers using the new operator. This creates an array of integers on the heap, and the memory for the array can be accessed using the pointer arr.

It is important to note that dynamic memory allocation in C++ requires corresponding deallocation to avoid memory leaks. Once you are done using the memory allocated for the array, you should use the delete[] operator to deallocate it:

javascript
Copy code
delete[] arr;
This will free up the memory allocated for the array so it can be used by other parts of the program.



alessimichele00@yahoo.it
new meaning
In C++, new is an operator that is used for dynamic memory allocation. It allows you to allocate memory for an object or an array of objects on the heap, which is a region of memory that is separate from the program's stack and is managed manually.

The new operator returns a pointer to the beginning of the allocated memory. You can use this pointer to access and manipulate the allocated memory.

Here's an example of how to use the new operator to dynamically allocate memory for a single integer:

go
Copy code
int* p = new int;
*p = 42; // assign a value to the allocated integer
// ...
delete p; // free the memory when you are done with it
In this example, the new operator is used to allocate memory for a single integer, and the pointer p is used to access and manipulate the allocated memory. The delete operator is used to free the memory when it is no longer needed.

The new operator can also be used to allocate memory for arrays, as shown in the example you provided:

go
Copy code
int* arr = new int[5];
This allocates memory for an array of 5 integers on the heap, and returns a pointer to the beginning of the array.*/

#endif