*The notes do not constitute a full reference book, please attend lectures, watch videos or read something else to fully understand the material. They are nothing more than "notes".*

### Functions

If you have tried to do the last lecture homework, you might have realized that retyping the same code over and over becomes unfeasible very soon. This is why we need functions.

A function is a block of code that performs some operation. It can take input parameters and it can return a value as output. If it doesn't return any value, it's return type is `void`. The simplest function you can write is:

```
void function(){};
```

This function does nothing. Let's make it do something.

```
void function(){
    std::cout<<"Hello, World!" <<std::endl;
}
```

If we need to return a value we need to specify the return type:

```
int function(){
   std::cout<<"I am a function that returns 77"<<std::endl;
   return 77;
}
```

To call a function, you do the following (inside `main`, or inside another function)

```
function();  //<---- it the return type is void
```

or 

```
int result = function();
```

If you are not sure which type the function returns or the return type is way too long (we will see such examples later), you use **auto** keyword

```
auto result = function();
```

#### Passing parameters to functions:

You function may need input parameters

```
int add_two(int a){
    return a+2;
}
```

Please note that the name of a parameter in a function definition is a "dummy", it can be whatever and if you write

```
int a;
int b = add_two(a);
```

*this is not the same a*.


What if you want to modify that parameter?

```
void add_two_ref(int& a){
    a=a+2;
}
```

This is called passing by reference.

Pass-by-reference means to pass the reference of an argument in the calling function to the corresponding formal parameter of the called function.

Note that if you do

```
void add_two_wrong(int a){
    a=a+2;
}
```

your variable will not get changed.
Facendi cosi, succede questo in pratica:
tu mi passi a, io (funzione) ne faccio una copia e lavoro su quella , quindi incremento la copia di 2 ma poi butto via quanto ho fatto.

Nel modo precedente invece (ossia col reference) io passo a, e la funzione lavora esattamente su quell' a senza fare una copia... nella pratica la funzione prende l'indirizzo di memoria di a (che ha grazie al fatto che passo a by reference) e lavora su quello, quindi a risulterà effettivamente modificato.

In C, you could only do:
```
void add_two_ref(int* a){
    *a=*a+2;
}
```

which was called "passing by reference", but actually it was "passing by pointer". If you pass by pointer, then you need to put the `&` in front of the variable when calling the function:

```
int z{8};
add_two(&z);
```
This is discouraged in C++ for "single variables" and can cause ambiguity and hard-to-catch bugs when you forget if it's an array or not, so avoid this unless you are using C-libraries. Arrays are already pointers and will always be passed "by pointer".

```
void print_array(int* arr, const int N){
    //accessing "normally"
    for(int i=0;i<N;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    //accessing with "pointer arythmetics"
    for(int i=0;i<N;i++){
        std::cout<<*(arr+i)<<" ";
    }
    std::cout<<std::endl;
}


int main(){
   const int N{5};
   int arr[N];//array is a pointer!!
   print_array(arr,N); 
   for(int i=0;i<N;i++){
     arr[i]=i*i;
   }   
   print_array(arr,N); 
}

```

#### Pointers and references:

Pointers and references are a very important concept in C++ and exist on their own, without the context of functions (although they are the most important in passing parameters). 

A pointer is a variable that stores the memory address of whatever it points to. It needs to have a type to know how to read that memory.

```
int a{0};
int* pointer{nullptr}; //doesn't have to be initialized, but it's better to put `nullptr` when you create it.
pointer=&a; //here & means *address of the variable*
```

To get access to a, we need to **dereference** a pointer by placing a `*` before the name. We have seen this syntax in the function example already.

```
std::cout<< *pointer << std::endl;
```
Con *pointer mi stampa il contenuto di a.
Con solo pointer (senza * iniziale), stampa invece l'indirizzo di memoria dove a è stipato.
A reference is defined with the `&` and *should be initialized at declaration*. **This is not the same `&` as we had when taking the address,** so things might look confusing at first. Do "play around" with example files to understand what's going on.

```
int a{0};
int& b{a};
```
Now `b` becomes an alias for a. You do with `b` whatever you wanted to do with `a`. If you run the following, you will see that the addresses and values of the variable and a reference to it are equal.

```
    int a{77};
    int& c{a};//c becomes an alias for a
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    std::cout<<"address of a is: "<<&a<<std::endl;
    std::cout<<"address of c is: "<<&c<<std::endl;
```

