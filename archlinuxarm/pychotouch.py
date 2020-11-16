#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import nested_scopes, generators, division, absolute_import, with_statement, print_function, unicode_literals

from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QDialog, QDialogButtonBox, QFileDialog, QPushButton, QScrollArea, QVBoxLayout
import argparse, fnmatch, numpy, os, random, signal, sys, time, traceback
from pychoacoustics import global_parameters
from pychoacoustics.control_window import*

#allows to close the app with CTRL-C from the console
signal.signal(signal.SIGINT, signal.SIG_DFL)
#
import logging
local_dir = os.path.expanduser("~") +'/.local/share/data/pychoacoustics/'
if os.path.exists(local_dir) == False:
    os.makedirs(local_dir)
stderrFile = os.path.expanduser("~") +'/.local/share/data/pychoacoustics/pychoacoustics_stderr_log.txt'

logging.basicConfig(filename=stderrFile,level=logging.DEBUG,)

#the except hook allows to see most startup errors in a window
#rather than the console
def excepthook(except_type, except_val, tbck):
    """ Show errors in message box"""
    # recover traceback
    tb = traceback.format_exception(except_type, except_val, tbck)
    def onClickSaveTbButton():
        ftow = QFileDialog.getSaveFileName(None, 'Choose where to save the traceback', "traceback.txt", 'All Files (*)')[0]
        if len(ftow) > 0:
            if fnmatch.fnmatch(ftow, '*.txt') == False:
                ftow = ftow + '.txt'
            fName = open(ftow, 'w')
            fName.write("".join(tb))
            fName.close()
    
    diag = QDialog(None, Qt.CustomizeWindowHint | Qt.WindowCloseButtonHint)
    diag.window().setWindowTitle("Critical Error!")
    siz = QVBoxLayout()
    lay = QVBoxLayout()
    saveTbButton = QPushButton("Save Traceback", diag)
    saveTbButton.clicked.connect(onClickSaveTbButton)
    lab = QLabel("Sorry, something went wrong. The attached traceback can help you troubleshoot the problem: \n\n" + "".join(tb))
    lab.setMargin(10)
    lab.setWordWrap(True)
    lab.setTextInteractionFlags(Qt.TextSelectableByMouse)
    lab.setStyleSheet("QLabel { background-color: white }");
    lay.addWidget(lab)

    sc = QScrollArea()
    sc.setWidget(lab)
    siz.addWidget(sc)#SCROLLAREA IS A WIDGET SO IT NEEDS TO BE ADDED TO A LAYOUT

    buttonBox = QDialogButtonBox(QDialogButtonBox.Ok|QDialogButtonBox.Cancel)

    buttonBox.accepted.connect(diag.accept)
    buttonBox.rejected.connect(diag.reject)
    siz.addWidget(saveTbButton)
    siz.addWidget(buttonBox)
    diag.setLayout(siz)
    diag.exec_()

    timeStamp = ''+ time.strftime("%d/%m/%y %H:%M:%S", time.localtime()) + ' ' + '\n'
    logMsg = timeStamp + ''.join(tb)
    logging.debug(logMsg)

