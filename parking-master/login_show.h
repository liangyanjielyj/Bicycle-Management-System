#ifndef LOGIN_SHOW_H
#define LOGIN_SHOW_H

#include <QWidget>
#include "mainwindow.h"
#include <QTcpSocket>
namespace Ui {
class login_show;
}

class login_show : public QWidget
{
    Q_OBJECT

public:
    explicit login_show(QWidget *parent = 0);
    ~login_show();

private slots:
    void on_pushButton_clicked();

    void doProcessConnected();
    void doProcessReadyRead();
    void doProcessDisconnected();
    void doProcessError(QAbstractSocket::SocketError);


    void on_pushButton_2_clicked();

private:
    Ui::login_show *ui;

    QTcpSocket *myClient;

    void Init();
};

#endif // LOGIN_SHOW_H
