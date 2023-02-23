#include <iostream>
#include <cmath>

class Shape{
protected:
    // pure virtual function (i.e. it mustbe overridden by each child class)
    virtual double getArea()=0;
    virtual double getPerimeter()=0;
};

class RegularPolygon: protected Shape{
public:
    virtual double getApothem()=0;
};

class Triangle: protected RegularPolygon{
public:
    Triangle(const double& l):L(l){}

    double getApothem() override{
        return L/(2*std::tan(M_PI/3));
    }

    double getArea() override{
        return (std::sqrt(3)/4)*L*L;
    }

    double getPerimeter() override{
        return 3*L;
    }
private:
    double L;
};

class Rectangle: protected Shape{
public:
    Rectangle(const double& b,const double& h ): B(b), H(h){}

    double getArea() override{
        return B*H;
    }

    double getPerimeter() override{
        return 2*B + 2*H;
    }
private:
    double B;
    double H;
};


class Square: protected RegularPolygon{
public:
    Square(const double& l){
        L = l;
    }

    double getApothem() override{
        return L/(2*std::tan(M_PI/4));
    }

    double getArea() override{
        return L*L;
    }

    double getPerimeter() override{
        return 4*L;
    }
private:
    double L;
};

class Pentagon: protected RegularPolygon{
public:
    Pentagon(const double& l){
        L = l;
    }

    double getApothem() override{
        return L/(2*std::tan(M_PI/5));
    }

    double getArea() override{
        return (L/(2*std::tan(M_PI/5)))*5*(L/2);
    }

    double getPerimeter() override{
        return 5*L;
    }
private:
    double L;
};

class Circle: protected Shape{
public:
    Circle(const double& r): R(r){}

    double getArea() override{
        return M_PI*R*R;
    }

    double getPerimeter() override{
        return 2*M_PI*R;
    }
private:
    double R;
};





int main(){
    Triangle t(1);
    Square s(1);
    Rectangle r(2,3);
    Circle c(1);
    Pentagon p(1);
    std::cout<<t.getApothem()<<std::endl;
    std::cout<<t.getArea()<<std::endl;
    std::cout<<t.getPerimeter()<<std::endl;
    std::cout<<s.getArea()<<std::endl;
    std::cout<<s.getApothem()<<std::endl;
    std::cout<<s.getPerimeter()<<std::endl;
    std::cout<<p.getArea()<<std::endl;
    std::cout<<p.getApothem()<<std::endl;
    std::cout<<p.getPerimeter()<<std::endl;
    std::cout<<r.getArea()<<std::endl;
    std::cout<<r.getPerimeter()<<std::endl;
    std::cout<<c.getArea()<<std::endl;
    std::cout<<c.getPerimeter()<<std::endl;
}





