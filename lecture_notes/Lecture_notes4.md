 *The notes do not consitute a full reference book, please attend lectures, watch videos or read something else to fully understand the material. They are nothing more than "notes".*

### Templates

extra reference book:

"C++ Templates: The Complete Guide 1st Edition"
by David Vandevoorde 


#### Function templates
the template are iniziated (and instanced) at compile time


What if you want to write a function to print different types of data? You would need to overload your `print()` function for every type you are going to use it with. It becomes cumbersome very fast and makes code hard to maintain if new types are added. Luckily, in c++ there is an easy solution: templates.

```
template <typename T>
void print(const T& x){
    //all we need is the operator << be defined for the type T
    std::cout<<x<<std::endl;
}
```

Now, if you call your `print()` function with whatever type, compiler will have an overloaded function for that type ready for you. The type needed will be deduced from the argument. If you want to have a different type from what the compiler would normally assume, you can specify that:

```
double a{3.9};
print<int>(a);
```

You can also have different templated arguments if you need. 

Templates need to be "instantiated" by the compiler at compile time, thus if you separate the declarations and definitions into different files as is done in `C`, you have to instatiate it manually. In many cases, that almost defeats the purpose of using templates and, unless working with projects where you care for executable size, can be avoided by simply creating "a header only library", that is, putting all the function/class definitions entirely into header files.

Se faccio dei progetti, ho nel main l utilizzo dei template, in un header ho le dichiarazioni dei template e nel fie in src ho i prototipi dei template. Il problema è che quando faccio make della progetto, compilo prima src e dopo il main, e quando compilo src, il compolatore non sa QUALI TIPI DEVE USARE PER COMPPILARE; INFATTI IO I TIPI CHE DEVE UARE GLIELI PASSO SOLO NEL MAIN, CHE PERO VIENE COMPILATO DOPO... QUINDI LUI NON SA COSA FARE...
Questo lo risolvo mettendo una lista di tutti i possibili tipi che usero nel template (sia i tipi dei parametri che passo, sia i tipi di quello che deve ritornare la funzione... devo mettere tutte le combinazioni che mi possono servire....  QUESTO è IL GRANDE GRANDE CONTRO DEI TEMPLATE )

POSSIBILE SOLUZIONE... non fare makefile e fare tutto nello stesso file, quindi non c'è problema. Quindi avrò solo il main che punta a un header.hpp, e nell header ci metto tutto... dichiarazioni dei template insieme direttamente con le implementazioni!!!!!!
SO PUT ALL INSIDE THE HPP HEADER FILE!!! IT MAKES OUR LIFE EASIER.

FROM NOW ON, NO MORE FUNCTIONS BUT DO ONLY TEMPLATE (THAT ACTUALLY IS A FUNCTION, BUT TEMPLATED :)) IT IS MORE FLEXIBLE AND ALLOW US TO DONT USE SRC AND PUT ALL INSIDE THE HEADER.

#### Class templates

Your classes can have templated fields and extra templated functions inside:

```
template <typename T>
class CMyClass{
public:
    T field1;
    T field2;
    CMyClass(const T& a, const T& b);
    template <typename M>
    void print_extra(const M& val);
};
```

When we define the functions outside the class, we still need to specify the `template` keyword. Or both of them if the function had an extra template:

```
template<typename T> 
CMyClass<T>::CMyClass ( const T& a, const T& b ) {
    field1=a;
    field2=b;
}

template<typename T> 
template<typename M> 
    void CMyClass<T>::print_extra(const M& val) {
    std::cout<< field1<<" "<<field2 <<" "<<val<<std::endl;    
}

```

When you create a variable of the templated class, you need to tell the compiler which type to use, as, unlike with functions, it cannot deduce the information from any arguments.

```
CMyClass<int> var;
```

#### Non-type template parameters:
Da usare se abbiamo una funzione o una classe che dipendono da un numero, ma la dipendenza da queato numero avviene at the compiling time.
To use with compile-time-parameter.
(Usabili anche con la ricorsione... passando al prossimo stadio della ricorsione il template ma con N=N-1)???

In addition to templating functions/classes on types, we can also template them on "integer" numbers. By "integer" here is meant anything that is mathematically integer, not just `int`.

```
template <typename T, short int N>
void add_number(T& var){
    var=var+N;
}

int main(){
    double b{4.7};
    add_number<double,7>(b);
    std::cout<<b<<std::endl;
    return 0;
}
```

#### Template specialization:

You can make the compiler produce very different functions based on the type. This is useful when dealing with old C-interface or when some operations are not permitted for certain types.
Se non compila, aggiungere alla fine di g++ -o... -std=c++17
```
#include <typeinfo>

template <typename T>
void CMyClass<T>::Function(){
    if constexpr(std::is_same_v<int,T>){
        std::cout<<"we are dealing with int"<<std::endl;
    }
    if constexpr(std::is_same_v<double,T>){
        std::cout<<"we are dealing with double"<<std::endl;
    }
    if constexpr(std::is_integral_v<T>){
        std::cout<<"something \"integer\" "<<std::endl;
    }else{
        std::cout<<"something non \"integer\" "<<std::endl;
    }
}

```

#### Variadic templates:

You can template on a variable number of arguments, for example if you wanted to have a function that can be called as

```
myPrint(1,2,"Hi",9.0);
myPrint('c', 1.4, 9,0, "kjhkjhkjh");

```

First, you need to write a "normal" print function:

```
template <typename T>
void myPrint(const T& arg){
     std::cout<<arg<<" ";
}
```

Then, you use `...` (ellipsis) to tell the compiler that the number of variables can change:

```
template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
```
You need the "normal" print function here to stop the recursion.

In generale, quando ho piu parametri scrivo ricorsivamente (è meglio).

### STL containers: std::array and std::vector

