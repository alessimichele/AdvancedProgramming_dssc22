#ifndef VARIADIC
#define VARIADIC


#include <iostream>
#include <fstream>
#include <string>

template <typename... T>
void copyFile(T... args)
{
    // Open input file
    std::ifstream input(args...);
    if (!input.is_open())
    {
        std::cerr << "Error: Failed to open input file." << std::endl;
        return;
    }

    // Open output file
    std::ofstream output("./file/output_variadic.txt");
    if (!output.is_open())
    {
        std::cerr << "Error: Failed to open output file." << std::endl;
        return;
    }

    // Copy contents of input file to output file
    std::string line;
    while (std::getline(input, line))
    {
        output << line << std::endl;
    }

    // Close files
    input.close();
    output.close();
}

/*
#include <iostream>
#include <string>
#include <fstream>

// define a funciton that read from file and copy to another file
// but is variadic template; so ...

template <typename T>
void variadic(std::string i_filename_path, std::string o_filename_path){
    T val;
// read from the file 'i_filename'
    std::ifstream i_filevar(i_filename_path);
    // store the value inside 'i_filename_path' into 'val' variable
    i_filevar>>val;
    i_filevar.close();

// writing on file 'o_filename_path'
    // default setting of std::ofstream is overwriting
    std::ofstream o_filevar(o_filename_path, std::ios_base::app);
    // o_filevar.open("o_filename_path", std::ios_base::app); // alternative for append mode
    o_filevar<<val;
    o_filevar << std::endl;
    o_filevar.close();
}
*/

#endif