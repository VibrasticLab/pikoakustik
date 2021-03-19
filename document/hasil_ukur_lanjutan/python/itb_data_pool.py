#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar 12 15:29:58 2021

@author: achmaday
"""

import numpy as np

class ITBDataPool():
    def __init__(self):
        super(ITBDataPool, self).__init__()

        # Ground Data
        self.Octave_FreqStr = ['16-L', '16-R', '31.5-L', '31.5-R', '63-L', '63-R', '125-L', '125-R', '250-L', '250-R', '500-L', '500-R', '1k-L', '1k-R', '2k-L', '2k-R', '4k-L', '4k-R', '8k-L', '8k-R', '16k-L', '16k-R']

        self.NoUnitNoHP_Second = np.array([17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41])
        self.NoUnitNoHP_Data = np.array([
            [37.5, 40.79, 39.11, 42.07, 36.16, 39.46, 35.21, 35.41, 32.33, 31.77, 31.33, 32.97, 32.65, 33.83, 34.99, 36.05, 38.19, 38.67, 40.78, 41.18, 43.38, 44.09],
            [39.66, 36.37, 40.15, 43.74, 39.43, 41.97, 34.82, 37.5, 32.14, 33.04, 31.01, 32.17, 32.53, 33.7, 35.27, 36.61, 37.94, 38.02, 40.48, 41.37, 43.49, 44.13],
            [40.81, 42.33, 40.31, 39.85, 37.78, 40.06, 34.63, 36.73, 33.27, 33.46, 32.25, 32.16, 33.86, 34.11, 35.54, 35.64, 38.92, 38.64, 40.86, 41.64, 43.82, 44.05],
            [40.03, 42.11, 39.89, 40.36, 37.8, 35.5, 34.25, 35.6, 32.35, 33.15, 31.95, 32.57, 33.96, 34.1, 35.72, 36.28, 37.87, 38.65, 40.75, 41.42, 43.57, 44.23],
            [40.26, 41.43, 40.53, 39.24, 37.35, 35.44, 36.21, 36.48, 32.24, 34.13, 32.32, 33.76, 33.76, 33.41, 34.77, 35.58, 38.15, 38.28, 41.02, 41.12, 43.96, 43.93],
            [42.35, 37.97, 39.9, 40.02, 39.1, 37.31, 33.77, 34, 31.21, 34.49, 31.6, 32.78, 33.07, 32.93, 34.64, 35.28, 37.85, 38.35, 40.71, 41.15, 43.51, 43.88],
            [40.78, 47.28, 40.42, 42.05, 37.62, 35.13, 32.82, 37.4, 32.43, 33.62, 31.8, 32.73, 34.03, 33.48, 35.7, 35.83, 38.43, 38.04, 40.87, 41.27, 43.59, 43.98],
            [40.09, 39.49, 41.76, 43.89, 38.16, 38.54, 34.41, 34.64, 30.83, 32.19, 31.9, 33.87, 33.37, 34.26, 35.2, 35.79, 37.56, 38.73, 40.94, 41.74, 43.72, 44.15],
            [39.74, 41.02, 39.35, 39.97, 36.68, 36.28, 36.72, 35.11, 33.94, 32.95, 32.79, 32.56, 33.74, 33.28, 35.82, 35.26, 38.19, 37.8, 40.89, 40.96, 43.83, 43.84],
            [37.41, 45.25, 35.96, 38.27, 36.48, 36.04, 36.11, 36.1, 34.11, 32.57, 31.39, 32.88, 33.8, 32.75, 35.43, 35.52, 37.88, 38.14, 40.64, 41.58, 43.56, 44.05],
            [39.94, 44.22, 40.4, 42.67, 38.13, 38.86, 34.88, 37.71, 33.46, 34.46, 32.2, 33.42, 32.42, 34.71, 35.66, 35.84, 38.11, 38.69, 40.65, 41.45, 43.69, 44.22],
            [37.73, 39.05, 41.12, 42.79, 37.04, 36.86, 33.37, 35.48, 33.27, 33.4, 32.5, 31.63, 33.85, 33.65, 35.64, 35.69, 38.27, 38.07, 40.8, 41.24, 43.95, 43.77],
            [36.63, 39.32, 37.99, 38.93, 33.53, 37.17, 32.04, 34.41, 30.55, 34.05, 32.02, 33.53, 32.62, 33.58, 35.29, 35.99, 37.77, 38.58, 40.53, 41.48, 43.89, 44.03],
            [40.29, 41.44, 43.19, 41.71, 33.73, 37.67, 33.56, 34.99, 33.6, 32.72, 32.06, 31.76, 33.41, 33.28, 36.02, 35.94, 38.55, 37.76, 40.92, 41.36, 43.83, 43.87],
            [40.39, 41.34, 36.86, 39.52, 37.93, 36.34, 34.45, 34.88, 33.57, 34.23, 33.65, 32.56, 33.37, 33.3, 35.15, 35.91, 37.9, 38.36, 40.87, 41.29, 43.69, 43.91],
            [42.06, 46.36, 40.35, 47.25, 38.31, 38.64, 35.51, 35.7, 33.55, 33.67, 32.4, 33.76, 32.83, 34.01, 34.89, 35.92, 38.32, 38.62, 40.6, 41.52, 43.76, 43.94],
            [41.47, 37.8, 42.66, 37.83, 36.45, 39.81, 34.89, 37.23, 33.24, 34.88, 32.34, 34.08, 33.94, 32.91, 35.64, 35.69, 38, 38.03, 40.98, 41.3, 43.69, 43.69],
            [39.29, 38.79, 41.18, 40.23, 35.62, 35.89, 34.59, 36.66, 32.57, 32.82, 32.21, 32.26, 33.4, 33.65, 35.67, 36.03, 38.35, 38.01, 40.91, 41.29, 43.69, 43.65],
            [43.75, 45.11, 41.76, 43.49, 36.47, 37.81, 33.49, 35.52, 34.2, 33.87, 31.16, 33.02, 33.46, 33.38, 35.55, 36.09, 37.67, 39.15, 40.75, 41.47, 43.57, 43.98],
            [42.55, 40.18, 40.24, 38.73, 34.08, 38.45, 34.78, 34.51, 31.81, 32.4, 31.64, 32.48, 32.83, 33.46, 35.23, 35.27, 38.03, 38.26, 40.96, 41.18, 43.55, 44.03],
            [47.24, 40.36, 41.89, 42.69, 37.24, 39.17, 36.55, 37.6, 34.09, 36.09, 32.83, 33.4, 33.44, 33.53, 35.36, 35.97, 38.35, 38.83, 40.77, 41.72, 43.88, 44.44],
            [41.48, 38.26, 34.73, 39.36, 33.84, 39.65, 32.98, 34.29, 32.93, 33.61, 32.72, 33.92, 33.37, 33.11, 35.73, 35.82, 38.61, 38.05, 40.89, 41.26, 44.13, 43.81],
            [38.35, 43.95, 40.02, 46.84, 37.89, 39.04, 36.15, 35.42, 32.78, 34.89, 32.37, 32.13, 32.95, 33.95, 35.7, 36, 37.6, 38.13, 40.67, 41.17, 43.36, 43.95],
            [45.41, 45.19, 40.5, 38.9, 35.63, 37.58, 35.84, 34.6, 32.08, 32.38, 32.5, 32.78, 33.94, 34.06, 35.12, 35.85, 38.38, 38.68, 40.9, 41.39, 43.5, 43.86],
            [41.7, 40.42, 38.91, 40.3, 35.71, 37.92, 35.15, 35.38, 33.89, 33.98, 32.02, 33.6, 34.06, 33.26, 34.99, 35.97, 38.08, 38.2, 40.78, 41.59, 43.69, 43.9],
        ])

        self.NoUnitMiniso_Second = np.array([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52])
        self.NoUnitMiniso_Data = np.array([
            [45.73, 42.91, 44.2, 41.64, 40.81, 36.03, 37.9, 34.88, 31.1, 32.79, 31.7, 32.88, 32.77, 33.61, 35.32, 35.45, 38.16, 38.47, 40.85, 41.24, 43.62, 44.01],
            [45.04, 42.33, 42.26, 41.97, 43.25, 41.55, 41.43, 37.3, 32.1, 34.6, 32.06, 32.15, 32.73, 34.61, 35.87, 36.12, 37.87, 38.46, 40.75, 41.31, 43.62, 43.77],
            [45.04, 41.28, 38.53, 39.87, 42.68, 39.39, 38.34, 36.57, 34.37, 34.3, 32.21, 31.62, 33.52, 33.12, 35.05, 35.41, 38.07, 38.4, 41.21, 41.3, 43.79, 43.79],
            [41.86, 42.05, 40.53, 44.04, 42.03, 38.13, 39.34, 36.2, 34, 32.54, 32.56, 32.6, 33.62, 33.47, 35.54, 35.81, 37.81, 38.47, 40.3, 41.51, 43.83, 43.89],
            [41.64, 42.86, 48.91, 44.35, 44.51, 40.27, 40.06, 35.9, 34, 35.31, 31.32, 32.85, 33.4, 33.74, 35.9, 35.25, 37.8, 38.28, 40.9, 41.34, 43.77, 43.97],
            [41.71, 36.17, 39.17, 38.79, 42.56, 38.82, 40.18, 35.17, 31.92, 32.39, 31.52, 32.33, 33.4, 33.71, 35.66, 35.38, 38.13, 37.97, 40.86, 40.91, 43.68, 43.73],
            [39.48, 42.85, 42.07, 41.88, 42.07, 36.64, 42.91, 36.19, 34.43, 33.07, 32.64, 33.08, 33.34, 33.66, 35.26, 36.13, 37.96, 38.55, 40.71, 41.28, 43.63, 43.98],
            [40.93, 45.27, 39.99, 43.79, 43.66, 35.67, 40.75, 37.08, 31.36, 34.37, 32.03, 33.49, 32.34, 33.93, 35.94, 36.26, 38.03, 38.6, 40.71, 41.46, 43.62, 44.15],
            [39.91, 43.98, 43.01, 42.72, 44.99, 37.8, 41.61, 34.72, 33.57, 32.74, 31.44, 32.4, 32.42, 32.97, 35.33, 35.75, 37.78, 38.21, 41.08, 41.42, 43.9, 43.84],
            [38.43, 38.53, 41.5, 40.27, 43.79, 38.02, 42.33, 34.93, 31.8, 32.63, 32.93, 33.17, 33.97, 33.99, 35.5, 35.57, 38.44, 38.15, 40.94, 40.87, 43.69, 43.82],
            [41.79, 39.39, 43.53, 40.03, 45.26, 38.89, 44.11, 35.66, 32.17, 33.91, 31.79, 32.6, 33.41, 33.28, 35.3, 35.28, 37.71, 38.09, 40.87, 41.21, 43.7, 43.69],
            [41.9, 42.79, 39.61, 40.78, 43.66, 38.85, 40.75, 35.45, 32.75, 33.99, 32.25, 31.45, 33.01, 34.04, 35.5, 35.21, 38.27, 38.27, 40.92, 41.12, 43.83, 43.87],
            [40.52, 43.45, 39.3, 42.25, 43.81, 35.13, 42.64, 33, 32.46, 32.76, 30.8, 31.7, 33.42, 34.05, 35.45, 35.37, 38.14, 38.36, 40.72, 41.31, 43.8, 44.13],
            [41.7, 45.99, 38.48, 40.38, 45.52, 36.94, 43.45, 36.08, 34.53, 33.5, 32.16, 32.91, 34.09, 32.95, 35.34, 36.21, 37.8, 38.54, 41.19, 41.27, 43.75, 44.3],
            [38.65, 40.48, 41.77, 42.62, 45.47, 39.52, 41.98, 37.03, 32.72, 33.83, 32.55, 31.72, 32.61, 34.05, 35.58, 35.65, 38.31, 38.99, 40.75, 41.47, 43.7, 44.1],
            [43.34, 41.99, 39.32, 41.39, 42.14, 42, 40.3, 37.93, 33.07, 34.91, 31.71, 31.71, 32.7, 34.25, 35.5, 35.82, 37.85, 38.29, 40.75, 41.3, 43.88, 43.93],
            [35.48, 40.19, 38.19, 40.31, 44.84, 37.53, 42.64, 35.93, 32.38, 33.92, 31.82, 32.5, 33.22, 33.11, 34.54, 35.63, 38.37, 38.69, 40.78, 41.28, 43.76, 43.87],
            [38.29, 41.07, 41.73, 42.3, 41.4, 39.86, 42.2, 35.07, 32.7, 33.11, 31.49, 32.73, 32.95, 33.67, 35.43, 36.21, 38.3, 38.92, 40.62, 41.64, 43.59, 44.19],
            [43.98, 38.18, 40.7, 40.03, 42.09, 38.01, 39.56, 35.19, 32.8, 33.6, 32, 33.08, 33.6, 33.47, 34.75, 36.29, 38.03, 38.53, 41.02, 41.32, 43.71, 44.08],
            [45.38, 38.45, 46.5, 40.39, 44.69, 37.23, 44.19, 36.73, 33.48, 34.94, 32.24, 33.16, 33.37, 33.49, 35.54, 36.12, 37.79, 38.32, 40.83, 41.04, 43.79, 44.02],
            [40.84, 43, 42.71, 42.68, 44.65, 38.46, 41.31, 35.99, 34.13, 33.98, 32.28, 32.54, 32.89, 34.24, 35.66, 35.37, 37.97, 38.17, 41.08, 41.76, 43.89, 43.53],
            [39.98, 44.61, 41.25, 37.37, 45.61, 38.36, 42.31, 37.92, 33.07, 31.95, 31.76, 32.62, 32.19, 33.58, 35.39, 36.07, 37.96, 38.27, 41.03, 41.41, 43.88, 43.98],
            [41.77, 41.19, 41.37, 42.33, 41.92, 38.29, 40.91, 33.37, 33.18, 32.43, 31.76, 31.65, 33.38, 33.32, 35.33, 35.65, 38.21, 38.59, 40.57, 41.27, 43.66, 43.76],
            [43.8, 42.54, 45.62, 43.86, 43.91, 37.87, 40.05, 36.38, 33.76, 33.02, 32.35, 32.73, 33.46, 33.85, 35.71, 35.48, 37.9, 38.08, 40.89, 41.44, 43.81, 43.93],
            [44.18, 41.49, 38.04, 33.62, 43.96, 37.04, 42.91, 35.77, 32.08, 33.98, 31.31, 31.6, 32.59, 33.89, 35.18, 36.35, 37.95, 38.59, 40.93, 41.15, 43.62, 44.11],
            [41.43, 36.59, 40.92, 43.11, 45.05, 37.27, 43.17, 34.23, 32.89, 31.47, 32.26, 32.19, 33.53, 33.26, 36.08, 35.7, 37.8, 38.32, 40.85, 41.11, 43.58, 43.84],
            [41.64, 39.77, 41.62, 42.77, 42.97, 37.73, 40.95, 35.58, 33.17, 34.03, 30.94, 31.84, 33.46, 33.54, 35.38, 35.71, 37.94, 38.13, 41.21, 41.04, 43.98, 43.9],
            [44.92, 40.86, 42.91, 41.01, 44.83, 39.04, 41.87, 35.78, 31.93, 32.96, 31.58, 31.45, 32.22, 33.4, 35.53, 35.71, 38.17, 38.61, 40.58, 41.76, 43.7, 44.06],
            [43.23, 42.5, 40.61, 42.58, 45.16, 37, 43.18, 35.5, 33.98, 33.24, 32.67, 31.83, 33.52, 33.82, 35.63, 35.74, 38.17, 38.18, 41.01, 41.2, 43.8, 43.84],
            [38.4, 39.07, 43.09, 42.95, 45.52, 38.56, 44.25, 37.39, 32.37, 34.08, 32.33, 31.66, 33.21, 33.79, 35.5, 35.72, 37.73, 38.67, 41.01, 41.46, 43.78, 43.95],
            [39.3, 43.79, 40.36, 44.18, 45.39, 38.83, 44.04, 36.13, 33.46, 34.25, 30.51, 33.01, 33.11, 33.13, 35.28, 36.69, 38.09, 38.46, 41.02, 41.52, 43.69, 44.09],
            [41.05, 43.02, 44.63, 44.34, 42.88, 39.06, 40.75, 35.38, 34, 34.04, 32.46, 31.99, 32.92, 33.44, 35.15, 35.58, 37.94, 38.46, 40.85, 41.24, 43.6, 43.94],
            [38.66, 41.93, 44.73, 45.52, 46.26, 39.44, 44.31, 35.92, 34.05, 31.58, 32.14, 32.17, 33.34, 34.09, 35.57, 35.4, 37.98, 38.28, 40.85, 40.97, 43.86, 43.74],
            [42.15, 41.96, 41.22, 44.02, 44.8, 34.11, 44.3, 36.63, 33.47, 35.2, 31.73, 31.4, 32.85, 33.58, 35.38, 36.08, 37.77, 38.31, 41.2, 41.35, 43.64, 43.65],
            [42.27, 40.08, 43.2, 45.06, 40.77, 40.05, 37.81, 36.18, 32.31, 34.93, 32, 32.79, 33.25, 34.09, 35.03, 36.29, 38.01, 38.53, 40.83, 41.82, 43.56, 44.24],
            [41.33, 40.9, 44.8, 41.8, 42.38, 35.46, 41.85, 34.82, 33.45, 33.33, 32.09, 34.01, 33.09, 33.72, 34.73, 34.86, 37.5, 37.82, 40.79, 41.02, 43.46, 43.68],
            [40.04, 44.5, 46.99, 43.36, 43.68, 37.46, 41.81, 35.97, 32.51, 34.76, 32.97, 31.74, 32.61, 32.61, 35.06, 35.67, 38.11, 38.78, 40.79, 41.38, 43.68, 44.01],
            [41.26, 33.76, 42.66, 42.97, 42.11, 36.6, 38.28, 35.65, 33.39, 32.19, 32.23, 32.97, 32.86, 32.73, 34.65, 35.24, 37.69, 38.06, 40.83, 40.96, 43.6, 43.72],
            [41.85, 42.1, 46.51, 41.63, 43.08, 37.84, 40.9, 36.03, 32.71, 33.74, 31.83, 31.53, 32.87, 33.92, 36.15, 35.87, 38.19, 38.59, 41.12, 41.6, 44.14, 43.94],
            [40.48, 39.7, 41.07, 41.6, 43.5, 39.07, 39.91, 34.38, 32.41, 33.34, 32.57, 31.05, 32.75, 33.17, 35.55, 35.87, 38.37, 38.44, 40.68, 41.11, 43.59, 43.95],
            [42.77, 43.54, 40.33, 43.97, 40.92, 38.79, 39.49, 35.42, 31.81, 32.14, 31.81, 32.97, 31.91, 33.87, 35.5, 35.76, 38.05, 38.82, 41.03, 41.44, 44.05, 44.04],
            [40.66, 41.89, 40.2, 40.67, 41.59, 36.77, 41.4, 36.14, 31.15, 32.08, 30.03, 32.98, 33.42, 32.94, 35.07, 36.04, 37.95, 38.25, 40.72, 40.98, 43.53, 43.9],
            [38.17, 42.46, 39.1, 39.43, 44.3, 34.85, 41.84, 35.53, 32.85, 33.47, 32.82, 32.63, 31.95, 33.69, 35.1, 35.64, 37.64, 38.03, 40.81, 41, 43.54, 43.99],
            [44.26, 44.21, 41.49, 41.35, 44.52, 39.8, 42.72, 38.13, 34.1, 31.85, 31.57, 32.46, 33.2, 32.68, 36.24, 35.91, 38.09, 38.18, 41.17, 41.26, 43.99, 43.96],
            [39.71, 43.98, 42.27, 43.49, 43.87, 33.57, 43.14, 34.34, 33.17, 32.41, 31.84, 32.19, 33.69, 32.92, 35.64, 35.86, 38, 38.45, 40.98, 41.22, 44.03, 43.77],
            [41.38, 41.49, 41.54, 41.26, 45.54, 36.77, 42.06, 36.92, 33.64, 31.91, 30.28, 33.15, 32.85, 32.69, 35.34, 35.66, 38.14, 38.16, 40.85, 41.09, 43.86, 43.63],
            [40.23, 47.87, 44.67, 43.39, 45.51, 40.74, 42.78, 35.72, 32.77, 33.23, 31.36, 32.64, 32.7, 33.71, 35.87, 35.6, 38.1, 38.65, 41.04, 41.67, 43.76, 44.18],
            [40.58, 38.93, 39.93, 40.63, 44.25, 37.69, 42.8, 36.96, 33.54, 33.42, 31.29, 32.55, 32.8, 33.73, 35.08, 36.01, 37.61, 38.09, 40.85, 41.14, 43.8, 44.02],
            [40.66, 40.37, 37.94, 44.43, 45.25, 39.27, 43.44, 35.32, 32.62, 32.36, 31.11, 32.4, 32.79, 33.84, 35.13, 36.07, 37.83, 38.89, 41.14, 41.39, 43.76, 44.07],
            [43.28, 43.36, 40.18, 39.98, 42.75, 37.47, 42.67, 36.37, 34.93, 34.75, 32.07, 32.01, 33.28, 33.48, 35.95, 35.89, 38.37, 38.33, 40.87, 41.36, 43.48, 44.18],
            [43.67, 42.08, 42.65, 42, 44.63, 37.94, 43.2, 35.39, 32.09, 34.22, 32.7, 32.56, 33.03, 33.24, 35.47, 35.67, 38.08, 38.23, 41.18, 41.46, 44, 43.66],
            [35.16, 41.32, 42.31, 43.23, 45.15, 35.69, 42.77, 36.34, 33.15, 33.07, 32.03, 32.49, 33.47, 33.46, 35.54, 34.9, 38.07, 38.1, 40.79, 41.08, 43.55, 43.76],
        ])

        self.NoUnitBose_Second = np.array([3,4,5,6,7,8,9,10,11,12,13,14])
        self.NoUnitBose_Data = np.array([
            [35.82, 34.22, 36.44, 33.52, 35.41, 32.54, 30.17, 29.8, 21.73, 21.24, 19.93, 21.2, 21.43, 22.13, 23.89, 24.36, 25.88, 26.73, 29.21, 29.76, 32.08, 32.33],
            [33.58, 25.9, 27.98, 31.03, 32.72, 30.78, 29.35, 28.61, 22.97, 20.3, 21.04, 21.48, 20.92, 22.21, 24.01, 23.6, 26.04, 26.6, 29.22, 29.85, 32, 32.36],
            [37.19, 35.86, 31.56, 31.59, 31.75, 27.9, 26.95, 28.38, 20.08, 22.78, 20.82, 21.06, 21.59, 21.71, 23.6, 24.18, 26.27, 26.82, 29.25, 29.9, 32.09, 32.6],
            [35.14, 29.87, 30.13, 28.93, 29.59, 28.17, 26.29, 26.69, 20.89, 21.74, 20.31, 21.73, 21.57, 21.94, 23.86, 24.28, 26.74, 26.95, 29.13, 29.63, 32.34, 32.44],
            [33.25, 30.54, 29.33, 26.46, 28.29, 30.46, 25.42, 29.72, 20.97, 23.44, 20.37, 20.26, 21.36, 21.53, 23.54, 24.06, 26.43, 26.84, 29.44, 29.84, 32.15, 32.4],
            [41.42, 29.28, 32.97, 28.78, 31.26, 28.07, 28.47, 27.2, 19.64, 21.2, 20.05, 20.97, 22.36, 21.75, 23.6, 24.01, 26.37, 26.97, 29.4, 29.92, 32.18, 32.34],
            [33.15, 24.67, 34.27, 32.06, 31.9, 29.96, 31.98, 28.65, 21.93, 22.04, 21.19, 20.31, 21.85, 21.32, 24.33, 24.33, 26.43, 27.04, 29.41, 29.67, 32.24, 32.45],
            [32.35, 34.03, 29.63, 30.55, 32.85, 29.19, 29.06, 27.33, 20.78, 21.5, 20.44, 20.43, 20.16, 21.83, 23.45, 23.79, 26.23, 27.18, 29.07, 29.71, 32.14, 32.35],
            [35.75, 28.18, 32.79, 27.29, 35.22, 28.95, 31.99, 25.43, 22.97, 22.71, 20.4, 21.68, 21.35, 22.07, 24.03, 23.87, 26.03, 27.01, 29.68, 29.7, 32.05, 32.15],
            [35.85, 29.86, 32.33, 28.35, 35.82, 27.58, 32.87, 26.53, 22.13, 21.76, 20.09, 20.61, 22.24, 22.27, 23.8, 24.55, 26.57, 26.78, 29.13, 29.84, 32.18, 32.21],
            [32.49, 29.99, 31.82, 35.03, 35.2, 30.1, 34.06, 25.9, 21.69, 22.81, 19.16, 21.21, 21.74, 21.74, 24.19, 23.83, 26.39, 26.58, 29.3, 29.64, 31.95, 32.25],
            [35.41, 31.42, 43.8, 39.37, 42.92, 35.86, 35.26, 32.06, 21.21, 21.63, 21.68, 21.02, 21.47, 21.77, 23.88, 23.69, 26.12, 26.84, 29.13, 29.56, 32.14, 32.05],
        ])

        # Measurement
        self.Ukur_Freq = np.array([250, 500, 1000, 2000, 4000, 8000])
        self.Ukur_OutUp = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9])
        self.Ukur_OutDown = np.array([9, 8, 7, 6, 5, 4, 3, 2, 1])

        # Day 1
        self.Day1_Bose1_Up = np.array([
            [
            [35.0, 36.2, 41.4, 45.6, 51.2, 57.0, 63.1, 69.1, 75.2],
            [35.4, 37.6, 41.9, 46.9, 52.7, 58.6, 64.7, 70.7, 76.8],
            [39.5, 42.6, 47.3, 52.7, 58.5, 64.5, 70.6, 76.6, 82.6],
            [36.7, 37.9, 41.0, 45.6, 50.8, 56.8, 62.8, 68.8, 74.9],
            [41.3, 43.4, 47.6, 52.7, 58.5, 64.4, 70.4, 76.5, 82.5],
            [41.5, 42.4, 44.5, 48.4, 53.6, 59.3, 65.3, 71.4, 77.4],
            ],
            [
            [34.7, 36.7, 41.2, 45.3, 51.0, 56.8, 63.0, 69.0, 75.1],
            [35.0, 37.7, 41.8, 47.3, 52.7, 58.7, 64.8, 70.8, 76.9],
            [39.2, 42.5, 47.3, 52.7, 58.5, 64.5, 70.6, 76.6, 82.6],
            [36.7, 37.9, 41.0, 45.4, 50.8, 56.7, 62.8, 68.8, 74.9],
            [41.2, 43.6, 47.6, 52.8, 58.5, 64.4, 70.4, 76.5, 82.5],
            [41.5, 42.3, 44.4, 48.4, 53.5, 59.3, 65.3, 71.4, 77.4],
            ],
            [
            [35.1, 36.6, 40.9, 45.4, 51.0, 56.8, 62.9, 69.0, 75.0],
            [35.0, 37.7, 41.8, 47.1, 52.8, 58.7, 64.8, 70.9, 76.9],
            [39.5, 42.7, 47.3, 52.7, 58.5, 64.5, 70.6, 76.6, 82.6],
            [36.7, 37.9, 40.6, 45.4, 50.9, 56.8, 62.8, 68.8, 74.9],
            [41.2, 43.6, 47.6, 52.8, 58.5, 64.4, 70.4, 76.5, 82.5],
            [41.6, 42.3, 44.4, 48.4, 53.6, 59.3, 65.3, 71.4, 77.4],
            ]
        ])

        self.Day1_Bose1_Down = np.array([
            [
            [75.1, 69.1, 63.0, 57.0, 51.0, 45.1, 41.1, 37.0, 34.8],
            [76.9, 70.8, 64.8, 58.7, 52.8, 47.1, 41.5, 37.6, 35.6],
            [82.6, 76.6, 70.6, 64.5, 58.5, 52.8, 47.3, 42.5, 39.2],
            [74.9, 68.8, 62.8, 56.7, 50.8, 45.4, 40.9, 37.8, 36.8],
            [82.5, 76.5, 70.5, 64.4, 58.4, 52.7, 47.6, 43.6, 40.9],
            [77.4, 71.4, 65.3, 59.3, 53.6, 48.5, 44.6, 42.2, 41.6],
            ],
            [
            [75.0, 69.0, 63.0, 56.8, 50.7, 45.2, 40.9, 36.8, 34.6],
            [76.9, 70.8, 64.8, 58.7, 52.8, 47.1, 41.5, 37.6, 35.3],
            [82.6, 76.6, 70.6, 64.5, 58.5, 52.7, 47.3, 42.6, 39.4],
            [74.9, 68.9, 62.8, 56.7, 50.9, 45.4, 40.8, 37.9, 36.7],
            [82.5, 76.5, 70.5, 64.5, 58.5, 52.7, 47.4, 43.5, 41.1],
            [77.4, 71.4, 65.3, 59.3, 53.6, 48.5, 44.6, 42.3, 41.5],
            ],
            [
            [75.0, 69.0, 63.0, 56.8, 82.6, 45.3, 40.9, 36.9, 34.8],
            [76.9, 70.9, 64.8, 58.6, 52.8, 47.2, 41.5, 37.6, 35.5],
            [82.6, 76.6, 70.6, 64.5, 58.5, 52.7, 47.3, 42.7, 39.4],
            [74.9, 68.8, 62.8, 56.7, 50.9, 45.5, 40.7, 37.8, 36.7],
            [82.5, 76.5, 70.5, 64.4, 58.5, 52.7, 47.4, 43.5, 41.1],
            [77.4, 71.3, 65.3, 59.3, 53.5, 48.2, 44.4, 42.3, 41.6],
            ]
        ])

        self.Day1_Bose2_Up = np.array([
            [
            [35.3, 36.4, 40.5, 45.1, 50.5, 56.3, 62.4, 68.5, 74.6],
            [35.8, 37.5, 41.7, 46.9, 52.4, 58.5, 64.6, 70.6, 76.7],
            [39.3, 42.5, 46.9, 52.4, 58.3, 64.3, 70.3, 76.4, 82.4],
            [36.7, 37.7, 40.9, 45.3, 50.7, 56.5, 62.5, 68.6, 74.7],
            [40.9, 43.6, 47.3, 52.5, 58.2, 64.2, 70.3, 76.3, 82.3],
            [41.4, 42.4, 44.3, 48.1, 53.3, 58.9, 64.9, 71.0, 77.0],
            ],
            [
            [34.5, 36.3, 40.4, 45.1, 50.5, 56.4, 62.5, 68.6, 74.6],
            [35.4, 37.7, 41.6, 47.0, 52.5, 58.5, 64.6, 70.6, 76.7],
            [39.1, 42.4, 47.0, 52.4, 58.3, 64.3, 70.3, 76.4, 82.4],
            [36.6, 37.9, 41.0, 45.2, 50.6, 56.5, 62.5, 68.6, 74.7],
            [41.0, 43.5, 47.4, 52.5, 58.3, 64.2, 70.2, 76.3, 82.3],
            [41.6, 42.4, 44.4, 47.9, 53.2, 58.9, 64.9, 71.0, 76.9],
            ],
            [
            [35.2, 36.5, 40.7, 44.9, 50.6, 56.4, 62.5, 68.6, 74.6],
            [35.3, 37.7, 41.5, 46.9, 52.6, 58.5, 64.6, 70.6, 76.7],
            [39.0, 42.4, 47.1, 52.4, 58.3, 64.3, 70.3, 76.4, 82.4],
            [36.6, 37.9, 41.0, 45.2, 50.6, 56.5, 62.5, 68.6, 74.7],
            [40.9, 43.5, 47.5, 52.5, 58.2, 64.2, 70.2, 76.3, 82.3],
            [41.4, 42.3, 44.4, 48.0, 53.2, 58.9, 64.9, 70.9, 76.9],
            ]
        ])

        self.Day1_Bose2_Down = np.array([
            [
            [74.6, 68.6, 62.5, 56.4, 50.5, 45.3, 40.1, 36.2, 35.0],
            [76.7, 70.7, 64.6, 58.5, 52.5, 46.9, 41.6, 37.8, 35.6],
            [82.4, 76.4, 70.3, 64.3, 58.3, 52.4, 47.1, 42.2, 39.2],
            [74.7, 68.6, 62.6, 56.5, 50.5, 45.2, 40.8, 37.8, 36.5],
            [82.3, 76.3, 70.2, 64.2, 58.3, 52.5, 47.3, 43.5, 40.9],
            [76.9, 71.0, 64.9, 58.9, 53.3, 48.1, 44.3, 42.2, 41.4],
            ],
            [
            [74.6, 68.6, 62.5, 56.4, 50.4, 45.1, 40.3, 36.3, 34.8],
            [76.7, 70.7, 64.6, 58.5, 52.6, 46.9, 41.6, 37.8, 35.4],
            [82.4, 76.4, 70.3, 64.3, 58.3, 52.5, 47.1, 42.2, 39.0],
            [74.7, 68.6, 62.5, 56.5, 50.6, 45.2, 40.7, 37.9, 36.4],
            [82.3, 76.3, 70.3, 64.2, 58.3, 52.5, 47.3, 43.3, 41.1],
            [76.9, 70.9, 64.9, 58.9, 53.2, 47.9, 44.4, 42.1, 41.4],
            ],
            [
            [74.6, 68.6, 62.5, 56.5, 50.5, 45.3, 40.2, 36.4, 34.9],
            [76.7, 70.7, 64.6, 58.5, 52.6, 46.8, 41.5, 37.7, 35.3],
            [82.4, 76.4, 70.3, 64.3, 58.3, 52.6, 46.9, 42.2, 39.0],
            [74.6, 68.6, 62.5, 56.5, 50.7, 45.2, 40.8, 37.9, 36.4],
            [82.3, 76.3, 70.3, 64.2, 58.3, 52.5, 47.3, 43.4, 41.0],
            [76.9, 70.9, 64.9, 58.9, 53.2, 48.0, 44.3, 42.2, 41.4],
            ]
        ])

        self.Day1_Miniso1_Up = np.array([
            [
            [41.3, 44.9, 49.6, 55.3, 61.2, 67.2, 73.2, 79.2, 85.2],
            [42.7, 46.5, 51.3, 57.0, 62.8, 68.8, 74.8, 80.8, 86.8],
            [46.1, 50.0, 54.8, 60.5, 66.4, 72.3, 78.3, 84.3, 90.3],
            [39.3, 41.5, 45.8, 51.1, 56.9, 62.8, 68.9, 74.9, 80.9],
            [38.5, 39.2, 41.1, 44.7, 49.8, 55.5, 61.6, 67.6, 73.7],
            [41.3, 41.9, 43.6, 47.2, 52.3, 57.9, 63.9, 70.0, 76.0],
            ],
            [
            [41.5, 44.8, 50.0, 55.3, 61.2, 67.2, 73.3, 79.3, 85.3],
            [42.7, 46.5, 51.4, 56.9, 62.8, 68.8, 74.8, 80.8, 86.8],
            [46.2, 49.9, 54.9, 60.5, 66.4, 72.4, 78.4, 84.4, 90.4],
            [39.0, 41.4, 45.7, 51.0, 56.9, 62.8, 68.9, 74.9, 80.9],
            [38.5, 39.3, 41.2, 44.7, 49.9, 55.5, 61.6, 67.7, 73.7],
            [41.4, 41.9, 43.8, 47.2, 52.3, 58.0, 64.0, 70.0, 76.1],
            ],
            [
            [41.5, 44.9, 50.0, 55.3, 61.2, 67.2, 73.2, 79.3, 85.3],
            [42.7, 46.5, 51.3, 56.9, 62.9, 68.8, 74.8, 80.8, 86.8],
            [46.2, 50.0, 55.0, 60.6, 66.5, 72.4, 78.4, 84.4, 90.4],
            [38.9, 41.7, 45.7, 51.1, 56.9, 62.8, 68.9, 74.9, 80.9],
            [38.5, 39.2, 41.2, 44.6, 49.9, 55.5, 61.6, 67.6, 73.7],
            [41.4, 41.9, 43.8, 47.2, 52.2, 58.0, 64.0, 70.0, 76.1],
            ]
        ])

        self.Day1_Miniso1_Down = np.array([
            [
            [85.3, 79.3, 73.2, 67.2, 61.2, 55.4, 49.8, 44.9, 41.2],
            [86.8, 80.8, 74.8, 68.8, 62.8, 57.0, 51.3, 46.4, 42.5],
            [90.3, 84.3, 78.4, 72.4, 66.4, 60.5, 54.9, 50.0, 46.1],
            [80.9, 74.9, 68.9, 62.9, 56.9, 51.0, 45.8, 41.5, 39.3],
            [73.7, 67.7, 61.6, 55.5, 49.8, 44.7, 41.1, 39.3, 38.4],
            [76.1, 70.0, 64.0, 58.0, 52.3, 47.3, 43.8, 42.0, 41.2],
            ],
            [
            [85.3, 79.3, 73.3, 67.3, 61.2, 55.4, 49.8, 44.9, 41.6],
            [86.8, 80.8, 74.8, 68.8, 62.8, 57.0, 51.5, 46.3, 42.6],
            [90.4, 84.4, 78.4, 72.4, 66.5, 60.6, 55.0, 50.0, 46.2],
            [80.9, 74.9, 68.9, 62.8, 56.8, 51.0, 46.0, 41.7, 39.1],
            [73.7, 67.7, 61.6, 55.5, 49.8, 44.7, 41.1, 39.4, 38.5],
            [76.1, 70.0, 64.0, 58.0, 52.4, 47.4, 43.8, 42.0, 41.4],
            ],
            [
            [85.3, 79.3, 73.3, 67.2, 61.2, 55.4, 49.9, 44.9, 41.5],
            [86.6, 80.8, 74.8, 68.8, 62.9, 56.9, 51.5, 46.4, 42.7],
            [90.4, 84.4, 78.4, 72.4, 66.5, 60.6, 54.9, 50.0, 46.2],
            [80.9, 74.9, 68.9, 62.8, 56.8, 51.0, 45.9, 41.5, 39.0],
            [73.3, 67.6, 61.6, 55.5, 49.7, 44.8, 41.0, 39.3, 38.5],
            [76.1, 70.0, 64.0, 58.0, 52.3, 47.4, 43.8, 42.0, 41.2],
            ]
        ])

        self.Day1_Miniso2_Up = np.array([
            [
            [41.0, 44.5, 49.2, 54.7, 60.6, 66.6, 72.7, 78.7, 84.7],
            [42.3, 46.0, 50.8, 56.5, 62.4, 68.3, 74.3, 80.4, 86.4],
            [45.8, 49.6, 54.4, 60.0, 65.9, 71.9, 77.9, 83.9, 89.9],
            [38.4, 41.1, 45.1, 50.3, 56.0, 62.0, 68.1, 74.1, 80.2],
            [38.0, 39.2, 40.5, 44.2, 49.2, 55.0, 61.0, 67.0, 73.1],
            [41.2, 41.8, 43.3, 46.6, 51.5, 57.1, 63.1, 69.1, 75.1],
            ],
            [
            [41.1, 44.5, 49.2, 54.9, 60.6, 66.6, 72.7, 78.7, 84.7],
            [42.3, 46.0, 50.8, 56.5, 62.3, 68.3, 74.3, 80.4, 86.4],
            [45.8, 49.5, 54.4, 60.0, 65.9, 71.9, 77.9, 83.9, 89.9],
            [38.5, 41.2, 45.1, 50.3, 56.0, 62.1, 68.1, 74.1, 80.2],
            [38.3, 39.3, 40.8, 44.1, 49.2, 54.9, 61.0, 67.0, 73.1],
            [41.3, 41.9, 43.4, 46.6, 51.5, 57.1, 63.1, 69.1, 75.0],
            ],
            [
            [41.0, 44.5, 49.2, 54.8, 60.7, 66.7, 72.7, 78.7, 84.7],
            [42.3, 45.9, 50.9, 56.5, 62.3, 68.3, 74.3, 80.4, 86.4],
            [45.9, 49.5, 54.4, 60.1, 66.0, 72.0, 77.9, 83.9, 89.9],
            [38.6, 41.2, 45.1, 50.3, 56.1, 62.1, 68.1, 74.1, 80.2],
            [38.3, 39.3, 41.0, 44.1, 49.3, 55.0, 61.0, 67.0, 73.1],
            [41.3, 41.9, 43.3, 46.6, 51.5, 57.1, 63.1, 69.1, 75.1],
            ]
        ])

        self.Day1_Miniso2_Down = np.array([
            [
            [84.7, 78.7, 72.7, 66.6, 60.6, 54.7, 49.1, 44.6, 41.0],
            [86.4, 80.4, 74.4, 68.3, 62.4, 56.5, 50.9, 45.9, 42.2],
            [89.9, 83.9, 77.9, 71.9, 65.9, 60.0, 54.4, 49.5, 45.6],
            [80.2, 74.1, 68.1, 62.1, 56.1, 50.4, 45.2, 41.1, 38.6],
            [73.1, 67.1, 61.0, 55.0, 49.3, 44.2, 40.6, 39.0, 38.2],
            [75.1, 69.1, 63.1, 57.1, 51.5, 46.6, 43.3, 41.8, 41.2],
            ],
            [
            [84.7, 78.7, 72.7, 66.7, 60.7, 54.9, 49.3, 44.6, 41.0],
            [86.4, 80.4, 74.3, 68.3, 62.4, 56.5, 50.9, 45.9, 42.2],
            [89.9, 83.9, 77.9, 71.9, 66.0, 60.0, 54.4, 49.5, 45.7],
            [80.2, 74.1, 68.1, 62.1, 56.1, 50.3, 45.2, 41.1, 38.7],
            [73.1, 67.0, 61.0, 55.0, 49.4, 44.3, 40.7, 39.2, 38.3],
            [75.1, 69.1, 63.1, 57.1, 51.4, 46.6, 43.4, 41.7, 41.3],
            ],
            [
            [84.7, 78.7, 72.7, 66.6, 60.6, 54.9, 49.3, 44.7, 41.0],
            [86.4, 80.4, 74.4, 68.3, 62.3, 56.4, 50.8, 45.8, 42.0],
            [89.9, 83.9, 77.9, 71.9, 66.0, 60.0, 54.5, 49.5, 45.7],
            [80.2, 74.1, 68.1, 62.1, 56.1, 50.4, 45.1, 41.1, 38.5],
            [73.1, 67.0, 61.0, 55.0, 49.2, 44.2, 40.8, 39.1, 38.3],
            [75.1, 69.1, 63.1, 57.1, 51.5, 46.5, 43.4, 41.6, 41.4],
            ]
        ])

        # Day 2
        self.Day2_Bose1_Up = np.array([
            [
            [35.1, 36.5, 40.1, 45.2, 50.7, 56.5, 62.6, 68.7, 74.8],
            [35.5, 37.3, 41.4, 46.3, 52.0, 58.0, 64.0, 70.1, 76.2],
            [39.2, 42.3, 46.7, 52.3, 58.1, 64.1, 70.1, 76.2, 82.2],
            [36.7, 38.4, 41.2, 45.7, 51.3, 57.3, 63.3, 69.3, 75.4],
            [41.4, 43.8, 48.2, 53.4, 59.2, 65.2, 71.2, 77.2, 83.3],
            [42.2, 43.5, 46.3, 50.9, 56.5, 62.3, 68.4, 74.4, 80.4],
            ],
            [
            [34.9, 36.7, 40.3, 45.0, 50.6, 56.6, 62.6, 68.7, 74.8],
            [35.4, 37.2, 41.4, 46.4, 52.0, 57.9, 64.1, 70.1, 76.2],
            [39.0, 42.1, 46.7, 52.3, 58.1, 64.1, 70.1, 76.2, 82.2],
            [36.7, 38.3, 41.2, 45.6, 51.3, 57.2, 63.3, 69.3, 75.4],
            [41.5, 43.8, 48.1, 53.4, 59.2, 65.2, 71.2, 77.2, 83.3],
            [42.0, 43.3, 46.5, 51.0, 56.5, 62.3, 68.4, 74.4, 80.4],
            ],
            [
            [35.2, 36.6, 40.6, 45.3, 50.8, 56.6, 62.6, 68.7, 74.8],
            [35.3, 37.2, 41.3, 46.4, 52.1, 58.0, 64.1, 70.1, 76.2],
            [38.9, 42.3, 46.8, 52.3, 58.1, 64.1, 70.1, 76.2, 82.2],
            [36.7, 38.3, 41.4, 45.7, 51.3, 57.3, 63.3, 69.3, 75.4],
            [41.4, 43.7, 48.2, 53.4, 59.2, 65.2, 71.2, 77.2, 83.2],
            [41.9, 43.4, 46.5, 50.9, 56.5, 62.3, 68.4, 74.4, 80.4],
            ]
        ])

        self.Day2_Bose1_Down = np.array([
            [
            [74.8, 68.7, 62.6, 56.6, 50.6, 45.2, 39.9, 36.7, 34.9], 
            [76.2, 70.1, 64.0, 57.9, 51.9, 46.4, 41.4, 37.4, 35.2], 
            [82.2, 76.2, 70.1, 64.1, 58.0, 52.2, 46.8, 42.2, 38.8], 
            [75.4, 69.3, 63.3, 57.3, 51.3, 45.8, 41.3, 38.4, 36.5], 
            [83.3, 77.2, 71.2, 65.2, 59.2, 53.5, 48.2, 44.1, 41.6], 
            [80.4, 74.4, 68.4, 62.3, 56.5, 50.8, 46.5, 43.5, 42.1], 
            ], 
            [
            [74.8, 68.7, 62.6, 56.6, 50.7, 45.3, 40.0, 36.8, 35.0], 
            [76.2, 70.1, 64.0, 58.0, 52.1, 46.4, 41.3, 37.5, 35.2], 
            [82.2, 76.2, 70.1, 64.1, 58.1, 52.3, 46.8, 42.2, 39.0], 
            [75.4, 69.3, 63.3, 57.2, 51.4, 45.6, 41.3, 38.4, 36.7], 
            [83.3, 77.2, 71.2, 65.2, 59.2, 53.4, 48.1, 43.9, 41.5], 
            [80.4, 74.4, 68.4, 62.4, 56.5, 50.9, 46.3, 43.5, 42.0], 
            ], 
            [
            [74.8, 68.7, 62.6, 56.6, 50.7, 45.2, 40.4, 36.8, 35.1], 
            [76.2, 70.1, 64.1, 58.0, 52.0, 46.6, 41.3, 37.4, 35.4], 
            [82.2, 76.2, 70.1, 64.1, 58.1, 52.3, 46.7, 42.3, 39.0], 
            [75.4, 69.3, 63.3, 57.2, 51.4, 45.9, 41.3, 38.3, 36.6], 
            [83.2, 77.2, 71.2, 65.2, 59.2, 53.4, 48.1, 43.9, 41.4], 
            [80.4, 74.4, 68.4, 62.3, 56.5, 50.9, 46.5, 43.5, 42.1], 
            ]
        ])

        self.Day2_Bose2_Up = np.array([
            [
            [34.9, 36.0, 40.2, 45.1, 50.8, 56.5, 62.5, 68.7, 74.7],
            [35.4, 37.3, 41.3, 46.4, 51.9, 57.8, 63.9, 70.0, 76.0],
            [38.5, 42.1, 46.4, 52.0, 57.9, 63.8, 69.9, 75.9, 81.9],
            [36.5, 38.1, 41.0, 45.4, 51.0, 56.9, 63.0, 69.0, 75.1],
            [41.4, 43.8, 47.8, 53.2, 59.0, 65.0, 71.0, 77.1, 83.1],
            [41.9, 43.2, 46.2, 50.4, 56.0, 61.8, 67.9, 73.9, 79.9],
            ],
            [
            [34.8, 36.0, 40.0, 45.0, 50.6, 56.4, 62.5, 68.6, 74.7],
            [35.2, 37.4, 41.3, 46.2, 51.7, 57.8, 63.9, 69.9, 76.0],
            [38.6, 41.9, 46.3, 51.9, 57.8, 63.8, 69.9, 75.9, 81.9],
            [36.5, 38.0, 41.0, 45.5, 51.2, 57.0, 63.0, 69.0, 75.1],
            [41.4, 44.0, 47.9, 53.3, 59.0, 65.0, 71.0, 77.1, 83.1],
            [42.0, 43.1, 46.0, 50.6, 56.0, 61.8, 67.9, 73.9, 79.8],
            ],
            [
            [35.0, 36.4, 40.3, 45.3, 50.5, 56.3, 62.5, 68.5, 74.6],
            [35.3, 37.5, 41.2, 46.1, 51.9, 57.8, 63.9, 70.0, 76.0],
            [38.7, 42.0, 46.4, 52.1, 57.8, 63.8, 69.9, 75.9, 81.9],
            [36.7, 37.8, 40.8, 45.7, 51.0, 56.9, 63.0, 69.0, 75.1],
            [41.6, 43.9, 48.0, 53.3, 59.0, 65.0, 71.0, 77.1, 83.1],
            [41.8, 43.2, 45.9, 50.5, 56.0, 61.9, 67.9, 73.9, 79.8],
            ]
        ])

        self.Day2_Bose2_Down = np.array([
            [
            [74.7, 68.6, 62.6, 56.5, 50.7, 45.2, 40.4, 36.0, 34.8],
            [76.0, 70.0, 63.9, 57.9, 51.8, 46.3, 41.2, 37.2, 35.2],
            [81.9, 75.9, 69.9, 63.8, 57.8, 52.0, 46.4, 42.0, 38.6],
            [75.1, 69.0, 63.0, 57.0, 51.1, 45.6, 40.8, 38.1, 36.6],
            [83.1, 77.1, 71.0, 65.0, 59.0, 53.3, 47.8, 43.9, 41.3],
            [79.8, 73.9, 67.9, 61.8, 56.1, 50.5, 46.1, 43.2, 42.0],
            ],
            [
            [74.6, 68.6, 62.5, 56.3, 50.5, 44.8, 40.6, 36.3, 34.7],
            [76.0, 70.0, 63.9, 57.8, 51.9, 46.3, 40.9, 37.2, 34.9],
            [81.9, 75.9, 69.9, 63.8, 57.9, 52.0, 46.7, 41.8, 38.5],
            [75.1, 69.0, 66.0, 56.9, 51.1, 45.4, 41.0, 38.0, 36.8],
            [83.1, 77.1, 71.1, 65.0, 59.1, 53.2, 48.0, 43.8, 41.4],
            [79.8, 73.9, 67.9, 61.9, 56.0, 50.5, 46.1, 43.1, 42.0],
            ],
            [
            [74.6, 68.6, 62.5, 56.4, 50.4, 44.8, 40.7, 36.5, 34.9],
            [76.0, 70.0, 63.9, 57.8, 51.9, 46.2, 41.0, 37.4, 35.1],
            [81.9, 75.9, 69.9, 63.8, 57.8, 52.0, 46.6, 42.0, 38.7],
            [75.1, 69.0, 63.0, 56.9, 51.1, 45.6, 41.0, 37.9, 36.8],
            [83.1, 77.0, 71.0, 65.0, 59.1, 53.4, 48.0, 43.8, 41.4],
            [79.8, 73.9, 67.8, 61.8, 56.0, 50.6, 46.0, 43.0, 41.8],
            ]
        ])

        self.Day2_Miniso1_Up = np.array([
            [
            [41.6, 44.9, 50.0, 55.4, 61.2, 67.2, 73.2, 79.2, 85.2],
            [42.6, 46.4, 51.4, 57.0, 63.0, 68.9, 74.8, 80.9, 86.9],
            [46.6, 50.2, 55.2, 60.8, 66.7, 72.7, 78.7, 84.7, 90.7],
            [38.9, 41.5, 45.6, 50.7, 56.7, 62.6, 68.7, 74.7, 80.7],
            [38.2, 39.1, 41.0, 44.7, 49.6, 55.4, 61.5, 67.6, 73.6],
            [41.3, 41.8, 44.0, 47.4, 52.6, 58.3, 64.3, 70.3, 76.4],
            ],
            [
            [41.6, 44.9, 49.8, 55.5, 61.3, 67.2, 73.2, 79.2, 85.2],
            [42.6, 46.5, 51.6, 57.0, 62.9, 68.9, 74.9, 80.9, 86.9],
            [46.6, 50.2, 55.2, 60.9, 66.7, 72.7, 78.7, 84.7, 90.7],
            [39.0, 41.6, 45.7, 50.8, 56.7, 62.6, 68.7, 74.7, 80.7],
            [38.3, 39.0, 41.0, 44.7, 49.6, 55.5, 61.5, 67.6, 73.6],
            [41.4, 42.0, 43.9, 47.4, 52.5, 58.2, 64.2, 70.3, 76.4],
            ],
            [
            [41.4, 45.1, 50.0, 55.3, 61.2, 67.2, 73.2, 79.2, 85.2],
            [42.7, 46.6, 51.3, 57.0, 62.9, 68.9, 74.9, 80.9, 86.9],
            [46.5, 50.1, 55.2, 60.8, 66.7, 72.7, 78.7, 84.7, 90.7],
            [38.9, 41.6, 45.6, 50.8, 56.6, 62.6, 68.6, 74.7, 80.7],
            [38.4, 39.2, 41.0, 44.7, 49.7, 55.4, 61.5, 67.6, 73.6],
            [41.3, 41.9, 43.7, 47.3, 52.4, 58.2, 64.2, 70.2, 76.3],
            ]
        ])

        self.Day2_Miniso1_Down = np.array([
            [
            [85.2, 79.2, 73.2, 67.2, 61.3, 55.3, 49.9, 45.1, 41.4],
            [86.9, 80.9, 74.9, 68.8, 62.9, 57.0, 51.4, 46.5, 42.7],
            [90.7, 84.7, 78.7, 72.7, 66.8, 60.8, 55.3, 50.3, 46.6],
            [80.7, 74.7, 68.7, 62.7, 56.7, 50.8, 45.7, 41.5, 38.9],
            [73.6, 67.6, 61.5, 55.4, 49.7, 44.7, 41.0, 39.2, 38.2],
            [76.4, 70.3, 64.3, 58.3, 52.6, 47.4, 44.0, 41.9, 41.2],
            ],
            [
            [85.2, 79.2, 73.2, 67.2, 61.3, 55.5, 50.0, 44.8, 41.5],
            [86.9, 80.9, 74.9, 68.9, 62.9, 57.0, 51.5, 46.5, 42.7],
            [90.7, 84.7, 78.7, 72.7, 66.7, 60.8, 55.2, 50.3, 46.4],
            [80.7, 74.7, 68.7, 62.6, 56.7, 50.8, 45.7, 41.5, 38.9],
            [73.6, 67.6, 61.5, 55.4, 49.8, 44.5, 41.2, 39.4, 38.4],
            [76.3, 70.3, 64.2, 58.2, 52.6, 47.4, 44.0, 41.9, 41.3],
            ],
            [
            [85.2, 79.2, 73.2, 67.2, 61.2, 55.3, 50.0, 44.9, 41.5],
            [86.9, 80.9, 74.9, 68.9, 62.9, 57.0, 51.5, 46.3, 42.8],
            [90.7, 84.7, 78.7, 72.7, 66.7, 60.8, 55.2, 50.2, 46.4],
            [80.7, 74.7, 68.7, 62.6, 56.6, 51.0, 45.8, 41.4, 39.1],
            [73.6, 67.6, 61.5, 55.4, 49.8, 44.6, 41.0, 39.2, 38.4],
            [76.3, 70.2, 64.2, 58.2, 52.6, 47.3, 44.0, 41.9, 41.3],
            ]
        ])

        self.Day2_Miniso2_Up = np.array([
            [
            [41.4, 44.5, 49.2, 54.8, 60.8, 66.8, 72.8, 78.8, 84.8],
            [42.4, 45.8, 50.9, 56.5, 62.4, 68.4, 74.4, 80.4, 86.4],
            [45.9, 50.0, 54.9, 60.6, 66.4, 72.4, 78.4, 84.4, 90.4],
            [38.3, 41.2, 45.2, 50.3, 56.1, 62.1, 68.1, 74.2, 80.2],
            [38.0, 39.2, 40.9, 44.4, 49.3, 55.0, 61.1, 67.2, 73.2],
            [41.3, 41.7, 43.4, 46.7, 51.9, 57.4, 63.4, 69.5, 75.4],
            ],
            [
            [41.4, 44.6, 49.2, 54.9, 60.7, 66.8, 72.8, 78.8, 84.8],
            [42.7, 45.9, 50.8, 56.6, 62.5, 68.4, 74.4, 80.5, 86.4],
            [46.2, 50.0, 54.9, 60.5, 66.4, 72.4, 78.4, 84.4, 90.4],
            [38.4, 41.2, 45.2, 50.3, 56.1, 62.1, 68.1, 74.2, 80.2],
            [38.2, 39.2, 40.8, 44.3, 49.3, 55.0, 61.0, 67.1, 73.2],
            [41.2, 41.8, 43.4, 46.8, 51.7, 57.4, 63.4, 69.4, 75.4],
            ],
            [
            [41.4, 44.6, 49.3, 54.9, 60.8, 66.8, 72.8, 78.8, 84.8],
            [42.5, 45.9, 50.9, 56.6, 62.5, 68.4, 74.4, 80.5, 86.4],
            [46.3, 50.0, 54.9, 60.6, 66.4, 72.4, 78.4, 84.4, 90.4],
            [38.4, 41.1, 45.1, 50.4, 56.0, 62.1, 68.1, 74.2, 80.2],
            [38.3, 39.2, 40.9, 44.2, 49.2, 55.0, 61.1, 67.1, 73.2],
            [41.4, 42.0, 43.4, 46.8, 51.7, 57.4, 63.4, 69.4, 75.4],
            ]
        ])

        self.Day2_Miniso2_Down = np.array([
            [
            [84.8, 78.8, 72.8, 66.8, 60.8, 54.8, 49.3, 44.7, 41.3],
            [86.4, 80.5, 74.4, 68.4, 62.5, 56.6, 50.9, 46.0, 42.2],
            [90.4, 84.4, 78.4, 72.4, 66.4, 60.5, 54.9, 49.8, 46.1],
            [80.2, 74.2, 68.1, 62.1, 56.1, 50.4, 45.2, 40.8, 38.6],
            [73.2, 67.1, 61.1, 55.0, 49.2, 44.4, 41.0, 39.0, 38.3],
            [75.4, 69.4, 63.5, 57.5, 51.8, 46.8, 43.3, 41.8, 41.2],
            ],
            [
            [84.8, 78.8, 72.8, 66.8, 60.8, 54.9, 49.3, 44.6, 41.1],
            [86.4, 80.5, 74.4, 68.4, 62.5, 56.5, 51.0, 46.2, 42.4],
            [90.4, 84.4, 78.4, 72.4, 66.4, 60.5, 54.9, 50.0, 46.0],
            [80.2, 74.2, 68.1, 62.1, 56.1, 50.3, 45.3, 41.0, 38.6],
            [73.2, 67.1, 61.1, 55.1, 49.3, 44.5, 41.0, 39.1, 38.4],
            [75.4, 69.4, 63.4, 57.4, 51.8, 46.7, 43.5, 41.7, 41.3],
            ],
            [
            [84.8, 78.8, 72.8, 66.8, 60.8, 54.9, 49.6, 44.7, 41.2],
            [86.4, 80.5, 74.4, 68.4, 62.5, 56.6, 51.1, 46.0, 42.3],
            [90.4, 84.4, 78.4, 72.4, 66.4, 60.5, 54.8, 50.0, 46.2],
            [80.2, 74.2, 68.1, 62.1, 56.1, 50.4, 45.3, 41.1, 38.6],
            [73.2, 67.1, 61.1, 55.1, 49.3, 44.4, 40.9, 39.1, 38.3],
            [75.4, 69.4, 63.4, 57.4, 51.8, 46.8, 43.4, 41.8, 41.3],
            ]
        ])
