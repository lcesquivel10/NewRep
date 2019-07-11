import numpy as np
import matplotlib.pylab as plt

data1 = np.genfromtxt("cuerdaonda.dat", delimiter=",")
t=data1[:,0]
y1=data1[:,1]
y2=data1[:,2]
y3=data1[:,3]

plt.plot(t,y1, color ="green")
plt.title("Condicion 1")
plt.xlabel("Longitud(m)")
plt.ylabel("Amplitud(m)")
plt.savefig("cuerda1.pdf")
plt.grid()

plt.figure()
plt.plot(t,y2,color ="green")
plt.title("Condicion 2")
plt.grid()
plt.xlabel("Longitud(m)")
plt.ylabel("Amplitud(m)")
plt.savefig("cuerda2.pdf")
plt.figure()

plt.plot(t,y3,color ="green")
plt.title("Condicion 3")
plt.grid()
plt.xlabel("Longitud(m)")
plt.ylabel("Amplitud(m)")
plt.savefig("cuerda3.pdf")
plt.show()

