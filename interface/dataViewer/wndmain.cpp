#include "wndmain.h"
#include "ui_wndmain.h"

wndMain::wndMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wndMain)
{
    ui->setupUi(this);

    ui->plotMain->setCanvasBackground(Qt::white);
    ui->plotMain->setAxisScale(QwtPlot::yLeft,0,110,10);
    ui->plotMain->setAxisScale(QwtPlot::xBottom,1,12,1);
    ui->plotMain->insertLegend(new QwtLegend());

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach(ui->plotMain);

    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setTitle("Record");
    curve->setPen(Qt::blue,4);
    curve->setRenderHint(QwtPlotItem::RenderAntialiased,true);

    QwtSymbol *symbol = new QwtSymbol(
            QwtSymbol::Ellipse,
            QBrush(Qt::yellow),
            QPen(Qt::red,2),
            QSize(8,8) );
    curve->setSymbol(symbol);

    QPolygonF points;
    points  << QPointF(1.0, 72.9)
            << QPointF(2.0, 66.9)
            << QPointF(3.0, 60.8)
            << QPointF(4.0, 54.8)
            << QPointF(5.0, 49.0)
            << QPointF(6.0, 43.5)
            << QPointF(7.0, 39.1)
            << QPointF(8.0, 36.3)
            << QPointF(9.0, 34.9);

    curve->setSamples(points);
    curve->attach(ui->plotMain);

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


void wndMain::on_btnDataBrowse_clicked()
{
    dataFile = QFileDialog::getOpenFileName(this,
                                            "Open Record File",
                                            "",
                                            ("TEXT (*.TXT)") );
    ui->txtDataFile->setText(dataFile);
}
