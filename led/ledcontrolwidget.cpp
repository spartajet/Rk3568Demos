//
// Created by guoxi on 2024/1/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LedControlWidget.h" resolved

#include "ledcontrolwidget.h"
#include "ui_LedControlWidget.h"
#include <QDebug>


LedControlWidget::LedControlWidget(QWidget *parent) : QWidget(parent), ui(new Ui::LedControlWidget) {
    ui->setupUi(this);
    /* 获取屏幕的分辨率，Qt官方建议使用这 11
     * 种方法获取屏幕分辨率，防上多屏设备导致对应不上
     * 注意，这是获取整个桌面系统的分辨率
     */
    QList<QScreen *> list_screen = QGuiApplication::screens();
#if __arm__
    this->resize(list_screen.at(0)->geometry().width(),list_screen.at(0)->geometry().height());

    /* 默认是出厂系统的LED为心跳的触发方式,想要控制LED，
     * 需要先关闭心跳，然后再设置为none
     */
    system("echo none > /sys/class/leds/work/trigger");
#else
    this->resize(800, 400);
#endif
}

LedControlWidget::~LedControlWidget() {
    delete ui;
}


void LedControlWidget::GetLedState() {
    if (!this->ledExist) {
        return;
    }
    if (!this->ledFile.open(QIODevice::ReadWrite)) {
        qDebug() << this->ledFile.errorString();
        this->ui->initialButton->setText("Open Led File Failed");
        return;
    }
    QTextStream in(&this->ledFile);
    QString line = in.readLine();
    if (line == "0") {
        this->ledState = false;
        this->ui->controlButton->setText("ON");
    } else if (line == "1") {
        this->ledState = true;
        this->ui->controlButton->setText("OFF");
    } else {
        this->ui->initialButton->setText("Led Operate Error");
    }
    this->ledFile.close();
}

void LedControlWidget::SetLedState(bool state) {
    if (!this->ledExist) {
        return;
    }
    if (!this->ledFile.open(QIODevice::ReadWrite)) {
        qDebug() << this->ledFile.errorString();
        this->ui->initialButton->setText("Open Led File Failed");
        return;
    }
    QTextStream in(&this->ledFile);
    if (state) {
        in << "1";
        this->ui->controlButton->setText("OFF");
    } else {
        in << "0";
        this->ui->controlButton->setText("ON");
    }
    this->ledFile.close();
}

void LedControlWidget::onInitialButtonClick() {
    this->ledFile.setFileName("/sys/class/leds/work/brightness");
    if (!this->ledFile.exists()) {
        this->ui->initialButton->setText("No Led File Found");
        this->ledExist = false;
        return;
    }
    this->GetLedState();
}

void LedControlWidget::onControlButtonClick() {
    if (this->ui->controlButton->text()=="ON") {
        this->SetLedState(true);
    } else if (this->ui->controlButton->text()=="OFF") {
        this->SetLedState(false);
    }
}
