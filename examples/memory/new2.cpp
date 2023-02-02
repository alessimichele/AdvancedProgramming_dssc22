#include <iostream>


// deep copy: it is a "true" copy in the sense that we don't have a new pointer poinitng to the same 
// memory region 
    // (in this case we would end up with one memory region, and 2 different pointers pointing to it),
// but we have a new memory region with same data stored in it and another pointer 
// pointing to that different memory region.
template <typename T>
class CMyClass{
public:
    T* data;
    size_t size;
    CMyClass(const int& N);
    ~CMyClass();
    void print();
    CMyClass& operator=(const CMyClass& p); // return the reference to a class
    // if don t overload =, the compiler copy the pointer so i end up with 2 pointers pointing to the
    // same region. So i call the destructor twice on the same memory address... this is not possible
    // after the first call on the first pointer, i free the memory on that memory address. At the 
    // second call, the second pointer is still pointing to that memory address and try to free it, but is already freed!
};

template<typename T> 
    CMyClass<T>::CMyClass(const int& N) {
    data=new T[N];
    size=N;
    for(int i=0;i<N;i++){
        data[i]=i;
    }
    std::cout<<"constructor called"<<std::endl;
}


template<typename T> 
    CMyClass<T>::~CMyClass() {
    delete[] data;
    data=nullptr;
    std::cout<<"destructor called"<<std::endl;
}


template<typename T> 
void CMyClass<T>::print() {
     for(int i=0;i<size;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;   
}

// settare la "corrente" istanza della classe uguale alla clase "p"... quello che sta a sx dell =
// viene post uguale a quello che sta a dx dell =.
template <typename T>
CMyClass<T>& CMyClass<T>::operator=(const CMyClass<T>& p){
    std::cout<<"assignment operator called"<<std::endl;
//first check for self-assignment
if (this != &p) {  // this is the pointer pointing to our instance of our class
//copy non-dynamic variables
	size=p.size;
//free memory of existing dynamic variables
	if (data != nullptr){
		delete[] data;
		data=nullptr;
    }	
//create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;}
	else{
		data = new T[size];
		for(int i=0;i<size;i++){
			data[i]=p.data[i];
        };
	}//else
	
}//of cheking for self-assignement
return *this;
};


int main(){
   
    CMyClass<int> obj(10);
    CMyClass<int> obj2(10);
    
    obj2=obj;   
    obj2.print();
    
    return 0;
}
 
