#include "eq.hpp"


int main(){
    eq equation;
    equation.coeff.ask_for_input();
    equation.coeff.print();
    
    equation.solve();
    equation.print_solution();

    return 0;
}