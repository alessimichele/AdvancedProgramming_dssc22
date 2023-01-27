#include "coeff.hpp"
#include "Complex.hpp"
#include "CQuadraticEq.hpp"

int main(){
    CQuadraticEq eq;
    eq.coefficients.ask_for_input();
    eq.coefficients.print();
    eq.solve();
    eq.print_solution();
    return 0;
}