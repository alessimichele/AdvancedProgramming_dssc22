#include "mesh.hpp"
#include "jacobi.hpp"

int main(){
    int N=2;
    Mesh<double> my_grid(N);
    my_grid.print();
    Solver<double> solver;
    for (int i = 0; i < 100; i++)
    {
        solver.solve(my_grid);
        my_grid.print();
    }

    return 0;
}