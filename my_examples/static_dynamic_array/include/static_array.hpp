#ifndef STATIC_ARRAY
#define STATIC_ARRAY

#include <iostream>

void static_array(){

    // note: static arrays live in the stack. This means fast memory access but cannot store big data.
    // note: once the size of a static array is defined at compile time, it cannot be changed at runtime.
    
// static array definition
    int v_static[10]; 
    // define pointer p pointing to the first memory address of v_static
    int* p;
    p = &v_static[0]; // p = v_static is the same

// what if we fill only part of the array? 
    // the remaining part is garbage-stuff, meaning that 'int v_static[10];' don't initializes its values.
    for (int i = 0; i < 5; i++)
    {
        v_static[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout<<v_static[i]<< " ";
    }
    std::cout<<std::endl;


// fill the array
    // 1. using vector aritmetic
    std::cout<<" fill using vector aritmetic"<<std::endl;
    for (int i = 0; i < 10; i++)
    {
        v_static[i] = i;
    }
    // print using index
    for (int i = 0; i < 10; i++)
    {
        std::cout<< v_static[i]<< " ";
    }
    std::cout<<std::endl;

    // 2. using pointer (we'll overwrite 1.)
    std::cout<<" fill using pointer"<<std::endl;
    for (int i = 0; i < 10; i++)
    {
        p[i] = i*i;
    }
    // print using pointer
    for (int i = 0; i < 10; i++)
    {
        std::cout<< p[i]<< " ";
    }
    std::cout<<std::endl;

    // 3. using pointer aritmetic (we'll overwrite 2.)
    std::cout<<" fill using pointer aritmetic"<<std::endl;
    for (int i = 0; i < 10; i++)
    {
        *(p+i) = i*i*i;
    }
    // print using pointer aritmetic
    for (int i = 0; i < 10; i++)
    {
        std::cout<< *(p+i)<< " ";
    }
    std::cout<<std::endl;

// what if we try to fill outside range?
    std::cout<<" fill outside range"<<std::endl;
    for (int i = 0; i < 20; i++)
    {
        v_static[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout<< *(p+i)<< " ";
    }
    std::cout<<std::endl;
    // we get the following error: 'zsh: abort      ./static_dynamic_array.x'


// note: the following won't resize the array: we are just creating a new array v2_static with size 20 an copy inside the element of v_static
// v_static won't be free. We have v_static area filled in the stack AND also v2_static area filled in the stack
    
        int v2_static[20]; 
        // define pointer p pointing to the first memory address of v_static
        int* q;
        q = v2_static;
        for (int i = 0; i < 10; i++)
        {
            q[i] = p[i];
        }
        
        std::cout<<"address of v_static: "<<p<<std::endl;
        std::cout<<"address of v2_static: "<<q<<std::endl;

        // doing this we leave the link to v_static, becuase p is no longer pointing to v_static, but now is pointing to v2_static as q does.
        // doing this it may seem that now we have resized v_static, but this is an error. Actually v_static exists in the stack, and there's no way to actually resize it.
        // that's because there no way to free its memory, beacuse it is a static array!
        p = q;

        // print the array: we see now we have more space, but this is v2_static
        std::cout<<" print the v2_static array: we see now we have more space, but this is v2_static"<<std::endl;
        for (int i = 0; i < 20; i++)
        {
            std::cout<< *(p + i)<< " ";
        }
        std::cout<<std::endl;

        std::cout<<"address of p: "<<p<<std::endl;
        std::cout<<"address of q: "<<q<<std::endl;

        // now define a new pointer to v_static, to show that v_static still exists!
        int* tmp = &v_static[0];
        std::cout<<"note that tmp points to the same address of v_static displayed before:"<<tmp<<std::endl;
    
        for (int i = 0; i < 10; i++)
        {
            std::cout<< *(tmp + i)<< " ";
        }
        std::cout<<std::endl;
}

#endif