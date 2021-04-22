#include "wndmain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wndMain w;
    w.setFixedHeight(600);
    w.setFixedWidth(800);
    w.show();
    return a.exec();
}
