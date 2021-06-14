#!/usr/bin/python3
# -*- coding: utf-8 -*-

import numpy as np
import sounddevice as sd
from scipy import fftpack
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

def update_data(i):
	fs = 44100
	duration = 0.1

	mycapture = sd.rec(1024,channels=2)
	sd.wait()

	splsL = fftpack.fft(mycapture[:,0])
	freqs = fftpack.fftfreq(len(mycapture[:,0])) * fs
	splsR = fftpack.fft(mycapture[:,1])

	axL.cla()
	axL.loglog(freqs,np.abs(splsL))
	axL.grid(True,which='both',ls='-')
	axL.set_xlim([32,10000])
	axL.set_ylim([0.01,10000])

	axR.cla()
	axR.loglog(freqs,np.abs(splsR))
	axR.grid(True,which='both',ls='-')
	axR.set_xlim([32,10000])
	axR.set_ylim([0.01,10000])

sd.default.device = 2, None
sd.default.channels = 2, None
#print(sd.query_devices())

fig = plt.figure(figsize=(12,6), facecolor='#DEDEDE')
axL = plt.subplot(211)
axR = plt.subplot(212)
axL.set_facecolor('#DEDEDE')
axR.set_facecolor('#DEDEDE')
ani = FuncAnimation(fig, update_data, interval=1)
plt.show()
