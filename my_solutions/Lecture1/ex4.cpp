#include <iostream>
#include <string>

int main(){
    int N;
    std::cout<<"Inserire la grandezza dell'array:"<<std::endl;
    std::cin>> N;

    const int k{N};
    int arr[k];
    std::cout<<"Inserire gli elementi:"<<std::endl;
    for (int i=0; i<k; i++){
    int j;
    std::cin>>j;
    arr[i]=j;
    }
    
    std::cout<<"Questo è l'array"<<std::endl;
    for (int i=0; i<k; i++){
    std::cout<< arr[i]<<" ";
    }

    std::cout<<std::endl;

    std::cout<<"Questo è l'array ordinato con insertion sort:"<<std::endl;
    for (int i=0; i<k; i++){
        for (int j=i+1; j<k; j++){
            if (arr[i]>arr[j]){
                int tmp;
                tmp = arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    for (int i=0; i<k; i++){
    std::cout<< arr[i]<< " ";
    }
    return 0;

}