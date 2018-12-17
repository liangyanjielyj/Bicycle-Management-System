#include "guanli.h"
#include "ui_guanli.h"
#include "mainwindow.h"
#include "cheg.h"
#include "reng.h"
#include <QTabWidget>
#include <QHBoxLayout>
#include "mapp.h"


guanli::guanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guanli)
{
    ui->setupUi(this);
    cheg *tab01 = new cheg();
    reng *tab02 = new reng();
    ui->tabWidget->addTab(tab02,"tab_yonghu");
    ui->tabWidget->addTab(tab01,"tab_car");

}


guanli::~guanli()
{
    delete ui;
}
void guanli::rfresushow(){

    //tab01->rfreshtab();
}
void guanli::on_pushButton_2_clicked()
{
   /* ui->textEdit->clear();
    ui->textEdit_2->clear();
    QSqlQuery query;
    query.exec("select * from YONHU");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString firstname = query.value(1).toString();
        QString password = query.value(2).toString();
        QString msg = QString("Id %1: 姓名: %2 密码：%3")
            .arg(id).arg(firstname).arg(password);
        ui->textEdit->append(msg);
    }
    query.exec("select * from spaces");
    while (query.next()) {
       // int id = query.value(0).toInt();
        QString firstname = query.value(1).toString();
        QString password = query.value(2).toString();
        QString time = query.value(3).toString();
        QString msg = QString("姓名: %1 车号：%2 用车时间：%3")
            .arg(firstname).arg(password).arg(time);
        ui->textEdit_2->append(msg);
    }*/

    ui->tabWidget->removeTab(3);
    ui->tabWidget->removeTab(2);
    cheg *tab01 = new cheg();
    reng *tab02 = new reng();
    ui->tabWidget->addTab(tab02,"tab_yonghu");
    ui->tabWidget->addTab(tab01,"tab_car");
}

void guanli::on_pushButton_clicked()
{
   /* QSqlQuery qry;
    QString nam = ui->lineEdit->text();
    QString sql = "DELETE FROM `YONHU` WHERE `username` = '"+nam+"'";
    qry.prepare(sql);
    if( !qry.exec() ){
        qDebug() << qry.lastError();
    }else{
        //this->close();
        QMessageBox msgBox;
        msgBox.setText("已删除用户");
        msgBox.exec();
    }*/
    mapp * c = new mapp();
    c->show();
}

void guanli::on_pushButton_3_clicked()
{
    MainWindow *w;
    w = new MainWindow();
    this -> close();
    w -> show();
}

void guanli::on_tabWidget_destroyed()
{
   qDebug() << "sdfasfasd";
}

