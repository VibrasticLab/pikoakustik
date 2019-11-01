#!/usr/bin/python2

import os
import sys
import time
import serial

try:
	import pygtk
	pygtk.require('2.0')
except:
	pass

try:
	import gtk
	import gtk.glade
except:
	sys.exit(1)

class SerialTest:

	def __init__(self):
		dirpath = os.path.dirname(os.path.realpath(__file__)) + '/'

		gui = gtk.Builder()
		gui.add_from_file(dirpath + 'SerialTest.glade')
		gui.connect_signals(self)

		win = gui.get_object('winApp')
		win.set_default_size(300,150)
		win.set_position(gtk.WIN_POS_CENTER)
		win.connect('destroy',self.on_destroy)

		self.devAddr = '/dev/tty'
		cmbDev = gui.get_object('cmbDev')
		cmbDevCell = gtk.CellRendererText()
		cmbDevList = gtk.ListStore(str)
		cmbDevList.append(['Select Device Port'])
		cmbDevList.append(['/dev/ttyUSB0'])
		cmbDevList.append(['/dev/ttyUSB1'])
		cmbDevList.append(['/dev/ttyUSB2'])
		cmbDevList.append(['/dev/ttyACM0'])
		cmbDevList.append(['/dev/ttyACM1'])
		cmbDevList.append(['/dev/ttyACM2'])
		cmbDev.set_model(cmbDevList)
		cmbDev.pack_start(cmbDevCell)
		cmbDev.set_attributes(cmbDevCell,text=0)
		cmbDev.set_active(0)
		cmbDev.connect('changed', self.on_dev_changed)

		self.Freq = 0
		cmbFreq = gui.get_object('cmbFreq')
		cmbFreqCell = gtk.CellRendererText()
		cmbFreqList = gtk.ListStore(str)
		cmbFreqList.append(['1'])
		cmbFreqList.append(['2'])
		cmbFreqList.append(['4'])
		cmbFreqList.append(['8'])
		cmbFreqList.append(['16'])
		cmbFreqList.append(['32'])
		cmbFreq.set_model(cmbFreqList)
		cmbFreq.pack_start(cmbFreqCell)
		cmbFreq.set_attributes(cmbFreqCell,text=0)
		cmbFreq.set_active(0)
		cmbFreq.connect('changed', self.on_freq_changed)

		self.Ampl = 0
		cmbAmpl = gui.get_object('cmbAmpl')
		cmbAmplCell = gtk.CellRendererText()
		cmbAmplList = gtk.ListStore(str)
		cmbAmplList.append(['0'])
		cmbAmplList.append(['1'])
		cmbAmplList.append(['5'])
		cmbAmplList.append(['10'])
		cmbAmplList.append(['15'])
		cmbAmplList.append(['20'])
		cmbAmpl.set_model(cmbAmplList)
		cmbAmpl.pack_start(cmbAmplCell)
		cmbAmpl.set_attributes(cmbAmplCell,text=0)
		cmbAmpl.set_active(0)
		cmbAmpl.connect('changed', self.on_ampl_changed)

		self.sttConnect = False
		self.ser = serial.Serial()
		self.btnConnect = gui.get_object('btnConnect')
		self.btnConnect.set_label('Connect')
		self.btnConnect.set_sensitive(False)
		self.btnConnect.connect('clicked', self.on_connect_clicked)

		self.testDelay = 5
		self.btnTest = gui.get_object('btnTest')
		self.btnTest.set_sensitive(False)
		self.btnTest.connect('clicked', self.on_test_clicked)

		win.show()

	def on_destroy(self,widget):
		if self.ser.isOpen():
			self.ser.close()
		gtk.main_quit()

	def on_dev_changed(self, widget):
		if widget.get_active() != 0:
			self.devAddr =  widget.get_active_text()
			self.btnConnect.set_sensitive(True)
		else:
			self.btnConnect.set_sensitive(False)

		return

	def on_freq_changed(self, widget):
		self.Freq = widget.get_active()

	def on_ampl_changed(self, widget):
		self.Ampl = widget.get_active()

	def on_connect_clicked(self,widget):
		if self.sttConnect == False:
			try:
				self.ser = serial.Serial(
							port = self.devAddr,
							baudrate = 9600,
							parity=serial.PARITY_NONE,
							stopbits=serial.STOPBITS_ONE,
							bytesize=serial.EIGHTBITS,
							timeout=1)

				self.ser.open()
			except IOError:
				self.ser.close()
				self.ser.open()

			if self.ser.isOpen():
				self.btnTest.set_sensitive(True)
				self.btnConnect.set_label('Disconnect')
				self.sttConnect = True

		elif self.sttConnect == True:
			self.ser.close()
			self.btnTest.set_sensitive(False)
			self.btnConnect.set_label('Connect')
			self.sttConnect = False

	def on_test_clicked(self,widget):
		self.btnTest.set_sensitive(False)
		self.ser.write('play %d %d\r\n' % (self.Freq,self.Ampl))
		time.sleep(self.testDelay/2) # somehow STM32 timer twice faster
		self.btnTest.set_sensitive(True)

if __name__ == '__main__':
	if not os.geteuid()==0:
		sys.exit('This script must be run as root!')

	app = SerialTest()
	gtk.main()
