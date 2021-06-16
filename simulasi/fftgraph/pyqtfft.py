#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import matplotlib
import numpy as np
import sounddevice as sd
from scipy import fftpack

matplotlib.use('Qt5Agg')

from PyQt5 import QtCore, QtWidgets
from PyQt5.QtCore import QThread, pyqtSignal

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

class Audio(QThread):

	dbSPL = pyqtSignal(int)
	spl_L = 0
	spl_R = 0
	freqs = 0
	fs = 44100

	def print_level(self,indata, frames, time, status):
		self.spl_L = fftpack.fft(indata[:,0])
		self.spl_R = fftpack.fft(indata[:,1])
		self.freqs = fftpack.fftfreq(len(indata[:,0])) * self.fs

		vol_norm = int(np.linalg.norm(indata))
		self.dbSPL.emit(vol_norm)

	def run(self):
		with sd.InputStream(callback=self.print_level):
			print("input capture started")
			while True:
				pass

class MplCanvas(FigureCanvasQTAgg):

	def __init__(self, parent=None, width=5, height=4, dpi=100):
		fig = plt.figure(figsize=(8,4), facecolor='#DEDEDE')

		self.axL = plt.subplot(211)
		self.axL.set_facecolor('#DEDEDE')
		self.axL.grid(True,which='both',ls='-')
		self.axL.set_xlim([32,10000])
		self.axL.set_ylim([0.1,1000])
		self.lineL, = self.axL.loglog([1])

		self.axR = plt.subplot(212)
		self.axR.set_facecolor('#DEDEDE')
		self.axR.grid(True,which='both',ls='-')
		self.axR.set_xlim([32,10000])
		self.axR.set_ylim([0.1,1000])
		self.lineR, = self.axR.loglog([1])

		ani = FuncAnimation(fig, None, interval=1)

		super(MplCanvas, self).__init__(fig)

class MainUI(QtWidgets.QMainWindow):

	def __init__(self, *args, **kwargs):
		super(MainUI, self).__init__(*args, **kwargs)

		sd.default.device = 2, None
		sd.default.channels = 2, None
		print(sd.query_devices())

		# Create the maptlotlib FigureCanvas object,
		# which defines a single set of axes as self.axes.
		self.sc = MplCanvas(self, width=5, height=4, dpi=100)
		self.setCentralWidget(self.sc)

		self.spl = Audio()
		self.spl.dbSPL.connect(self.onSPLchanged)
		self.spl.start()

		self.show()

	def onSPLchanged(self,value):
		spl_avg = value
		self.sc.lineL.set_data(self.spl.freqs, np.abs(self.spl.spl_L))
		self.sc.lineR.set_data(self.spl.freqs, np.abs(self.spl.spl_R))

app = QtWidgets.QApplication(sys.argv)
w = MainUI()
app.exec_()
