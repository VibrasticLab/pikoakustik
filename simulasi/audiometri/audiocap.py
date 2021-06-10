#!/usr/bin/python3
# -*- coding: utf-8 -*-

import numpy as np
import sounddevice as sd
from PyQt5.QtCore import QThread,pyqtSignal

class AudioCapture(QThread):
    dbSPL = pyqtSignal(int)
    vol_normL = 0
    vol_normR = 0
    gain = 100

    def get_spl(self,indata,frames,time,status):
        self.vol_normL = int(np.linalg.norm(indata[:,0]) * self.gain)
        self.vol_normR = int(np.linalg.norm(indata[:,1]) * self.gain)
        vol_norm = int(np.linalg.norm(indata) * self.gain)
        self.dbSPL.emit(vol_norm)

    def run(self):
        sd.default.device = 2, None
        sd.default.channels = 2, None

        with sd.InputStream(callback=self.get_spl):
            print("Capture Started")
            while True:
                pass
