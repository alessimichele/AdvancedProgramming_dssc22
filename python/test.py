import numpy as np
import matplotlib.pyplot as plt

import sys
# caution: path[0] is reserved for script path (or '' in REPL)
sys.path.insert(1, './game_of_life')

from game_of_life import next_iteration, find_neigh

def onclick(event):
    global data
    if event.inaxes:
        x, y = int(event.xdata), int(event.ydata)
        data[y, x] = 1
        plt.imshow(data, cmap='gray')
        plt.draw()

def onkey(event):
    if event.key == 'q':
        plt.close()

# Define the grid size
grid_size = (10, 10)
data = np.zeros(grid_size, dtype=int)

# Display the grid
plt.imshow(data, cmap='gray')
plt.connect('button_press_event', onclick)
plt.connect('key_press_event', onkey)
plt.show()

# Store the grid into a numpy array
grid = data

### game

def game_of_life(initial_state, number_of_it):
    k=0
    current = initial_state
    plt.imshow(np.array([current[i, :] for i in range(current.shape[1])]))
    while np.sum(current)!=0 and k<number_of_it:
        current = next_iteration(current)
        #print(current)
        #curr_img = plot_grid(current)
        plt.imshow(np.array([current[i, :] for i in range(current.shape[1])]))
        k = k+1


import matplotlib.animation as animation

fig=plt.figure()
current = grid
#current = np.zeros((5,5), dtype= int)
#current[2,1] =1 
#current[2,2]=1
#current[2,3]= 1
curr = np.array([current[i, :] for i in range(current.shape[1])])
#you can put something depending on i here
def animate(f): 
    game_of_life(curr,f)

     
anim = animation.FuncAnimation(fig,animate,frames=10, interval=1000)

# save the animation as an gif
anim.save("game_of_life.gif") 
