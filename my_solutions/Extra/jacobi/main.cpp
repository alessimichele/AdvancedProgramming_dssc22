#include "mesh.hpp"

int main(){
    int N=9;
    Mesh<int> my_grid(N);
    int len = my_grid.size();
    for (int i = 0; i < len; i++)
    {
        std::cout<<my_grid.grid[i]<<" ";
    }
    return 0;
    
}