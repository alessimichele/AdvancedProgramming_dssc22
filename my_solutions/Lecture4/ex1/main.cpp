#include "coeff.hpp"
#include "eq.hpp"

int main(){
    coeff<double> C;
    C.ask_for_input();
    C.print();
    solve_quadratic_eq(C.a, C.b, C.c);
}