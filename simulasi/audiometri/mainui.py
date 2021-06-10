#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
from PyQt5.QtWidgets import QDialog,QApplication,QProgressBar,QGroupBox,QVBoxLayout
from PyQt5.QtWidgets import QGridLayout

from audiocap import AudioCapture

class MainUI(QDialog):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Audiometri Simulator')

        # Audio Level
        self.grpAudioLevel = QGroupBox("Audio Level")

        self.barAudioL = QProgressBar()
        self.barAudioL.setGeometry(0,0,300,25)
        self.barAudioL.setMaximum(100)

        self.barAudioR = QProgressBar()
        self.barAudioR.setGeometry(0,0,300,25)
        self.barAudioR.setMaximum(100)

        self.vboxAudioLevel = QVBoxLayout()
        self.vboxAudioLevel.addWidget(self.barAudioL)
        self.vboxAudioLevel.addWidget(self.barAudioR)
        self.vboxAudioLevel.addStretch(1)

        self.grpAudioLevel.setLayout(self.vboxAudioLevel)

        # Main Grid
        gridMain = QGridLayout()
        gridMain.addWidget(self.grpAudioLevel,0,0)
        self.setLayout(gridMain)

        self.resize(400,300)

        # Run other threads
        self.splcap = AudioCapture()
        self.splcap.dbSPL.connect(self.onSPLchanged)
        self.splcap.start()

        # last show
        self.show()

    def onSPLchanged(self,value):
        splavg = value
        self.barAudioL.setValue(self.splcap.vol_normL)
        self.barAudioR.setValue(self.splcap.vol_normR)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    win_app = MainUI()
    sys.exit(app.exec_())
