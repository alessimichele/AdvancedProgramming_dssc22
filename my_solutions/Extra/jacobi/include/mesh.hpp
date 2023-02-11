#ifndef MESH
#define MESH

#include <iostream>
#include <vector>

template <typename T>
class Mesh{
public:
    std::vector<T> grid;

    // default constructor
    Mesh();

    // constructor
    Mesh(const int& N);

    // size
    int size();

};

template<typename T>
// default constructor
    Mesh<T>::Mesh(){
        grid.resize(0);
    }

template <typename T>
// constructor
    Mesh<T>::Mesh(const int& N){
        int N_star = N+2;
        grid.resize(N_star * N_star);
        double K = 100.0/(N_star - 1);
        std::vector<T> bdry;
        bdry.resize(N_star);
        
        for (int i = 0; i < N_star; i++)
        {
            bdry[i] = 100 - K*i;
        }

        for (int i = 0; i < N_star; i++)
        {
            grid[N_star*(N_star -1) + i] = bdry[i];
        }
        for (int i = 0; i < N_star; i++)
        {
            grid[N_star*(N_star -1) - i*N_star] = bdry[i];
        }
        
        

    }

template <typename T>
// size
    int Mesh<T>::size(){
        return grid.size();
    }


#endif