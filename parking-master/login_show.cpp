#include "login_show.h"
#include "ui_login_show.h"
#include "youche.h"

login_show::login_show(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_show)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    Init();
    QString servIp = (QString)RGS_SERVER_IP;
    QString servPort = "8235";
    qDebug() << servIp << servPort;
    myClient->connectToHost(QHostAddress(servIp),servPort.toUInt());
    connect(myClient,SIGNAL(connected()),
            this,SLOT(doProcessConnected()));
    connect(myClient,SIGNAL(readyRead()),
            this,SLOT(doProcessReadyRead()));
    connect(myClient,SIGNAL(disconnected()),
            this,SLOT(doProcessDisconnected()));
    connect(myClient,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(doProcessError(QAbstractSocket::SocketError)));
}

login_show::~login_show()
{
    delete ui;
}
void login_show::Init(){
    myClient = new QTcpSocket(this);
}

void login_show::doProcessConnected(){
    qDebug() << "以确立连接";
}
void login_show::doProcessReadyRead(){
    QString msg= myClient->readAll();
    qDebug() << msg;
    if(msg == "OK"){
        this->close();
        QMessageBox msgBox;
        msgBox.setText("登录成功");
        msgBox.exec();
        YouChe *w = new YouChe();
        w->show();

    }
    if (msg == "NO"){
        //this->close();
        QMessageBox msgBox;
        msgBox.setText("登录失败，请重新登录");
        msgBox.exec();
    }
}
void login_show::doProcessDisconnected(){
    qDebug() << "服务器未启动";
}
void login_show::doProcessError(QAbstractSocket::SocketError err){
    qDebug() << err;
}
void login_show::on_pushButton_clicked()
{
    MainWindow *w;
    w = new MainWindow();
    this -> close();
    w -> show();
}

void login_show::on_pushButton_2_clicked()
{
    QString uname = ui->lineEdit->text();
    QString pw = ui->lineEdit_2->text();
    QByteArray ba = pw.toLatin1();
    ba = QCryptographicHash::hash(ba,QCryptographicHash::Md5);
    ba = ba.toHex();

    QString msg = " ";
    pw =  QString(ba);
    QString dat = QString("%1%2%3").arg(uname).arg(msg).arg(pw);
    qDebug() << dat;
    myClient->write(dat.toUtf8());
}
