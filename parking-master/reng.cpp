#include "reng.h"
#include "ui_reng.h"
#include "guanli.h"
reng::reng(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reng)
{
    ui->setupUi(this);
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
}

reng::~reng()
{
    delete ui;
}

void reng::on_pushButton_clicked()
{
    QSqlQuery qry;
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
    }
    //this->close();
    //guanli *a = new guanli();
    //a->show();
}
