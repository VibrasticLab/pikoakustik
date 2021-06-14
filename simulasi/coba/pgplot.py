#!/usr/bin/python3
# -*- coding: utf-8 -*-

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
    freqs = []

    def get_fft(self,indata,frames,time,status):
        self.fft_L = np.abs(np.fft.fft(indata[:,0]))
        self.freqs = np.fft.fftfreq(len(indata[:,0])) * self.fs

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

        self.graphWidget = pg.PlotWidget()
        self.setCentralWidget(self.graphWidget)

        self.graphWidget.setBackground('w')

        pen = pg.mkPen(color=(0,0,0),width=2)
        self.graphWidget.showGrid(x=True,y=True)
        self.graphWidget.setLogMode(x=True)
        self.graphWidget.enableAutoRange(axis='y')
        self.graphWidget.setYRange(0,24)
        self.graphWidget.setXRange(2,4)
        self.data_line = self.graphWidget.plot(pen=pen)

        sd.default.device = 2, None
        sd.default.channels = 2, None
        #print(sd.query_devices())

        self.spl = Audio()
        self.spl.dbSPL.connect(self.update_plot)
        self.spl.start()

    def update_plot(self,value):
        volnorm = value
        try:
            self.data_line.setData(self.spl.freqs, self.spl.fft_L)
        except:
            pass

app = QtWidgets.QApplication(sys.argv)
wn = MainUI()
wn.show()
sys.exit(app.exec_())
