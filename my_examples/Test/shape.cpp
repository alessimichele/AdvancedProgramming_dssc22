#include <iostream>

class Shape{
public:
    virtual void print()=0;
    virtual ~Shape(){};
};

class Circle: public Shape{
public:
  double r;
  void print() override {std::cout<<r<<std::endl;};
  Circle(const double& R){r=R;};
};

int main(){
  Shape* s;
  s = new Circle(7);
  s->print();
  return 0;
}