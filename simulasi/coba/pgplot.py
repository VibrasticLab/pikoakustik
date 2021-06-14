#!/usr/bin/python3
# -*- coding: utf-8 -*-

from PyQt5 import QtWidgets, QtCore
import pyqtgraph as pg
import sys

from random import randint

class MainUI(QtWidgets.QMainWindow):
    """description"""

    def __init__(self):
        super().__init__()

        self.graphWidget = pg.PlotWidget()
        self.setCentralWidget(self.graphWidget)

        self.x = list(range(100))
        self.y = [randint(0,100) for _ in range(100)]

        self.graphWidget.setBackground('w')

        pen = pg.mkPen(color=(0,0,0),width=2)
        self.data_line = self.graphWidget.plot(self.x, self.y, pen=pen)

        self.tmr = QtCore.QTimer()
        self.tmr.setInterval(50)
        self.tmr.timeout.connect(self.update_plot)
        self.tmr.start()

    def update_plot(self):
        self.x = self.x[1:]
        self.x.append(self.x[-1]+1)

        self.y = self.y[1:]
        self.y.append(randint(0,100))

        self.data_line.setData(self.x, self.y)

app = QtWidgets.QApplication(sys.argv)
wn = MainUI()
wn.show()
sys.exit(app.exec_())
