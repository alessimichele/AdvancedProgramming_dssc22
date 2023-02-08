#include <sstream>
#include <iostream>
#include <getopt.h>

//play around with this file and see what passing different "wrong" things does

int main(int argc, char * const argv[]) { 
   
    //c-style way to parse parameters
    //they should be passed like "-a 1 -b 9"
    int a{0}, b{0}, c{0}, d{0};
    int res{0};
    while( (res = getopt(argc, argv, "a:b:c:d:") ) != -1 ) {
        switch(res){
            case 'a':
                a = std::atoi(optarg);
                break;
            case 'b':
                b = std::atoi(optarg) ;
                break;
            case 'c':
                c = std::atoi(optarg) ;
                break;
            case 'd':
                d = std::atoi(optarg) ;
                break;
        }//switch
    }//while
    
 
  std::cout<< "a: " <<a<<" b: "<<b<<" c: " <<c<<" d: " <<d<<std::endl;
    
    return 0;   
}   

/*
The code is a while loop that repeatedly calls the getopt function to parse the command-line arguments in argv. The loop continues as long as getopt returns a value other than -1.

The getopt function is a C library function that is used to parse the command-line options and arguments. It takes three arguments:

argc: the number of command-line arguments
argv: an array of C-style strings that contain the arguments
"a:b:c:d:": a string that specifies the valid option characters and their corresponding arguments. A colon : after an option character indicates that the option requires an argument.
The return value of the getopt function is the next option character that was found. The switch statement inside the while loop processes the returned value. If the returned value is 'a', the a variable is set to the value of optarg, which is the argument associated with the option character. The same logic applies to the 'b', 'c', and 'd' options. If the returned value is not 'a', 'b', 'c', or 'd', the switch statement does nothing. The break statement inside each case statement is used to exit the switch statement after processing the corresponding option character.

In summary, the while loop and the switch statement are used to repeatedly call the getopt function to parse the command-line arguments and set the values of a, b, c, and d accordingly.*/