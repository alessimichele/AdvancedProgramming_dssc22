// Create an abstract base class "shape" and inherit classes triangle 
// (should have 3 vectices member variables) and polygon from it (should have a raw pointer 
// to vertices coordinates within to make life harder). 
// The classes should have functions to calulate perimeter and to print vertice coordinates 
// that work with runtime polymorhism.

#include <iostream>
#include <cmath>
#include <vector>

// class for Coordinates
template <typename T>
class Coord{
public:
    T x;
    T y;

    // default constructor
    Coord();

    // constructor
    Coord(const T& x0, const T& y0);

    // print
    void print_coord();
};

// default constructor
template <typename T>
    Coord<T>::Coord(){
        x = 0;
        y = 0;
    }

// constructor
template <typename T>
    Coord<T>::Coord(const T& x0, const T& y0){
        x = x0;
        y = y0;
    }

// print
template <typename T>
    void Coord<T>::print_coord(){
        std::cout<<"("<<x<<", "<<y<< ")"<<std::endl;
    }

// function to compute distance between two Coord objects
template <typename T>
    double distance(const Coord<T>& P1, const Coord<T>& P2){
        double tmp = (P2.x - P1.x)*(P2.x - P1.x) + (P2.y - P1.y)*(P2.y - P1.y) ;
        return std::sqrt(tmp);
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class for shape
class Shape{
public:
    virtual double perimeter()=0;
    virtual void print_vertices()=0;
    virtual ~Shape(){};
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class for Triagle
template <typename T>
class Triangle: public Shape{
public:
    Coord<T> a;
    Coord<T> b;
    Coord<T> c;

    // default constructor
    Triangle();

    // constructor
    Triangle(Coord<T>& a0, Coord<T>& b0, Coord<T>& c0);

    // perimeter
    double perimeter() override;

    // print_vertices
    void print_vertices() override;
};

// default constructor
template <typename T>
    Triangle<T>::Triangle(){}

// constructor
template <typename T>
    Triangle<T>::Triangle(Coord<T>& a0, Coord<T>& b0, Coord<T>& c0){
        a = a0;
        b = b0;
        c = c0;
    }

// perimeter
template <typename T>
    double Triangle<T>::perimeter(){
        return distance(a,b) + distance(b,c) + distance(c,a);
    }

// print_vertices
template <typename T>
    void Triangle<T>::print_vertices(){
        std::cout<<"Vertices:"<<std::endl;
        a.print_coord();
        b.print_coord();
        c.print_coord();
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class for Polygon
template <typename T>
class Polygon: public Shape{
public:
    Coord<T>* vertices;
    int number_of_vertices;

    // default constructor
    Polygon();

    // constructor
    Polygon(const std::vector<Coord<T>>& actual_vertices);

    // destructor
    ~Polygon();

    // perimeter
    double perimeter() override;

    // print_vertices
    void print_vertices() override;

};

 // default constructor
 template <typename T>
    Polygon<T>::Polygon(){
        number_of_vertices = 0;
        vertices = nullptr;
    }

 // constructor
 template <typename T>
    Polygon<T>::Polygon(const std::vector<Coord<T>>& actual_vertices){
        number_of_vertices = actual_vertices.size();
        vertices = new Coord<T>[number_of_vertices];
        for (int i = 0; i < number_of_vertices; i++)
        {
            vertices[i] = actual_vertices[i];
        }
    }

// destructor
template <typename T>
    Polygon<T>::~Polygon(){
        delete[] vertices;
    }

// perimeter
template <typename T>
    double Polygon<T>::perimeter(){
        double res{0};
        for (int i = 0; i < number_of_vertices ; i++)
        {
            res += distance(vertices[i], vertices[i+1]);
        }
        res += distance(vertices[number_of_vertices], vertices[0]);
        return res;
    }

// print_vertices
template <typename T>
    void Polygon<T>::print_vertices(){
        std::cout<<"Vertices:"<<std::endl;
        for (int i = 0; i < number_of_vertices; i++)
        {
            vertices[i].print_coord();
        }
        
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    Coord<double> a(0,0);
    Coord<double> b(1,0);
    Coord<double> c(0,1);
    Coord<double> d(1,1);
    Triangle<double> T(a,b,c);
    Polygon<double> P({a,b,d,c});
    Shape * shape_T = &T;
    Shape * shape_P = &P;
    std::cout<<shape_T -> perimeter()<<std::endl;
    shape_T -> print_vertices();
    std::cout<<shape_P -> perimeter()<<std::endl;
    shape_P -> print_vertices();
    std::cout<<T.perimeter()<<std::endl;
    T.print_vertices();
    return 0;
}