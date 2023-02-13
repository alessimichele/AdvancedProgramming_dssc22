import numpy as np
from matplotlib import pyplot as plt
import matplotlib.animation as animation
import time

# grid size
N = 20

def jacobi(N, iteration):
    grid = np.zeros((N+2, N+2))
    K = 100.0/((N + 2) - 1)
    for i in range(N+2):
        grid[i,0]= K*i
        grid[N+1, i] = 100 - K*i
    plt.imshow(grid)
    k = 0
    while k < iteration:
        k += 1
        next_grid = grid.copy()
        for i in range(1, N+1):
            for j in range(1, N+1):
                next_grid[i,j] = 0.25 * (grid[i-1, j] + grid[i+1, j] + grid[i, j-1] + grid[i, j+1])
        grid = next_grid
        plt.imshow(grid)


fig = plt.figure()
def animate(i):
    jacobi(N, i)

anim = animation.FuncAnimation(fig,animate,frames=30, interval=100)

# save the animation as an gif
anim.save("./images/jacobi_{}.gif".format(time.time())) 