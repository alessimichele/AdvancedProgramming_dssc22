#ifndef FUNCTION
#define FUNCTION

#include <iostream>

// to write/read on/from files
#include <string>
#include <fstream>

// https://stackoverflow.com/questions/67631098/what-is-the-difference-between-ifstream-ofstream-and-fstream

// define a function that read a value from a file and print that value on another file, overwriting
template <typename T>
void over(std::string i_filename_path, std::string o_filename_path){
    T val;
// read from the file 'i_filename'
    std::ifstream i_filevar(i_filename_path);
    // store the value inside 'i_filename_path' into 'val' variable
    i_filevar>>val;
    i_filevar.close();

// writing on file 'o_filename_path'
    // default setting of std::ofstream is overwriting
    std::ofstream o_filevar(o_filename_path);
    o_filevar<<val;
    o_filevar.close();
}


// define a function that read a value from a file and print that value on another file, keeping track of the history on the writing file
template <typename T>
void not_over(std::string i_filename_path, std::string o_filename_path){
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


#endif