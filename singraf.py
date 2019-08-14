#!/usr/bin/python

import numpy as np
import math as mt
import matplotlib.pyplot as plt

NUM_SAMPLES = 512
SAMPLING_RATE = 44100

# one wave length
def onewavelen(FR,AMP):
	x = 0
	y = 0
	
	neg_a = 0
	neg_b = 0
	phase = 0
	stop = 0
	sample = 0
	
	sine_sample = np.zeros(NUM_SAMPLES)
	sine_sample[0] = AMP * 0.2
	
	i = 1
	
	while stop == 0:
		x = i / SAMPLING_RATE
		y = mt.sin(2.0 * mt.pi * FR * x ) + 1
		sample = AMP * 0.2 * y

		sine_sample[i] = sample
		i = i + 1

		if sample == 2000:
			phase = phase + 1
		elif sample > 2000:
			neg_b = 0
		elif sample < 2000:
			neg_b = 1

		if neg_b != neg_a:
			phase = phase + 1
			neg_a = neg_b
			if phase == 2:
				stop = 1
		elif neg_b == neg_a:
			neg_a = neg_b
			
		if i == NUM_SAMPLES:
			stop = 1
	
	print("one wave len = %i" % i)
	return i

# build wave sample
def sample_prep(FR, DUR, AMP):
	x = 0
	y = 0
	
	waveone = onewavelen(FR,AMP)
	wavenum = int(NUM_SAMPLES/waveone)
	wavelen = wavenum * waveone

	sample = 0
	
	sine_sample = np.zeros(NUM_SAMPLES)
	sine_sample[0] = AMP * 0.2

	for i in range(1,NUM_SAMPLES):
		x = i / SAMPLING_RATE
		y = mt.sin(2.0 * mt.pi * FR * x ) + 1
		sample = AMP * 0.2 * y

		sine_sample[i] = sample
		i = i + 1

	print("wave len = %i * %i = %i" % (wavenum,waveone,wavelen))
	wave_sample = sine_sample[0:wavelen+1]
	return wave_sample
         
datasin = sample_prep(1000,2,10000)
plt.plot(datasin)
plt.show()
