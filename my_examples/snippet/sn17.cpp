#include <iostream>


class Shape{
 public:
  virtual void print(){};
  virtual ~Shape(){
    std::cout<<"Shape destructor"<<std::endl;
  };
};

class Polygon: public Shape{
public:
  double* v;

  void print() override {
    std::cout<<"hi"<<std::endl;
  };

  Polygon(const int&N){
    v = new double[N];
  };

  ~Polygon(){
    delete[] v;
    std::cout<<"Polygon destructor"<<std::endl;
    };
};

int main(){
  Shape* s = new Polygon(7);
  s->print();
  delete s;


  Shape* p;
  Polygon pol = Polygon(7);
  p = &pol;
  p->print();

}

