#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import math

I2S_BUFF_SIZE = 256
SAMPLING_RATE = 44100

ampl = 1000
freq = 1000

x = np.array([])
y = np.array([])

for i in range(I2S_BUFF_SIZE):
	x = np.append(x,i)
	y = np.append(
				y,
				ampl*(math.sin(2.0*3.14159*freq*(i/SAMPLING_RATE))+1)
				)

plt.plot(x,y,'ro')
plt.show(block=True)
