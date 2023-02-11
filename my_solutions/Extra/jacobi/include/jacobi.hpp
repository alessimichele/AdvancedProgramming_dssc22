#ifndef JACOBI
#define JACOBI

#include "mesh.hpp"

template <typename T>
class Solver{
public:
    void solve(Mesh<T>& g);
};

template <typename T>
    void Solver<T>::solve(Mesh<T>& g){
        for (int i = 1; i < g.N_star - 1; i++)
        {
            for (int j = 1; j < g.N_star - 1; j++)
            {
                g.new_grid[g.N_star*i + j] = 0.25*(g.grid[g.N_star*(i-1) + j] + g.grid[g.N_star*i + j + 1] + g.grid[g.N_star*i + j - 1] + g.grid[g.N_star*(i+1) + j]);
            }   
        }
        g.new_grid.swap(g.grid); 
    }



#endif