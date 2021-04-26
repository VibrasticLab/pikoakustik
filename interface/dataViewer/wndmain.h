#ifndef WNDMAIN_H
#define WNDMAIN_H

#include <QMainWindow>
#include <QFileDialog>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>

QT_BEGIN_NAMESPACE
namespace Ui { class wndMain; }
QT_END_NAMESPACE

class wndMain : public QMainWindow
{
    Q_OBJECT

public:
    wndMain(QWidget *parent = nullptr);
    ~wndMain();

private slots:
    void on_btnDataBrowse_clicked();

private:
    Ui::wndMain *ui;
    QString dataFile;
    void addSerialPort(void);
};
#endif // WNDMAIN_H
