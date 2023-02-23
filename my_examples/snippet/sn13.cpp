
#include <fstream>

int calculate_result(int& k){
   return k*k;
};


int main(){
int result;
int N=10;
for(int i=0;i<N;i++){
   

   result = calculate_result(i); // valid function defined somewhere else
   std::ofstream filevar("results.txt", std::ios_base::app );
   filevar<<result<<std::endl;
   filevar.close();
}
return 0;
}
