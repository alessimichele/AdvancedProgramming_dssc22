*The notes do not constitute a full reference book, please attend lectures, watch videos or read something else to fully understand the material. They are nothing more than "notes".*

### Inheritance

#### simple member access and inheritance modes:

We can derive a child class from the base class in different access modes: public, protected, private. For example:

`class Derived : public Base`


 - Public inheritance makes public members of the base class public in the derived class, and the protected members ("protected" means friends and derived classes can access) of the base class remain protected in the derived class.
 - protected inheritance makes the public and protected members of the base class protected in the derived class.
 - private inheritance makes the public and protected members of the base class private in the derived class.

Note: private members of the base class are inaccessible to the derived class.

```
class CBase {
  public:
    int x;
  protected:
    int y;
  private:
    int z;
};

class CPublicDerived: public CBase {
  // x is public
  // y is protected
  // z is not accessible from CPublicDerived
};

class CProtectedDerived: protected CBase {
  // x is protected
  // y is protected
  // z is not accessible from CProtectedDerived
};

class CPrivateDerived: private CBase {
  // x is private
  // y is private
  // z is not accessible from CPrivateDerived
};
```

It's possible to inherit from multiple classes at once.




#### Polymorphism:  virtual functions

One of the key features of class inheritance is that a pointer to a derived class is type-compatible with a pointer to its base class. This is called runtime or dynamic polymorhism and is one of the key features of the object oriented design. (It's mostly not recommended in high performace applications, as it's slow.)


NB: i template sono inizializzati at compiling time, quindi quando l programma compila, deve già sapere che "type" mettere ai vari template affinchè si possa runnare tutto allo step successivo. Se prima del running time (i.e, se al compiling time) non conosco i "type" che mi serviranno, devo mettere tutti i possibili... Casino!
Con i polymorhpism, io ho un puntatore alla classe base che può "puntare" alle classi figlie "di volta in volta quando serve", e questo avviene at RUNNING time, quindi non devo conoscere in anticipo i type che mi serviranno! Sarà il puntatore mentre il codice runna (dopo essere stato compilato) a puntare "nel posto giusto".

```
 #include <iostream>

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b){ 
        width=a; height=b; 
    }
};

class Rectangle: public Polygon {
  public:
    int area(){ 
        return width*height;
    }
};

class Triangle: public Polygon {
  public:
    int area(){ 
        return width*height/2;
    }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  std::cout << rect.area() << '\n';
  std::cout << trgl.area() << '\n';
  return 0;
}
```
Here you used `area()` function as an overloaded one, you knew what you called it on.

Instead of overloading the functions (happens at compile time), you can override them. This requires a `virtual` keyword.


A class that declares or inherits a virtual function is called a polymorphic class.

```
#include <iostream>

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area (){ 
        return 0; 
    }
 //  virtual int area ()=0;//makes the class abstract, then you can't have an object of it
    
};

class Rectangle: public Polygon {
  public:
      //override helps compiler and makes sure you don't type anything wrong
    int area() override{ 
        return width * height;
    }
};

class Triangle: public Polygon {
  public:
    int area() override{ 
        return (width * height / 2); 
    }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  // la sintassi è tipo:
  // double a = 1;
  // int* p = &a; it complains because a is double but double IS NOT child of int

  // here we say:
  // "type Polygon" * (pointer) ppoly (name of the pointer) = &rect (ppoly points to an object of a child class)
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
  std::cout << ppoly1->area() << std::endl;
  std::cout << ppoly2->area() << std::endl;
  std::cout << ppoly3->area() << std::endl;
  return 0;
}
```

If a class has a pure virtual function (declared with `=0`), then it's an "abstract class" and you cannot have an object of it. It's used for interface only purposes. Virtual functions must be overriden in derived classes, otherwise they become abstract too.


### Test yourself:

 - what are protected class members?
 -
 - what are virtual functions? 
 - *In C++, a virtual function is a member function that is declared within a base class and redefined (overridden) by derived classes.* It allows for dynamic dispatch, meaning that the function called at runtime will be based on the actual type of the object, rather than its static type. This allows for polymorphic behavior, where objects of different types can be treated as objects of the base type and the appropriate virtual function will be called based on the actual type of the object. The "virtual" keyword is used to declare a virtual function in the base class.
  
 
 - what is an abstract class?
 - an abstract class is a class that cannot be instansiated. It can be used only as based class for its derived class(es). If we declare some virtual functions inside the abstract class, these are only declared. Each derived class must then provide its implementation of those virtual functions.
 
 - explain dynamic (runtime) polymorphism
 - When an object of a derived class is referred to through a pointer or a reference of the base class type, and a virtual function is called on that object, the function that is actually executed at runtime is determined by the actual type of the object, rather than the type of the pointer or reference. This allows for polymorphic behavior, where *objects of different types can be treated as objects of a common base type, and the appropriate virtual function will be called based on the actual type of the object at runtime.*
 
 - why destructors should be made virtual?
 - if we deal with class hierarchy, destructor should be virtual in order to ensure that the correct derived class destructor is called when an object is destroyed.


#### All the code snippets below have mistakes, find them:

Snippet 1
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
}

class Circle: public Shape{
  double r;
  void print() override {std::cout<<r<<std::endl};
  }

int main(){
  Shape s;
  Circle c; 
}
```
Sol:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
}

class Circle: public Shape{
  double r;
  void print() override {std::cout<<r<<std::endl};
  }

int main(){
  // Shape s; can't  instantiate object s since Shape is an abstract class!
  Circle c; 
}
```

Snippet 2
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class Shape{
 public:
  virtual void print(){};
  ~Shape(){};
}

class Polygon: public Shape{
  double* v;
  void print() override {std::cout<<"hi"<<std::endl};
  Polygon(const int&N){v=new double[N];};
  ~Polygon(){delete[] v;};
  }

int main(){
  Shape* s = new Circle(7);
  s.print();
}
```
Sol:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class Shape{
 public:
  virtual void print(){};
  ~Shape(){};
}

class Polygon: public Shape{
  double* v;
  void print() override {std::cout<<"hi"<<std::endl};
  Polygon(const int&N){v=new double[N];};
  ~Polygon(){delete[] v;};
  }
  
class Circle: public Shape{
  double* v;
  void print() override {std::cout<<"hi"<<std::endl};
  Circle(const int&N){v=new double[N];};
  ~Circle(){delete[] v;};
  }

int main(){
  Circle c(7);
  Shape* s = &c;
  s->print();
}
```


### Exercises:

#### Exercise 0:

Go through all the example files, make sure you understand them. "Play around" with changing inheritance modes, commenting out default constructors, making functions pure virtual, etc.

#### Exercise 1:
Create an abstract base class "shape" and inherit classes triangle (should have 3 vectices member variables) and polygon from it(should have a raw pointer to vertices coordinates within to make life harder). The classes should have functions to calulate perimeter and to print vertice coordinates that work with runtime polymorhism.








