#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QNetworkInterface>
#include <QTcpSocket>
#include "database.h"
#include <QSqlDatabase>
//#include <QtSql/qtsqlglobal.h>
#include <QtSql/qsqldatabase.h>
#include <QtCore/qstring.h>
#include <QSqlQuery>
#include <QSqlError>
#define SIZE    1024

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void doProcessNewConnection();
    void doProcessAcceptError(QAbstractSocket::SocketError);
    void doProcessDisconnected();
    void doProcessReadyRead();

private:
    Ui::Widget *ui;
    QTcpServer *myServer;

    void databaseshow(QString msg);

    void Init();
};


#endif // WIDGET_H
