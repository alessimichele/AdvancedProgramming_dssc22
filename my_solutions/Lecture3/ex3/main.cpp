#include "include/eq.hpp"



int main(){
    Equation eq;
    eq.coeff.ask_for_input();
    eq.coeff.print();
    
    eq.solve();
    eq.print_solution();

    return 0;
}