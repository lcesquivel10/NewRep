import numpy as np
import matplotlib.pyplot as plt
data = np.genfromtxt("dataR.dat", delimiter = ",")
x = data [0:]
y =data[1:]
plt.plot (x,y)
plt.savefig("RunnGe")