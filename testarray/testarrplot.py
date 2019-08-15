#!/usr/bin/python

import matplotlib.pyplot as plt
import subprocess as sp
import numpy as np
import pyaudio

p = sp.Popen(['./testarr'],stdout=sp.PIPE,stderr=sp.PIPE)
output, err = p.communicate()
retc = p.returncode

strout = output.decode("utf-8")
sine_sample = np.fromstring(strout,sep=',',dtype=np.uint16)

plt.plot(sine_sample)
plt.show()
