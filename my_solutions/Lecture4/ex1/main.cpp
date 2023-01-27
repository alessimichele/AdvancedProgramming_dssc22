#include "header.hpp"

int main(){
    coeff C;
    C.ask_for_input();
    C.print();
    solve_quadratic_eq(C.a, C.b, C.c);
}