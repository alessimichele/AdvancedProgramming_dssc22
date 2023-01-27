#include <iostream>
#include <cmath>

int main(){
    double extreme[2];
    extreme[0]=-10;
    extreme[1]=10;
    double mid;
    while (extreme[1]-extreme[0]>pow(10,-9)){
        mid = (extreme[1]+extreme[0])/2.0;
        if ((pow(mid,3)-6*pow(mid,2)+11*mid-6)==0){
            std::cout<<mid;
            break;
        } else{
            if ((pow(extreme[0],3)-6*pow(extreme[0],2)+11*extreme[0]-6) * 
                (pow(mid,3)-6*pow(mid,2)+11*mid-6)>0){
                extreme[0]=mid;
            }else{
                extreme[1]=mid;
            }
        }
        std::cout<<mid<<std::endl;
    }
    return 0;
}
