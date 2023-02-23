#include <iostream>


class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
};

class Circle: public Shape{
  double r;
public:
  void print() override {std::cout<<r<<std::endl;};
};

int main(){
  
  Circle c; 
  c.print();

  // with poly
  Shape* pshape;
  pshape = &c;
  pshape->print();
}
