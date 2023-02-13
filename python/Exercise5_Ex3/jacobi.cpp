#include <iostream>
#include <vector>
#include <cmath>


template <typename T>
class Mesh{
public:
    std::vector<T> grid;
    
    int N_star;

    // constructor
    Mesh(const int& N);

    // print
    void print();

};


template <typename T>
// constructor
    Mesh<T>::Mesh(const int& N){
        N_star = N+2;
        grid.resize(N_star * N_star);
        
        double K = 100.0/(N_star - 1);

        // set inner grid to 0.5
        for (int i = 0; i < N_star*N_star - 1  ; i++)
        {
            grid[i] = 0.5;
            
        }

        // set boundaries
        for (int i = 0; i < N_star; i++)
        {
            grid[N_star*(N_star -1) + i] = 100 - K*i;
            grid[N_star*(N_star -1) - i*N_star] = 100 - K*i;
            grid[i] = 0;
            grid[N_star - 1 + i*(N_star)] = 0;

            
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

    
    }

template <typename T>
class Solver{
public:
    T* solve(Mesh<T>& g);
};

template <typename T>
    T* Solver<T>::solve(Mesh<T>& g){
        std::vector<T> new_grid;
        new_grid.resize(g.N_star * g.N_star);
        for (int i = 1; i < g.N_star - 1; i++)
        {
            for (int j = 1; j < g.N_star - 1; j++)
            {
                new_grid[g.N_star*i + j] = 0.25*(g.grid[g.N_star*(i-1) + j] + g.grid[g.N_star*i + j + 1] + g.grid[g.N_star*i + j - 1] + g.grid[g.N_star*(i+1) + j]);
            }   
        }
        // copy grid updated content into new_grid (this is 'swap like')
        for(int i = 1; i < (g.N_star-1); i++){
            for(int j = 1; j <(g.N_star-1); j++){
                g.grid[j + i*(g.N_star)] = new_grid[j + i*(g.N_star)];
            }
        }
        return &g.grid[0];
    }

extern "C"{
double* OLD_main(){
    int N=2;
    Mesh<double> my_grid(N);
    my_grid.print();
    Solver<double> solver;
    for (int i = 0; i < 100; i++)
    {
        solver.solve(my_grid);
        my_grid.print();
    }

    return &my_grid.grid[0];
}
}