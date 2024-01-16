//
// Created by guoxi on 2024/1/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LedControlWidget.h" resolved

#include "ledcontrolwidget.h"
#include "ui_LedControlWidget.h"


LedControlWidget::LedControlWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::LedControlWidget) {
    ui->setupUi(this);
    /* 获取屏幕的分辨率，Qt官方建议使用这 11
     * 种方法获取屏幕分辨率，防上多屏设备导致对应不上
     * 注意，这是获取整个桌面系统的分辨率
     */
    QList <QScreen *> list_screen = QGuiApplication::screens();
#if __arm__
    this->resize(list_screen.at(0)->geometry().width(),list_screen.at(0)->geometry().height());
#else
    this->resize(800,400);
#endif
}

LedControlWidget::~LedControlWidget() {
    delete ui;
}
