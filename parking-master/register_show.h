#ifndef REGISTER_SHOW_H
#define REGISTER_SHOW_H

#include <QWidget>
#include "mainwindow.h"
#include <QTcpSocket>
#include "proto.h"
#include <QHostAddress>
#include <QDebug>

namespace Ui {
class register_show;
}

class register_show : public QWidget
{
    Q_OBJECT

public:
    explicit register_show(QWidget *parent = 0);
    ~register_show();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void doProcessConnected();
    void doProcessReadyRead();
    void doProcessDisconnected();
    void doProcessError(QAbstractSocket::SocketError);

private:
    Ui::register_show *ui;

    QTcpSocket *myClient;

    void Init();
};

#endif // REGISTER_SHOW_H
