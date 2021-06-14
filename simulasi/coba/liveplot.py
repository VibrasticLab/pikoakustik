#!/usr/bin/python3
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation
import psutil
import collections

def my_function(i):
	cpu.popleft()
	cpu.append(psutil.cpu_percent())

	ram.popleft()
	ram.append(psutil.virtual_memory().percent)

	ax.cla()
	ax1.cla()

	ax.plot(cpu)
	ax.scatter(len(cpu)-1, cpu[-1])
	ax.text(len(cpu)-1, cpu[-1]+2, "{}%".format(cpu[-1]))
	ax.set_ylim(0,100)

	ax1.plot(ram)
	ax1.scatter(len(ram)-1, ram[-1])
	ax1.text(len(ram)-1, ram[-1]+2, "{}%".format(ram[-1]))
	ax1.set_ylim(0,100)


cpu = collections.deque(np.zeros(10))
ram = collections.deque(np.zeros(10))

# define and adjust figure
fig = plt.figure(figsize=(12,6), facecolor='#DEDEDE')

ax = plt.subplot(121)
ax1 = plt.subplot(122)

ax.set_facecolor('#DEDEDE')
ax1.set_facecolor('#DEDEDE')# test

ani = FuncAnimation(fig, my_function, interval=10)
plt.show()
