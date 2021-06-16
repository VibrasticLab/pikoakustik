#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import sounddevice as sd
from scipy import fftpack
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

import time
import serial
import threading

def update_data(i):
	fs = 44100

	mycapture = sd.rec(4096,channels=2)
	sd.wait()

	spl_L = np.fft.rfft(mycapture[:,0])
	freqs = np.fft.rfftfreq(len(mycapture[:,0])) * fs
	spl_R = np.fft.rfft(mycapture[:,1])

	lineL.set_data(freqs,np.abs(spl_L))
	lineR.set_data(freqs,np.abs(spl_R))

def tone_request():
	threading.Timer(60,tone_request).start()
	#print("trying test tone")
	ser = serial.Serial('/dev/ttyACM0',9600,timeout=1)
	ser.write(b'out 1 500 9 5000\n\r')
	ser.close()

mycapture = np.array([])

sd.default.device = 2, None
sd.default.channels = 2, None
print(sd.query_devices())

fig = plt.figure(figsize=(8,4), facecolor='#DEDEDE')

axL = plt.subplot(211)
axL.set_facecolor('#DEDEDE')
axL.grid(True,which='both',ls='-')
axL.set_xlim([32,10000])
axL.set_ylim([0.1,1000])
lineL, = axL.loglog([1])

axR = plt.subplot(212)
axR.set_facecolor('#DEDEDE')
axR.grid(True,which='both',ls='-')
axR.set_xlim([32,10000])
axR.set_ylim([0.1,1000])
lineR, = axR.loglog([1])

#tone_request()

ani = FuncAnimation(fig, update_data, interval=1)
plt.show()
