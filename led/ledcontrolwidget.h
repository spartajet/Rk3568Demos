//
// Created by guoxi on 2024/1/16.
//

#ifndef LEDCONTROLWIDGET_H
#define LEDCONTROLWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class LedControlWidget; }
QT_END_NAMESPACE

class LedControlWidget : public QWidget {
Q_OBJECT

public:
    explicit LedControlWidget(QWidget *parent = nullptr);
    ~LedControlWidget() override;

private:
    Ui::LedControlWidget *ui;
};


#endif //LEDCONTROLWIDGET_H