### std::array

The header you need to include is:
```
#include <array>
```

To define a variable, do:

```
std::array<int,5> arr;//you need to pass the number of elements just like with the static array
```

*From now on, you can safely forget about "c-style" static arrays and always use std::array*. Why? It has the same performance, but causes no confusion with pointers, knows it's size and can be used with many C++ algorithms (that we'll see later).

### std::vector

Utili quando non mi frega del memory management... con gli array è tipo c invece, devo allocare la memoria e poi de allocarla.

vector fa da solo tutto quello che fanno mallock e free.
Solo nel caso in cui voglio fare io memory management NON uso i vector. (NB non è vero che i vector sono più lenti degli array di C se li si sanno usare bene)

NB gli array sono inizializzati (come mallock)
i vector non lo sono (come i callock)

NBNBNBNB non fare push_back... se il nuovo elemento me lo deve mettere nella allocazione di memoria successiva che però è occupata, lui deve copiare tutto e aggiungere da un altra parte... lentissimo. It will reallocate (realloc in C)

La cosa migliore è usare un vector come se fosse un array (quindi con grandezza fissata)... e so che semmai dovesse servire posso resaizare.
```
include <vector>
```

std::vector provides dynamic array functionality that handles its own memory management. This saves a lot of time, especially on debugging stage. You don't yet know all the horrors of memory management and with vectors you will only need to know them for cuda and the like.

However, it's easy to lose perfomance if you don't know what you are doing. Specifically, there is a handy function `push_back`, which should be used with caution or outright avoided when speed matters.

```
std::vector<int> V;
for (int i=0;i<100000;i++){
    V.push_back(i);
}
```

What happens behind the scnenes is that the vector will reserve the memory for itself with what it believs as "enough", then allocate new elemement in that area. Once it runs out of reserved memory, it will *copy eveything to a new location*, which you obvioulsy want to avoid when working with anything big.

So, when working with vectors in hpc, try to treat them like arrays and awaid resizing more than once. Always use `resize(NUMBER)` function, then fill in the values normally. As an alternative, you can call `reserve(NUMBER)` and then do `push_back`, but this way it's not always clear when the vector decides it's time to "move", it's safer to stick with "resize()".

When you work with C-style functions that require a pointer, you can pass vector's contents either as `&myvec[0]` or `myvec.data()`.

Both `std::vector` and `std::array` have a `.size()` function, so you don't need to manually pass their size to functions that work on them.

#### 2-dimentional arrays/vectors

When working with matrices, you generally want the data to be contiguous in memory, so never use something like  `std::vector<std::vector<int>>`. Use one-dimensional storage instead and access the `(i,j)` elements as `data[i*N+j]`.


### Test Yourself:
 
 - what's the main advantage of using templates?
 - isn't neccesary anymore to write different functions that do the same things for different type of data.
 
 - why do people usually put definitions of templated functions directly into `.hpp` files?
 - because if we also use a src folder with their definition, since templated are instantiated at compilation time, we would instantiate also all possible type of data when declaring template.
 
 - except on types, what else can we template on?
 - we can template on integer, that is all that is "mathematically" an integer, not just "int".
 
 - what is template specialization?
 - when we specify the type of data we are going to use (tell the compiler which type I use). It  make the compiler produce very different functions based on the type
 
 - what is a variadic template?
 - it is a type of template in which the number and the type of parameters of a function are templated, that is: variable number of templated parameters
 
 - why using `push_back` for `std::vector` is a bad idea?
 - because if we havent enough space, the compiler will copy all the content of the vetor to store the value passed with push_back
 
 - how do you pass data from `std::vector` to a "C-style" function that needs a pointer?
 - using &name_of_vector or name_of_vector.data()
 
 - why you shouldn't use a "vector of vectors"?
 - because we want data to be contigous in memory


#### All the code snippets below have mistakes, find them:


Snippet 1:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T>
class CMyClass{
  T a;
  T b;
}

int main(){
  CMyClass var;
 ...
}
```
Sol:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T>
class CMyClass{
  T a;
  T b;
}

int main(){
  CMyClass<T> var;
 ...
}
```

Snippet 2:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T, double S>
void add_number(T& var){
    T=T+S;
}
```
Sol:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T, int S> // qualcosa che sia "int" matematicamente
void add_number(T& var){
    T=T+S;
}
```


Snippet 3:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename... Types>
void myPrint(const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
```
Sol:
```
template <typename T>
void myPrint(const T& arg){
  std::cout<<arg<<" ";
}

template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
```

Snippet 4:

```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T>
void print(const T& var){
  std::cout<<var<<std::end;
}

struct MyClass{
  int a;
  int b;
}

int main(){
 MyClass var;
 print(var);
}

```
Sol:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T>
void print(const T& var){
  std::cout<<var<<std::end;
}

struct MyClass{
  int a;
  int b;
}

int main(){
 MyClass var;
 print<int>(var);
}

```



### Exercises:

#### Exercise 1:

Rewrite your "solve quadratic equation" exercise templating everything on the type of the coefficients. Your templated class should live in .hpp file.


#### Exercise 2:

Rewrite your "complex class" exercise templating everything. Your templated class should live in .hpp file.
Specialize the templates for integer and doubles to print some extra message when the arithmetic operations are called.


#### Exercise 3:

Write a function that can sum an arbitrary number of arguments using variadic templates.


#### Exercise 4:

Write a square matrix class that:

 - uses std::vector to store the data
 - is templated on the type of the data
 - can read/write a matrix to/from file
 - has operator `*` overloaded

You main function should look similar to 

```
int main(){
  CMatrix<double> A,B;
  A.read_from_file("A.txt");
  B.read_from_file("B.txt");
  auto C=A*B;
  C.print_to_file("C.txt");
}

```









