#!/usr/bin/python

import os
import numpy as np
import matplotlib.pyplot as plt

fileName = '../../hasil_rpi/bose/1000/90.csv'
fileRead = open(fileName,'rt')
fileBuff = fileRead.readlines()
fileLen  = len(fileBuff)
fileData = fileBuff[2:fileLen-1]

buffData = np.array([0,0,0])
for line in fileData:
    oneData = np.fromstring(line,sep=',')
    buffData = np.vstack((buffData,oneData))
allData = buffData[1:fileLen]
allData_F = allData[:,0]
allData_L = allData[:,1]
#allData_R = allData[:,2]

plt.figure(1)
plt.plot(allData_F,allData_L,'-')
plt.xlabel('frequency (Hz)')
plt.ylabel('SPL Max (dB)')
plt.xlim(0,13000)
plt.ylim(-10,100)

plt.show()
