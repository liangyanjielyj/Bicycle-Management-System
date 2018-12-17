#include "mibao.h"
#include "ui_mibao.h"
#include "database.h"
#include <QDebug>
#include <QSqlQuery>
#include "login_show.h"
#include "mibao.h"
mibao::mibao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mibao)
{
    ui->setupUi(this);
}

mibao::~mibao()
{
    delete ui;
}

void mibao::on_pushButton_2_clicked()
{
    MainWindow *c = new MainWindow();
    c->show();
    this->close();
}

void mibao::on_pushButton_clicked()
{
    QSqlQuery qry;
    QSqlQuery query;
    QString uname = ui->namelineEdit->text();
    QString umibao = ui->mibaolineEdit->text();
    QString sql = "SELECT * FROM `YONHU` WHERE `username` = '"+uname+"' and `mibao` = '"+umibao+"'";
    qry.prepare(sql);
    if(!qry.exec()){
        qDebug() << "qry.lastError()";
    }else {
       if(qry.first()) {
           QString name = qry.value(1).toString();
           QString password = qry.value(2).toString();
           QString mib = qry.value(3).toString();
           QString pas = password.section(",",1,1);
           QString dd = "记好你的密码：";
           pas = QString("%1%2").arg(dd).arg(pas);
           QMessageBox msgBox;
           msgBox.setText(pas);
           msgBox.exec();
           login_show *c = new login_show();
           c->show();
           this->close();
       }else {
           QMessageBox msgBox;
           msgBox.setText("用户名与密宝不匹配无法找回密码");
           msgBox.exec();
       }
    }
}
