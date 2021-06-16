#!/usr/bin/env python
# -*- coding: utf-8 -*-

import pyfftw.interfaces.numpy_fft as fftw
from PyQt5 import QtWidgets, QtCore
import sounddevice as sd
import pyqtgraph as pg
import numpy as np
import sys

import warnings
warnings.filterwarnings("ignore")

class Audio(QtCore.QThread):

    dbSPL = QtCore.pyqtSignal(int)
    fs = 44100
    fft_L = []
    fft_R = []
    freqs = []

    def get_fft(self,indata,frames,time,status):
        self.fft_L = np.abs(fftw.fft(indata[:,0]))
        self.fft_R = np.abs(fftw.fft(indata[:,1]))
        self.freqs = fftw.fftfreq(len(indata[:,0])) * self.fs

        volnorm = int(np.linalg.norm(indata))
        self.dbSPL.emit(volnorm)

    def run(self):
        with sd.InputStream(callback=self.get_fft):
            print("input capture started")
            while True:
                pass

class MainUI(QtWidgets.QMainWindow):
    """description"""

    def __init__(self):
        super().__init__()

        win = QtWidgets.QWidget()
        vBoxLayout = QtWidgets.QVBoxLayout()
        vBoxLayout.addStretch(1)

        graphWidgetL = pg.PlotWidget()
        graphWidgetL.setGeometry(100, 100, 600, 300)
        graphWidgetL.setBackground('w')
        graphWidgetL.showGrid(x=True,y=True)
        graphWidgetL.setLogMode(x=True,y=True)
        graphWidgetL.setYRange(-2,3)
        graphWidgetL.setXRange(2,4)
        vBoxLayout.addWidget(graphWidgetL)

        graphWidgetR = pg.PlotWidget()
        graphWidgetR.setGeometry(100, 100, 600, 300)
        graphWidgetR.setBackground('w')
        graphWidgetR.showGrid(x=True,y=True)
        graphWidgetR.setLogMode(x=True,y=True)
        graphWidgetR.setYRange(-2,3)
        graphWidgetR.setXRange(2,4)
        vBoxLayout.addWidget(graphWidgetR)

        win.setLayout(vBoxLayout)
        self.setCentralWidget(win)

        penL = pg.mkPen(color=(255,0,0),width=2)
        self.data_lineL = graphWidgetL.plot(pen=penL)

        penR = pg.mkPen(color=(0,0,255),width=2)
        self.data_lineR = graphWidgetR.plot(pen=penR)

        sd.default.device = 2, None
        sd.default.channels = 2, None
        print(sd.query_devices())

        self.spl = Audio()
        self.spl.dbSPL.connect(self.update_plot)
        self.spl.start()

    def update_plot(self,value):
        volnorm = value
        try:
            self.data_lineL.setData(self.spl.freqs, self.spl.fft_L)
            self.data_lineR.setData(self.spl.freqs, self.spl.fft_R)
        except:
            pass

app = QtWidgets.QApplication(sys.argv)
wn = MainUI()
wn.show()
sys.exit(app.exec_())
