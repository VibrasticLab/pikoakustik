from numpy import genfromtxt
import matplotlib.pyplot as plt

wave = genfromtxt('data.csv', delimiter=',')
plt.plot(wave,'ro')