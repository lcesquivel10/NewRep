import numpy as np
import matplotlib.pyplot as plt
data = np.genfromtxt("ondacuerda.dat", delimiter = ",")
posicion = data[:,0]
condicion1 =data[:,1]
condicion2 =data[:,2]
condicion3 =data[:,3]
plt.plot(posicion, condicion1, color = "green")
plt.grid
plt.title ( "Amplitud vs Posicion  (condicion 1)")
plt.xlabel ("Posicion")
plt.ylabel ("Amplitud")
plt.legend
plt.savefig ("condicion1.png")
plt.plot(posicion, condicion2, color = "magenta")
plt.grid
plt.title ( "Amplitud vs Posicion  (condicion 2)")
plt.xlabel ("Posicion")
plt.ylabel ("Amplitud")
plt.legend
plt.savefig ("condicion2.png")
plt.plot(posicion, condicion3)
plt.grid
plt.title ( "Amplitud vs Posicion  (condicion 3)")
plt.xlabel ("Posicion")
plt.ylabel ("Amplitud")
plt.legend
plt.savefig ("condicion3.png")

