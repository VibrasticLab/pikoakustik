#!/usr/bin/python

import matplotlib.pyplot as plt
import subprocess as sp
import numpy as np
import pyaudio

fs = 44100       # sampling rate, Hz, must be integer
duration = 1.0   # in seconds, may be float
f = 440.0 

p = sp.Popen(['./testarr'],stdout=sp.PIPE,stderr=sp.PIPE)
output, err = p.communicate()
retc = p.returncode

strout = output.decode("utf-8")
sine_sample = np.fromstring(strout,sep=',',dtype=np.uint16)
#sample = 0.5 * (np.sin(2*np.pi*np.arange(fs*duration)*f/fs) + 1).astype(np.float32)

aud = pyaudio.PyAudio()
audstream = aud.open(format=pyaudio.paFloat32,channels=1,rate=fs,output=True)

#audstream.write(sample)
audstream.write(sine_sample)

audstream.stop_stream()
audstream.close()
aud.terminate()

#plt.plot(sample)
plt.plot(sine_sample)
plt.show()
