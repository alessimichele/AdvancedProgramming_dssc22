#include <iostream>

class Dynamic{
public: 
    int N;
    int* v;

    Dynamic(const int& n){
        std::cout<<"constructor called"<<std::endl;
        N = n;
        v = new int[n];
        for (int i = 0; i < N; i++)
        {
            v[i] = i;
        }
        
    };

    Dynamic(const Dynamic& d){
        std::cout<<"copy constructor called"<<std::endl;
        if (this != &d)
        {
            N = d.N;
            if (d.v == nullptr)
            {   
                v = nullptr;
            }
            else{
                v = new int[N]; 
                for (int i = 0; i < N; i++)
                {
                    v[i] = d.v[i];
                }   
            }   
        }
    };

    Dynamic operator=(const Dynamic& d){
        std::cout<<"assignment operator called"<<std::endl;
        if (this != &d)
        {
            N = d.N;
            // if "mine" has stuff inside, free it
            if (v != nullptr)
            {
                delete[] v;
                v = nullptr;
            }
            if (d.v == nullptr)
            {
                v = nullptr;
            }else{
                v = new int[N]; 
                for (int i = 0; i < N; i++)
                {
                    v[i] = d.v[i];
                }   
            }   
        }
        return *this;
    };

    ~Dynamic(){
        std::cout<<"destructor called"<<std::endl;
        delete[] v;
        v = nullptr;
    };
    
};


void print(Dynamic d){
    for (int i = 0; i < d.N; i++)
    {
        std::cout<<d.v[i]<<" ";
    }
    
}

int main(){
    Dynamic a(8);
    Dynamic b(a);
    Dynamic c(6);
    b=c;
    print(a);
    print(b);
    print(c);
    return 0;
}