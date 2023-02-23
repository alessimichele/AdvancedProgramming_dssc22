#include <iostream>

class CMyClass{
    int a;
public:
    CMyClass(int x):a(x){};
};



int main(){
   CMyClass c(7);
   std::cout<<"this won't work"<<std::endl;
   return 0;
}