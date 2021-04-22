#ifndef WNDMAIN_H
#define WNDMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class wndMain; }
QT_END_NAMESPACE

class wndMain : public QMainWindow
{
    Q_OBJECT

public:
    wndMain(QWidget *parent = nullptr);
    ~wndMain();

private:
    Ui::wndMain *ui;

    void addSerialPort(void);
};
#endif // WNDMAIN_H