def main(argv):
    prm = {}
    prm['calledWithPrm'] = False
    prm['calledWithReset'] = False
    prm['calledWithRecursionDepth'] = False
    prm['calledWithAutostart'] = False
    prm['hideWins'] = False
    prm['quit'] = False
    prm['progbar'] = False
    prm['blockProgbar'] = False
    parser = argparse.ArgumentParser()

    parser.add_argument("-f", "--file", help="Load parameters file", nargs='?', const='', default='')
    parser.add_argument("-r", "--results", help="Results file")
    parser.add_argument("-l", "--listener", help="Listener Name")
    parser.add_argument("-s", "--session", help="Session Label")
    parser.add_argument("-c", "--conceal", help="Hide Control and Parameters Windows", action="store_true")
    parser.add_argument("-o", "--minimized", help="Start minimized (useful for testing)", action="store_true")
    parser.add_argument("-p", "--progbar", help="Show the progress bar", action="store_true")
    parser.add_argument("-b", "--blockprogbar", help="Show the block progress bar", action="store_true")
    parser.add_argument("-q", "--quit", help="Quit after finished", action="store_true")
    parser.add_argument("-a", "--autostart", help="Automatically start the first stored block", action="store_true")
    parser.add_argument("-k", "--reset", help="Reset block positions", action="store_true")
    parser.add_argument("-x", "--recursion-depth", help="Sets the maximum recursion depth", type=int)
    parser.add_argument("-z", "--seed", help="Set random seed")
    parser.add_argument("-g", "-graphicssystem", "--graphicssystem", help="Sets the backend to be used for on-screen widgets and QPixmaps. Available options are native (default) raster and opengl (experimental)")#, choices=['raster', 'opengl', 'native'])
    parser.add_argument("-d", "--display", help="This option is only valid for X11 and sets the X display (default is $DISPLAY)")
    
    args = parser.parse_args()
    
    if len(args.file) > 0:
        prm['calledWithPrm'] = True
        prm['prmFile'] = args.file
    if args.results:
        prm['resultsFile'] = args.results
    if args.listener:
        prm['listener'] = args.listener
    if args.session:
        prm['sessionLabel'] = args.session
    if args.conceal:
        prm['hideWins'] = True
    if args.minimized:
        prm['startMinimized'] = True
    else:
        prm['startMinimized'] = False
    if args.progbar:
        prm['progbar'] = True
    if args.blockprogbar:
        prm['blockProgbar'] = True
    if args.quit:
        prm['quit'] = True
    if args.autostart:
        prm['calledWithAutostart'] = True
    if args.recursion_depth:
        prm['calledWithRecursionDepth'] = True
        prm['cmdLineMaxRecursionDepth'] = args.recursion_depth
    if args.reset:
        prm['calledWithReset'] = True
    if args.seed:
        random.seed(int(args.seed))
        numpy.random.seed(int(args.seed))
    if args.graphicssystem:
        prm['graphicssystem'] = args.graphicssystem
    if args.display:
        prm['display'] = args.display
        
    prm = global_parameters.get_prefs(prm)
    callArgs = sys.argv
    if 'display' in prm:
        callArgs = callArgs + ['-display', prm['display']]
    if 'graphicssystem' in prm:
        callArgs = callArgs + ['-graphicssystem', prm['graphicssystem']]
    app = QApplication(callArgs)

    #LOCALE LOADING
    # qtTranslator is the translator for default qt component labels (OK, cancel button dialogs etc...)
    locale = QtCore.QLocale().system().name() #returns a string such as en_US
    qtTranslator = QtCore.QTranslator()
    if qtTranslator.load("qt_" + locale, ":/translations/"):
        app.installTranslator(qtTranslator)
    # appTranslator is the translator for labels created for the program
    appTranslator = QtCore.QTranslator()
    if appTranslator.load("pychoacoustics_" + locale, ":/translations/"):
        app.installTranslator(appTranslator)
    prm['currentLocale'] = QtCore.QLocale(locale)
    QtCore.QLocale.setDefault(prm['currentLocale'])
    prm['currentLocale'].setNumberOptions(prm['currentLocale'].OmitGroupSeparator | prm['currentLocale'].RejectGroupSeparator)
    
    if prm['pref']['country'] != "System Settings":
        locale =  prm['pref']['language']  + '_' + prm['pref']['country']#returns a string such as en_US
        qtTranslator = QtCore.QTranslator()
        if qtTranslator.load("qt_" + locale, ":/translations/"):
            app.installTranslator(qtTranslator)
        appTranslator = QtCore.QTranslator()
        if appTranslator.load("pychoacoustics_" + locale, ":/translations/") or locale == "en_US":
            app.installTranslator(appTranslator)
            prm['currentLocale'] = QtCore.QLocale(locale)
            QtCore.QLocale.setDefault(prm['currentLocale'])
            prm['currentLocale'].setNumberOptions(prm['currentLocale'].OmitGroupSeparator | prm['currentLocale'].RejectGroupSeparator)
    responseBoxLocale =  prm['pref']['responseBoxLanguage']  + '_' + prm['pref']['responseBoxCountry']#returns a string such as en_US
    responseBoxTranslator = QtCore.QTranslator()
    responseBoxTranslator.load("pychoacoustics_" + responseBoxLocale, ":/translations/")
    respButtTranslator = QtCore.QTranslator()

    prm['rbTrans'] = responseBoxTranslator
    prm['buttonTranslator'] = respButtTranslator

    prm = global_parameters.set_global_parameters(prm)
    app.setWindowIcon(QtGui.QIcon("/usr/share/icons/Machovka_Headphones.svg"))
    app.setStyle("Fusion")
    pychControlWin(parent=None, prm=prm)
    sys.exit(app.exec_())

if __name__ == "__main__":
    main(sys.argv[1:])
