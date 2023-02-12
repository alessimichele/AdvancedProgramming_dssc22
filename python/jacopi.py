from matplotlib import pyplot as plt
import numpy as np 
import matplotlib.animation as animation
import math


## initialize the grid
def build_grid(N):
    N_star = N+2
    grid = np.empty(N_star*N_star)
    new_grid = np.empty(N_star*N_star)
    K = 100.0/(N_star - 1)

    ##set inner grid to 0.5
    for i in range(N_star*N_star):
        grid[i] = 0.5
        new_grid[i] = 0.5

    ## set boundaries
    for i in range(N_star):
        grid[N_star*(N_star -1) + i] = 100 - K*i
        grid[N_star*(N_star -1) - i*N_star] = 100 - K*i
        grid[i] = 0
        grid[N_star - 1 + i*(N_star)] = 0

        new_grid[N_star*(N_star -1) + i] = 100 - K*i
        new_grid[N_star*(N_star -1) - i*N_star] = 100 - K*i
        new_grid[i] = 0
        new_grid[N_star - 1 + i*(N_star)] = 0
    return grid


## build next-step grid from the input
def solver(grid):
    N_star = int(math.sqrt(len(grid)))
    new_grid = np.empty(N_star*N_star)
    for i in range(1, N_star -1):
        for j in range(1, N_star -1):
                new_grid[N_star*i + j] = 0.25*(grid[N_star*(i-1) + j] + grid[N_star*i + j + 1] + grid[N_star*i + j - 1] + grid[N_star*(i+1) + j])
    return new_grid
    


    



fig = plt.figure()
images = []
N = 5
N_star = N+2
image = np.reshape(build_grid(N), (N_star,N_star))
final = np.array([image[i, :] for i in range(N_star)])

def animate(i):
    global image
    image = np.reshape(solver(np.reshape(image,(N_star*N_star,))),(N_star, N_star))
    final = np.array([image[i, :] for i in range(N_star)])
    im = plt.imshow(final, animated=True)
    images.append([im])

anim = animation.FuncAnimation(fig, animate, frames=10, interval=500, repeat = False)

anim.save('jacobi.gif', writer='imagemagick', fps=2)