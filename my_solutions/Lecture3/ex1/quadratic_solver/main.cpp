#include "coeff_fun.hpp"
#include "solve_quad_eq.hpp"

int main(){
    coeff C;
    C.ask_for_input();
    C.print();
    solve_quadratic_eq(C.a, C.b, C.c);
}