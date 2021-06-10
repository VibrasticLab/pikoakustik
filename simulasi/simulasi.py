#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  audiobar.py
#
#  Copyright 2021 achmaday <achmaday@archmate>
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#
#

import sys
import numpy as np
import sounddevice as sd

from PyQt5.QtCore import QThread, pyqtSignal
from PyQt5.QtWidgets import QApplication, QDialog, QProgressBar, QPushButton

class Audio(QThread):

    dbSPL = pyqtSignal(int)
    vol_normL = 0
    vol_normR = 0
    gain = 100

    def print_level(self,indata, frames, time, status):
        self.vol_normL = int(np.linalg.norm(indata[:,0])*self.gain)
        self.vol_normR = int(np.linalg.norm(indata[:,1])*self.gain)
        vol_norm = int(np.linalg.norm(indata)*self.gain)
        self.dbSPL.emit(vol_norm)

    def run(self):
        with sd.InputStream(callback=self.print_level):
            print("input capture started")
            while True:
                pass
            print("input capture finished")

class Actions(QDialog):
    """docstring for Actions"""
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Audio Bar')
        self.vbarL = QProgressBar(self)
        self.vbarL.setGeometry(0,0,300,25)
        self.vbarL.setMaximum(100)

        self.vbarR = QProgressBar(self)
        self.vbarR.setGeometry(0,0,300,25)
        self.vbarR.setMaximum(100)
        self.vbarR.move(0, 30)

        self.show()

        sd.default.device = 2, None
        sd.default.channels = 2, None
        print(sd.query_devices())

        self.spl = Audio()
        self.spl.dbSPL.connect(self.onSPLchanged)
        self.spl.start()

    def onSPLchanged(self,value):
        spl_avg = value
        self.vbarL.setValue(self.spl.vol_normL)
        self.vbarR.setValue(self.spl.vol_normR)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    wndw = Actions()
    sys.exit(app.exec_())
