import numpy as np
from matplotlib import pyplot as plt
import matplotlib.animation as animation
from game import game_of_life

"""
Instruction:
- be sure to be in the game_of_life directory

- if you want to change the grid size, change only N_horizontal and N_vertical

- to play, run this code. A window will open. By click on that, you can buld the initial configuration as you want

- when you are done with your configuration, press "q" on your keyboard

- in "images" folder, you should be able to see your output gif, named "game_of_life_{current_time}"

"""

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
N_horizontal = 30
N_vertical = 30

grid_size = (N_horizontal, N_vertical) 
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
