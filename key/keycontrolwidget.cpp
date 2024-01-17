//
// Created by guoxi on 2024/1/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_keycontrolwidget.h" resolved

#include "keycontrolwidget.h"
#include "ui_keycontrolwidget.h"
#include <QKeyEvent>


keycontrolwidget::keycontrolwidget(QWidget *parent) : QWidget(parent), ui(new Ui::keycontrolwidget) {
    ui->setupUi(this);
    /* 获取屏幕的分辨率，Qt官方建议使用这
     * 种方法获取屏幕分辨率，防上多屏设备导致对应不上
     * 注意，这是获取整个桌面系统的分辨率
     */
    QList<QScreen *> list_screen = QGuiApplication::screens();
#if __arm__
    this->resize(list_screen.at(0)->geometry().width(),list_screen.at(0)->geometry().height());
#else
    this->resize(800, 400);
#endif
}

keycontrolwidget::~keycontrolwidget() {
    delete ui;
}

void keycontrolwidget::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    this->ui->label->setText("key: 0x" + QString::number(key,16) + "按下");
    QWidget::keyPressEvent(event);
}

void keycontrolwidget::keyReleaseEvent(QKeyEvent *event) {
    int key = event->key();

    this->ui->label->setText("key: 0x" + QString::number(key,16) + "抬起");
    QWidget::keyReleaseEvent(event);
}
