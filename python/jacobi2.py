import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def Jacobi_solver(n, n_iter):
    mesh = np.zeros((n+1, n+1), dtype = "float")
    # Initial setup
    for i in range(0, mesh.shape[1]):
        mesh[i, 0] = (100/n) * i
        mesh[mesh.shape[1]-1, i] = (100/n) * (mesh.shape[1] - i - 1)
    for i in range(1, mesh.shape[1]-1):
        for j in range(1, mesh.shape[1]-1):
            mesh[i, j] = 0.5

    k = 0  
    while k < n_iter:
        k += 1
        mesh_old = mesh #since we need to use old values not new ones.
        for i in range(1, mesh.shape[1]-1):
            for j in range(1, mesh.shape[1]-1):
                mesh[i, j] = 0.25 * (mesh_old[i-1, j] + mesh_old[i+1, j] + mesh_old[i, j-1] + mesh_old[i, j+1])
        final = np.array([mesh[i, :] for i in range(mesh.shape[1])])
        plt.imshow(mesh)

        


fig=plt.figure()
#you can put something depending on i here
def animate(i): 
   Jacobi_solver(20, i)

     
anim = animation.FuncAnimation(fig,animate,frames=75, interval=0.25)

# save the animation as an gif
anim.save("jacobi2.gif") 