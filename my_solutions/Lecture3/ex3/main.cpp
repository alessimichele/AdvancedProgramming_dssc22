#include "include/eq.hpp"
#include <fstream>


int main(){
    Equation eq;
    //eq.coeff.ask_for_input();
    eq.coeff.coeff_from_file("coefficients.txt");
    eq.coeff.print();
    
    eq.solve();
    eq.print_solution();
    eq.solution_to_file("solutions.txt");

    return 0;
}