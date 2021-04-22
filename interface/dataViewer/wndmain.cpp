#include "wndmain.h"
#include "ui_wndmain.h"

wndMain::wndMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wndMain)
{
    ui->setupUi(this);

    ui->plotMain->setCanvasBackground(Qt::white);
    ui->plotMain->setAxisScale(QwtPlot::yLeft,0,110,10);
    ui->plotMain->setAxisScale(QwtPlot::xBottom,0,15,1);

    addSerialPort();
}

wndMain::~wndMain()
{
    delete ui;
}

void wndMain::addSerialPort(void){
#ifdef Q_OS_LINUX
    ui->cmbPort->addItem("/dev/ttyUSB0");
    ui->cmbPort->addItem("/dev/ttyUSB1");
    ui->cmbPort->addItem("/dev/ttyUSB2");
    ui->cmbPort->addItem("/dev/ttyACM0");
    ui->cmbPort->addItem("/dev/ttyACM1");
    ui->cmbPort->addItem("/dev/ttyACM2");
#else
    ui->cmbPort->addItem("COM1");
    ui->cmbPort->addItem("COM2");
    ui->cmbPort->addItem("COM3");
    ui->cmbPort->addItem("COM4");
    ui->cmbPort->addItem("COM5");
    ui->cmbPort->addItem("COM6");
#endif
}

