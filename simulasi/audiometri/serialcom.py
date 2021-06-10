#!/usr/bin/python3

import serial
from serial.serialposix import Serial

class SerialComm():

    sercom = None

    def SerComStart(self):
        self.sercom = serial.Serial('/dev/ttyACM0',9600,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                rtscts=False,dsrdtr=False
                )
    def SerComStop(self):
        self.sercom.close()

    def TestComm(self):
        self.SerComStart()
        self.sercom.write(b'out 500 9\r\n')

