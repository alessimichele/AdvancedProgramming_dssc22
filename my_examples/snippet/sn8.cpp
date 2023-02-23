#include <iostream>

void swap(int& a, int& b){
   int temp = a;
   a=b;
   b=temp; 
}
int main(){
   int var1{8}, var2{9};
   swap(var1,var2);
   std::cout<<var1<<" "<<var2<<std::endl;
   return 0;
}