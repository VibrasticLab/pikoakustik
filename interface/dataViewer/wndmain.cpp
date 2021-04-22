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
}

wndMain::~wndMain()
{
    delete ui;
}

