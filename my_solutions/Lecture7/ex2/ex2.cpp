#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// da sistemare

std::vector<int> my_getops(int argc, char* argv[], std::string par){
    
    // get the name of the parameters I need
        std::istringstream ss(par);
        std::string token;

        // in v store the "name" of the parameters to be checked
        std::vector<std::string> v;
        int i=0;
        while(std::getline(ss, token, ':')) {
            v.resize(i+1);
            v[i] = token;
            // std::cout<<v[i]<<std::endl;
            i = i+1;
        }

        std::cout<<"start v"<<std::endl;
        for (int i = 0; i < v.size(); i++)
        {
            std::cout<<v[i]<<std::endl;
        }
        std::cout<<"end v"<<std::endl;

        for (int i = 0; i < argc; i++)
        {
            std::cout<<"argv: "<<argv[i]<<std::endl;
        }
        

    // get the value 
        // vector to store my final values
        std::vector<int> values;
        values.resize(v.size());

        int j=0;
        for (int i = 1; i < argc; i++){
            std::string arg = argv[i];

            std::cout<<"j = "<<j<<std::endl;
            
            if (arg[0] == '-'){
                std::size_t start = 1;
                std::string substring = arg.substr(start);
                if (substring == v[j]){
                    values[j] = (std::atoi(argv[i+1]));
                    std::cout<<"insert in values: "<<values[j]<<std::endl;
                    j = j+1;
                }
            }
        }
    
    // return an array with the passed values
    return values;
    
};


int main(int argc, char* argv[]){
    std::vector<int> values = my_getops( argc,  argv, "a:b:c:");

    std::cout<<"end my_getops"<<std::endl;

    for (int i = 0; i < values.size(); i++)
    {
        std::cout<<values[i]<<std::endl;
    }
    
    
    
}