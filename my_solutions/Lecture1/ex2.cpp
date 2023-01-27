#include <iostream>
#include <string>

int main(){
    std::cout<<"Enter the integer you want to convert into binary:"<<std::endl;
    int n;
    std::cin>>n;
    std::cout<<std::bitset<17>(n).to_string()<<std::endl;
    int arr[64];
    int i{0};
    while (n!=0){
        arr[i]= n%2;
        i=i+1;
        n = n/2;
    }
    i--;
    while (i>=0){
        std::cout<<arr[i];
        i--;
    }
    std::cout<<std::endl;
    
    return 0;
}