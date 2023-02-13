import numpy as np
from matplotlib import pyplot as plt
import matplotlib.animation as animation
from game import find_neigh, next_iteration, game_of_life


### input/putput

def onclick(event):
    global data
    if event.inaxes:
        x, y = int(event.xdata), int(event.ydata)
        data[y, x] = 1 - data[y, x]
        plt.imshow(data, cmap='gray')
        plt.draw()

def onkey(event):
    if event.key == 'q':
        plt.close()

# Define the grid size

grid_size = (30, 30)
data = np.zeros(grid_size, dtype=int)

# Display the grid
plt.imshow(data, cmap='gray')
plt.connect('button_press_event', onclick)
plt.connect('key_press_event', onkey)
plt.show()

# Store the grid into a numpy array
current = data

# game
fig=plt.figure()
#curr = np.array([current[i, :] for i in range(current.shape[1])])

def animate(f): 
    game_of_life(current,f)

anim = animation.FuncAnimation(fig,animate,frames=15, interval=1000)

import time
anim.save("./images/game_of_life_{}.gif".format(time.time())) 
