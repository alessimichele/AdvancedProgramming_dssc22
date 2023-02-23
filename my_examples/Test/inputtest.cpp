#include <iostream>
#include <string>
#include <vector>

int main(){
    std::cout<<"hi, enter your name and surname"<<std::endl;
    std::string name;
    std::string surname;
    std::cin>> name>> surname;
    std::cout<<"hi "<<name<<" "<<surname<<std::endl;

    std::cout<<"enter integer: they'll be store inside a vector. When want to stop enetering, enter anything isn't an integer"<<std::endl;
    std::cout << "\nEnter Your Input::"<<std::endl;
    int input;
    std::vector<int> v;
    v.reserve(100);
    while (std::cin >> input)
    {
        v.push_back(input);
    }

    
    std::cout << "you entered: ";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout<<v[i]<<" ";
    }
    
    return 0;
}