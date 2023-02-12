from matplotlib import pyplot as plt
import numpy as np 
import matplotlib.animation as animation

#run this file with `python3 game.py` from command line

    


# dimension of the NxN grid
N = 3


def next_iteration(grid, max):
    plt.imshow(np.array([grid[i, :] for i in range(grid.shape[1])]))
    k=0
    while np.sum(grid) != 0 and k < max:
        k += 1
        next_grid = grid.copy()
        for i in range(N):
            for j in range(N):
                count = grid[i, (j-1)%N] + grid[i, (j+1)%N] + grid[(i-1)%N, j] + grid[(i+1)%N, j] + grid[(i-1)%N, (j-1)%N] + grid[(i-1)%N, (j+1)%N] + grid[(i+1)%N, (j-1)%N] + grid[(i+1)%N, (j+1)%N]

                if grid[i,j] == 1:
                    if (count<2) or (count>3):
                        next_grid[i,j] = 0
                else:
                    if count == 3:
                        next_grid[i,j] = 1
        grid = next_grid
        plt.imshow(np.array([grid[i, :] for i in range(grid.shape[1])]))
        


fig=plt.figure()
#current = np.random.choice([0, 1], size=(10, 10), p=[0.5, 0.5])
current = np.zeros((5,5), dtype= int)
current[2,1] =1 
current[2,2]=1
current[2,3]= 1
curr = np.array([current[i, :] for i in range(current.shape[1])])
#you can put something depending on i here
def animate(i): 
    next_iteration(curr,i)

     
anim = animation.FuncAnimation(fig,animate,frames=10, interval=1000)

# save the animation as an gif
anim.save("gameeee.gif") 
