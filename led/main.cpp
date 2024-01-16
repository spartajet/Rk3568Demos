
#include <iostream>
#include <QApplication>
#include "ledcontrolwidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LedControlWidget widget;
    widget.show();
    return QApplication::exec();
}
