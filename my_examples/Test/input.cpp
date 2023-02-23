//#include <sstream>
#include <iostream>
#include <getopt.h>

int main(int argc, char * const argv[]) { 
    int size{0};
    int opt{0};
    while( (opt = getopt(argc, argv, "s:" )) != -1 ) {
        switch (opt) {
            // if pass -s to the command line, do the following
            case 's':
                size = std::atoi(optarg);
                break;
            // error handling
            default:
                std::cerr << "Usage: " << argv[0] << "[-s value]" << std::endl;
                return 1;
        }
    }
    // print inserted size
    std::cout<< "Inserted size: " <<size<<std::endl;
    return 0;   
}   