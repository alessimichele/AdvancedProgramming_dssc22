#include <iostream>

struct mystruct{
private:
  int a;
  int b;
public:
  
  friend void mod_a(mystruct& m, const int& val){
      m.a = val;
  };

  void mod_b(const int val){
    b = val;
  };

  void print(){
    std::cout<<a<<", "<<b<<std::endl;
  };
};

int ex(int* v){
  *v = *v+2;
  return *v;
}

int main(){


int var = 5;

std::cout<<ex(&var)<<std::endl;
std::cout<<var<<std::endl;




mystruct S;
S.print();
mod_a(S, 8);
S.mod_b(7);
S.print();


return 0;
}