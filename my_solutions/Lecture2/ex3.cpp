#include <iostream>

void recursive_printing(int* arr, const int N ){
    if (N==1){
        std::cout<<*arr<<std::endl;
    } else{
        std::cout<<arr[0];
        recursive_printing(&arr[1], N-1);
    }
}

int main(){
    const int N{7};
    int arr[7]{1,2,3,4,5,6,7};
    
    recursive_printing(arr,N);
    return 0;
}
