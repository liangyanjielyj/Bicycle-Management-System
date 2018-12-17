#include "register_show.h"
#include "ui_register_show.h"

register_show::register_show(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::register_show)
{
    ui->setupUi(this);
    ui->regpasslineEdit->setEchoMode(QLineEdit::Password);
    Init();
    QString servIp = (QString)RGS_SERVER_IP;
    QString servPort = "8234";
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
void register_show::doProcessConnected(){
    qDebug() << "已确立连接";
}
void register_show::doProcessReadyRead(){
    QString msg= myClient->readAll();
    qDebug() << msg;
    if(msg == "OK"){
        this->close();
        QMessageBox msgBox;
        msgBox.setText("注册成功");
        msgBox.exec();
        MainWindow *m;
        m = new MainWindow();
        this -> close();
        m -> show();
    }
    if (msg == "NO"){
        //this->close();
        QMessageBox msgBox;
        msgBox.setText("注册失败，请重新注册");
        msgBox.exec();
    }
}
void register_show::doProcessDisconnected(){
    qDebug() << "服务器未启动";
}
void register_show::doProcessError(QAbstractSocket::SocketError err){
    qDebug() << err;
}


register_show::~register_show()
{
    delete ui;
}

void register_show::on_pushButton_clicked()
{
    MainWindow *w;
    w = new MainWindow();
    this -> close();
    w -> show();
}
//function
void register_show::Init(){
    myClient = new QTcpSocket(this);
}
//endfuction

void register_show::on_pushButton_2_clicked()
{
//    struct rgs_st zhuce;

    QString p = "$%^FG%$^&$FDFG$^%%$%^G";
    QString q = ",";

    QString uname = ui->regnamelineEdit->text();
    QString pw = ui->regpasslineEdit->text();
   // QString pw = ui->regpasslineEdit->text();

    QString mibao = ui->lineEdit->text();
   /* QByteArray ba = pw.toLatin1();
    ba = QCryptographicHash::hash(ba,QCryptographicHash::Md5);
    ba = ba.toHex();*/
    pw = QString("%1%2%3").arg(p).arg(q).arg(pw);
/*  const char *p = ba.data();
    //const char *p = pw.toStdString().c_str();
    const char *u = uname.toStdString().c_str();

    qsnprintf(zhuce.username, SIZE, u);
    qsnprintf(zhuce.passwd, SIZE, p);
    qDebug() << "zhuce" << zhuce.username << " " << zhuce.passwd << endl;*/
    //QHostAddress *address = new QHostAddress(QString(RGS_SERVER_IP));
    //socket->writeDatagram((const char *)&zhuce,sizeof(zhuce), *address,RGS_SERVER_PORT);
  //  myClient->writeData((const char *)&zhuce,64);
    QString msg = " ";
    //pw =  QString(ba);
    QString dat = QString("%1%2%3%4%5").arg(uname).arg(msg).arg(pw).arg(msg).arg(mibao);
    qDebug() << dat;
    myClient->write(dat.toUtf8());
}
