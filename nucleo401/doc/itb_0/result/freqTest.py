#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 14 14:44:31 2019

@author: achmadi
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def get_data(csv_file):
    np_data = pd.read_csv(csv_file,header=1).to_numpy()
    f_data = np_data[:,0]
    l_data = np_data[:,1]
    r_data = np_data[:,2]
    
    return np.vstack((f_data,l_data,r_data))
  
def value_data(fftdata,name=''):
    lmax = np.amax(fftdata[1])
    flmax = fftdata[0][np.argmax(fftdata[1])]
    
    rmax = np.amax(fftdata[2])
    frmax = fftdata[0][np.argmax(fftdata[2])]
    
    freq = (flmax + frmax)/2
    spl = (lmax + rmax)/2
    
    print('%s => freq: %d | spl: %d' % (name,freq,spl))
    return freq,spl

def plot_data(fftdata):
    plt.figure()
    
    plt.subplot(211)
    plt.plot(fftdata[0],fftdata[1],'r')
    plt.xscale('log')
    
    plt.subplot(212)
    plt.plot(fftdata[0],fftdata[2],'b')
    plt.xscale('log')

print('===============')
print('List Value:')
value_data(get_data('day_4/newsine400.csv'),'sine400')
