#ifndef MESH
#define MESH

#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class Mesh{
public:
    std::vector<T> grid;
    std::vector<T> new_grid;
    int N_star;

    

    // constructor
    Mesh(const int& N);

    // print
    void print();

};
/*
template<typename T>
// default constructor
    Mesh<T>::Mesh(){
        grid.resize(0);
        new_grid.resize(0);
        N_star = 0;
    }
*/

template <typename T>
// constructor
    Mesh<T>::Mesh(const int& N){
        N_star = N+2;
        grid.resize(N_star * N_star);
        new_grid.resize(N_star * N_star);
        double K = 100.0/(N_star - 1);

        // set inner grid to 0.5
        for (int i = 0; i < N_star*N_star - 1  ; i++)
        {
            grid[i] = 0.5;
            new_grid[i] = 0.5;
        }

        // set boundaries
        for (int i = 0; i < N_star; i++)
        {
            grid[N_star*(N_star -1) + i] = 100 - K*i;
            grid[N_star*(N_star -1) - i*N_star] = 100 - K*i;
            grid[i] = 0;
            grid[N_star - 1 + i*(N_star)] = 0;

            new_grid[N_star*(N_star -1) + i] = 100 - K*i;
            new_grid[N_star*(N_star -1) - i*N_star] = 100 - K*i;
            new_grid[i] = 0;
            new_grid[N_star - 1 + i*(N_star)] = 0;
        }
    }


// print
template <typename T>
    void Mesh<T>::print(){
        std::cout<<"grid: "<<std::endl;
        //int N_star = std::sqrt(grid.size());
        for (int i = 1; i < N_star - 1; i++)
        {
            for (int j = 1; j < N_star - 1; j++)
            {
                std::cout<<grid[N_star*i + j]<<" ";
                if ((N_star*i + j )%(N_star-2) == 0)
                {
                    std::cout<<std::endl;
                }
            }   
        }

        // since the swap, the newest result is always stored into "grid", so just print that
        /*
        std::cout<<"new grid: "<<std::endl;
        //int N_star = std::sqrt(grid.size());
        for (int i = 1; i < N_star - 1; i++)
        {
            for (int j = 1; j < N_star - 1; j++)
            {
                std::cout<<new_grid[N_star*i + j]<<" ";
                if ((N_star*i + j )%(N_star-2) == 0)
                {
                    std::cout<<std::endl;
                }
            }   
        }
        */
    }

#endif