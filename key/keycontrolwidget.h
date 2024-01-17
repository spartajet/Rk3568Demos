//
// Created by guoxi on 2024/1/17.
//

#ifndef KEYCONTROLWIDGET_H
#define KEYCONTROLWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class keycontrolwidget; }
QT_END_NAMESPACE

class keycontrolwidget : public QWidget {
Q_OBJECT

public:
    explicit keycontrolwidget(QWidget *parent = nullptr);
    ~keycontrolwidget() override;

private:
    Ui::keycontrolwidget *ui;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};


#endif //KEYCONTROLWIDGET_H
