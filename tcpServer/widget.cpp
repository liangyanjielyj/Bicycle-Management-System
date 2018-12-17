#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#define MAXNUM 100

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Init(){
    myServer = new QTcpServer(this);
}

void Widget::on_pushButton_clicked()
{
    QString myAddr;
    myAddr = ui->IP_test->text();
    QString myPort = QString("8234");
    //添加线程池


    QString msg;
    bool ret = myServer->listen(QHostAddress(myAddr),myPort.toUInt());
    if(!ret){
        msg = "绑定成功";
    }else{
        msg = "绑定失败";
        //ui->pushButton->setEnabled(false);
    }
    ui->textEdit->append(msg);
    myServer->setMaxPendingConnections(MAXNUM);

    connect(myServer, SIGNAL(newConnection()),
            this, SLOT(doProcessNewConnection()));
    connect(myServer, SIGNAL(acceptError(QAbstractSocket::SocketError)),
            this, SLOT(doProcessAcceptError(QAbstractSocket::SocketError)));
}

void Widget::doProcessNewConnection(){
    QTcpSocket *client = myServer->nextPendingConnection();
    //客户端断开
    connect(client,SIGNAL(disconnected()),
            this, SLOT(doProcessDisconnected()));
    //读取内容
    connect(client, SIGNAL(readyRead()),
            this, SLOT(doProcessReadyRead()));

}

void Widget::doProcessAcceptError(QAbstractSocket::SocketError err){
    qDebug() << err;
}

void Widget::doProcessDisconnected(){
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString msg = QString("客户端[%1:%2] 退出！")
                          .arg(client->peerAddress().toString())
                          .arg(client->peerPort());
    ui->textEdit->append(msg);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
}
void Widget::doProcessReadyRead(){
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString str1 = QString("856T[%1:%2] 数据：")
                           .arg(client->peerAddress().toString())
                           .arg(client->peerPort());
    QString msg;
    QString str2;
    while (!client->atEnd()) {
        msg.append(QString( client->readAll()));
//        QString str2 = QString( client->readAll());
//        msg = QString("%1%2".arg(str1).arg(str2));
//        ui->textEdit->append(str);

    }
    str2 = QString("%1%2").arg(str1).arg(msg);
    this->databaseshow(msg);
    ui->textEdit->append(str2);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);

}
void Widget::databaseshow(QString msg){
    QTcpSocket *client = (QTcpSocket *)this->sender();
    QString dat = msg;
    QString que ="OK";
    char a[SIZE];
    char b[SIZE];
    char e[SIZE];
    QString uname = dat.section(" ",0,0);
    QString pssd  = dat.section(" ",1,1);
    QString mibao = dat.section(" ",2,2);
    const char *c = uname.toStdString().c_str();
    const char *d  = pssd.toStdString().c_str();
    const char *f = mibao.toStdString().c_str();
    qsnprintf(a, SIZE, c);
    qsnprintf(b, SIZE, d);
    qsnprintf(e, SIZE, f);
    QSqlQuery qry;
    qry.prepare("INSERT INTO YONHU(username,password,mibao)"
                        "VALUES (:username, :password, :mibao)");
    // qry.bindValue(":ID", 325103);
    qry.bindValue(":username", uname);
    qry.bindValue(":password", pssd);
    qry.bindValue(":mibao", mibao);

    //qry.prepare(sql);
    if (!qry.exec()) {

        qDebug() << qry.lastError();
    }else {
        client->write(que.toLatin1());
        qDebug() << "success";
    }
}