#### Function overloading

You can have different functions with the same name if they have a different number of type of the input parameters.

```
void add_two(int&a){
    a=a+2;
}

void add_two(int&a, int&b){
    a=a+2;
    b=b+2;
}

void add_two(double& a){
    a=a+2;
}

```

#### Recursive functions:

Functions can call themselves, in that case they are called *recursive functions*. 

```
unsigned long long int factorial(int N){
    if(N==1){
        return 1;
    }else{
        return N*factorial(N-1);
    }
}
```

Recursive functions are slower than iterations, but are sometimes much easier to write, so you need to know how to work with them.


#### Class member functions

Classes can have *member functions* that act on member variables. They have access to all member variables, including private ones, you do not need to pass anything.

One of the special member functions that doesn't have a return type at all is *constructor*. Constructors exist to initialize class member variables. Default constructor takes no parameters (if you don't want it to exist, you can use `CCoords() = delete;`).

```
class CCoords{
    double x;
    double y;
public:
    //default constructor
    CCoords(){
      x=0;y=0;  
    }
    //constructor with a parameter
    //a different syntax with the initializer list
    //it's "just a syntax" here, but can be important when member variable is also of some class type
    //pay attention to the initialization order!
    CCoords(double x1, double y1):x(x1),y(y1){
    }
    //only need the declaration here
    void print();
    //try to implement them yourself!
    auto getx();//this is c++14 standard
    auto gety();
    void setx(double a);
    void sety(double a);
};
```

If defining all the functions inside a class makes it too long (anything longer then "one screen" is too long), you can take the definition outside the class with the following syntax.

```
void CCoords::print() {
    std::cout<<x<<" "<<y<<std::endl;
}
```


### Test yourself:
 - What is a reference?
 - What is a difference between passing variables to functions by reference and by value?
 - Why do we want to pass variables to functions by reference rather than by pointer?
 - If the function accepts pointers (signature `int function(int* a)`), how do you pass a variable defined as `int x` to it?
 - Why do we want to use `const` modifier whenever possible?
 - If you have a pointer named `p`, how do you access a value it points to? What is the name of that process?
 - What value is stored in the pointer variable itself?
 - What can you say about a function that has signature `void function()`?
 - What is an `auto` keyword?
 - What is function overloading?
 - What is a recursive function?
 - What is the role of a constructor in a class?
 - How can we change private member variables of a class?
 
## Risposte

- A reference variable is an alias, that is, another name for an already existing variable.
- Pass a variable by value would works only if we return another variable (in this case, the output variable is a new variable, and the input variable remains itself). Passing by reference works if we want to modify the parameter inside the function: in this case, i pass to the function an alias of my variable, that is: the funcion will no longer create a new variable, but will "work directly" on the memoty allocation of the input value I pass to the function.
```
#include <iostream>

int add_two(int a){
    return a+2;
}

int main(){
    int a;
    a = 1;
    std::cout<<"inizio"<<a<<std::endl;
    int *p = &a;
    std::cout<<p<<std::endl;
    add_two(a);
    std::cout<<"dopo"<<a<<std::endl;
    std::cout<<p<<std::endl;
    return 0;
}

//output
//inizio1
//0x16fd73428
//dopo1
//0x16fd73428
```
```
#include <iostream>

void add_two(int &a){
    a = a+2;
}

int main(){
    int a;
    a = 1;
    std::cout<<"inizio"<<a<<std::endl;
    int *p = &a;
    std::cout<<p<<std::endl;
    add_two(a);
    std::cout<<"dopo"<<a<<std::endl;
    std::cout<<p<<std::endl;
    return 0;
}

//output:
//inizio1
//0x16b30f428
//dopo3
//0x16b30f428
```

- Because passing variables by pointers could lead to problem if we forget if we are handling variables or arrays.
- I have to pass the function the address of `int x`, that is `&x`.
More complex solution:
Create a pointer on x and pass it, that is:
```
int function(int* a){...}
int x;
int *p;
p = &x;
function(p)
```
The latter solution is exactly the same of passing  `&x`. Actually:
```
int x;
int *p;
p = &x; //create a pointer to x. Inside p we have the adress of x.

&x //is DIRECTLY the adress of p.
```

- Because it makes us sure that our code will not change. A non-const variable can be passed to a function that accepts const parameters. But poi if we modify our non-const variable, we'll have trouble.

