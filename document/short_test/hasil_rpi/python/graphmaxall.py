#!/usr/bin/python

import os
import numpy as np
import matplotlib.pyplot as plt

outPhone = ['bose','miniso']

# outFreq = [250,500,1000,2000,4000,8000]
# outAmpl = [0.0039,0.0078,0.0156,0.0312,0.0625,0.125,0.25,0.5,1]

outFreq = [250,500,1000,2000,4000,8000,16000]
outAmpl = [30,40,50,60,70,80,90]

def getMax(fileName,inFreq,rangeFreq=1000):
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

    low_F = inFreq-rangeFreq
    hi_F = inFreq+rangeFreq

    arrLow_F = allData_F>=low_F
    arrHi_F = allData_F<hi_F
    range_F = allData_F[np.logical_and(arrLow_F,arrHi_F)]

    arrResult = np.array([0])
    for i in range_F:
        idx = np.where(allData_F==i)
        oneResult = allData_L[idx]
        arrResult = np.vstack((arrResult,oneResult))

    lenResult=len(arrResult)
    arrResult=arrResult[1:lenResult]
    return np.amax(arrResult)

def plotGraph(outFolder):
    freqMax = np.array([])
    for freq in outFreq:
        arrTemp = np.array([])
        currentPath='../' + outFolder + '/' + str(freq)
        #print('freq: '+ str(freq))
        for root, dirs, files in os.walk(currentPath):
            for file in files:
                if file.endswith(".csv"):
                    currentFile=os.path.join(root, file)
                    vmax = getMax(currentFile,freq)
                    arrTemp = np.append(arrTemp,vmax)

        globals()['f_' + str(freq)] = np.sort(arrTemp)
        #print(globals()['f_' + str(freq)])
    
        freqMax = np.append(freqMax,np.amax(globals()['f_' + str(freq)]))
    return freqMax
    
for inFolder in outPhone:
    amplMax = plotGraph(inFolder)
    print(inFolder)
    print(amplMax)
    
    plt.plot(outFreq,amplMax,'-o',label=inFolder,)

plt.figure(1)
plt.xticks(outFreq)
plt.xlabel('frequency (Hz)')
plt.ylabel('SPL Max (dB)')
plt.ylim(-10,100)
plt.legend()

plt.show()