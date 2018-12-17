#include "cheg.h"
#include "ui_cheg.h"
#include "database.h"
#include <QThread>
#include <QTime>
#include "mainwindow.h"
cheg::cheg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cheg)
{
    ui->setupUi(this);
   // while(1){
        //  this->sleep(1000);
   //}
    show();
}


void cheg::sleep(unsigned int msec){
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime) {
       QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void cheg::show(){
    QSqlQuery query;
        query.exec("select * from spaces");
        while (query.next()) {
           // int id = query.value(0).toInt();
            QString firstname = query.value(1).toString();
            QString password = query.value(2).toString();
            QString time = query.value(3).toString();
            QString msg = QString("姓名: %1 车号：%2 用车时间：%3")
                .arg(firstname).arg(password).arg(time);
            ui->textEdit->append(msg);
        }
    QSqlQuery qry;
         qry.exec("select * from car_pos");
         while (qry.next()) {
               // int id = query.value(0).toInt();
            QString chehao = qry.value(7).toString();
            QString zhangtai = qry.value(6).toString();
            QString qk = qry.value(5).toString();
            QString ms = QString("车号: %1 车况：%2 是否被使用：%3")
                .arg(chehao).arg(zhangtai).arg(qk);
            ui->textEdit_2->append(ms);
        }
}

void cheg::rfreshtab(){
    ui->textEdit->clear();
    show();
}

cheg::~cheg()
{
    delete ui;
}

void cheg::on_pushButton_2_clicked()
{
    QSqlQuery qry;
    QString che = ui->lineEdit->text();
    QString sql = "DELETE FROM `car_pos` WHERE `pos_num` = '"+che+"'";
    qry.prepare(sql);
    if( !qry.exec() ){
        qDebug() << qry.lastError();
    }else{
        //this->close();
        QMessageBox msgBox;
        msgBox.setText("已删除车辆");
        msgBox.exec();
    }
}

void cheg::on_pushButton_clicked()
{
    QString x = "12";
    QString y = "34";
    QString width = "23";
    QString height = "23";
    QString status = "free";
    QString type = "nice";
    QString pos_num = ui->lineEdit->text();
    QSqlQuery qry;
    QString sql = "INSERT INTO `car_pos` (`x`, `y`, `width`, `height`, `status`, `type`, `pos_num`) VALUES ('"+x+"', '"+ y +"', '"+ width +"', '"+ height +"', '"+ status +"', '"+ type +"', '"+ pos_num +"')";

    qry.prepare(sql);

    if( !qry.exec() ) {
        qDebug() << qry.lastError();
    } else {
        QMessageBox msgBox;
        msgBox.setText("以添加新车");
        msgBox.exec();
    }
}

void cheg::on_pushButton_3_clicked()
{
    MainWindow *c=new MainWindow();
    c->show();
    this->close();
}