- If I have a pointer `p`, I access the value of the variables it points to by doing dereference operation `*p`.

- In the pointer variable itself is stored the memory address of the variable which the pointer points to.

- `void function()`: this function does not return any value after execution.

- `auto`: when we are not sure about the type that a function returns, we can use auto. Even if we don t want to specify what type our function return, we use it. (We can use it also to declare a variable with a complicated type:  you can use auto to declare a variable where the initialization expression involves templates, pointers to functions, or pointers to members).

- We can have more than one function with the same name, but with different type/number of type in the input parameters. The compiler will not complain. (You can have different functions with the same name if they have a different number of type of the input parameters). NB OVERLOADING APPLY ONLY ON ARGUMENT TYPE AND NUMBER OF ARGUMENT (se ho due funz con stesso nome ma diversi tipi negli argument o deverso numero di parametri, funziona. Se invece ho stesso numero din parametri e dello stesso tipo e cambia SOLO il return type, beh questo non posso farlo.)

- It is a function which calls itself.

- Its role is to initialize some valid values for the class members variables (of an object). It ha the same name of the class, say "C". If we don t want it, put C()= delete;

- How can we change private member variables of a class? We can modify the setting at the beginning by setting the class to be "public".

#### All the code snippets below have mistakes, find them:
(if you cannot see the error, type this in an IDE or try to compile)

Snippet 1:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
void add_two(int* a){
    a=a+2;
}
int main(){
    int var{0};
    add_two(&var);
    std::cout<<var<<std::endl;
    return 0;
}
```
Correct:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
void add_two(int *a){
    *a=*a+2;
}
int main(){
    int var{0};
    add_two(&var);
    std::cout<<var<<std::endl;
    return 0;
}
```

Snippet 2:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
void swap(int a, int b){
   int temp{a};
   a=b;
   b=a; 
}
int main(){
   int var1{8}, var2{9};
   swap(var1,var2);
   std::cout<<var1<<" "<<var2<<std::endl;
   return 0;
}
```
Correct:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
void swap(int &a, int &b){
   int temp;
   temp = a;
   a=b;
   b=temp; 
}
int main(){
   int var1{8}, var2{9};
   swap(var1,var2);
   std::cout<<var1<<" "<<var2<<std::endl;
   return 0;
}
```

Snippet 3:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class CMyClass{
    int a;
    CMyClass(int x):a(x){};
}

int main(){
   CMyClass c(7);
   std::cout<<"this won't work"<<std::endl;
   return 0;
}
```
Correct:
```
class CMyClass{
public:
    int a;
    CMyClass(int x):a(x){};
    
    void display(){
        std::cout<<a;
    }
};

int main(){
   CMyClass c(7);
   std::cout<<"this works"<<std::endl;
   c.display();
   return 0;
}
```
Snippet 4:
```
int main(){
int x=4;
int& y;

......
}
```
!!!!References has to be delcared and initialized at the same time!!!! I CANNOT ONLY DECLARE A REFERENCE.

### Exercises:

#### Exercise 0:
Read the lecture notes and run all the examples mentioned in them. If you have little experience, it's better if you re-type rather than copy. Seeing that pointers/references are important, today it's a pretty useful exercise, don't skip it.


#### Exercise 1:
(prerequisite: exercise 1 of Lecture 1)
Add a contructor to your class of coefficients to initialize them all to zero. Add a class member function that prints the coefficients. Add a class member function that asks the user to input the coefficients. Write a function that takes a variable of your coefficient class as input and solves the equation (this function should also print solutions). You `main` function should be similar to

```
CCoeffs coeffs;
coeffs.ask_for_input();
coeffs.print();
solve_quadratic_equation(coeffs);

```


#### Exercise 2:
(prerequisite: exercise 1 of Lecture 2)
Create a class called "CQuadratic_Equation". It should have a class member variable of a type CCoeffs and two member variables of the other class "complex" (that you need to also create; if you already feel comfortable with c++, you can use the std::complex instead) to store solutions. Add a class member function that solves the equation. Add a separate member function that prints solutions. Your main should be similar to

```
CQuadratic_Equation eq;
eq.coeffs.ask_for_input();
eq.coeffs.print();
eq.solve();
eq.print_solution();

```

#### Exercise 3:

Write a recursive function to print an array.







