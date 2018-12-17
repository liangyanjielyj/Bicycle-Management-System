#include "in.h"
#include "ui_in.h"
#include "youche.h"
#include "mapp.h"
in::in(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::in)
{
    ui->setupUi(this);
    setWindowTitle("共享单车管理系统");
    this -> initWindow();
}

in::~in()
{
    delete ui;
}

void in::on_back_clicked()
{
    YouChe *m;
    m = new YouChe();
    this -> close();
    m -> show();
}

void in::initWindow(){

    QTimer *timer = new QTimer(this);
    displayTime();
    connect(timer, SIGNAL(timeout()), this, SLOT(displayTime()));
    timer->start(1000);

    QString car_pos = this -> allocationPos();

    if(car_pos == "false") {
        ui -> pos -> setAlignment(Qt::AlignCenter);
        ui -> pos -> setStyleSheet("border: 1px solid red;");
        ui -> pos -> setText("车已用完");
        ui -> car_num -> setEnabled(false);
    } else {
        ui -> pos -> setAlignment(Qt::AlignCenter);
        ui -> pos -> setStyleSheet("border: 1px solid green;");
        ui -> pos -> setText(car_pos);
    }
}

void in::displayTime(){
    QDateTime dt;
    QTime time;
    QDate date;

    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());

    QString currentDate = dt.toString("yyyy-MM-dd hh:mm:ss");
    ui -> in_time -> setAlignment(Qt::AlignCenter);
    ui -> in_time -> setStyleSheet("border: 1px solid green;");
    ui->in_time->setText(currentDate);
}

QString in::allocationPos(){
//    new database();

    QSqlQuery qry;
    qry.prepare( "SELECT * FROM `car_pos` WHERE `status` = 'free' and `type` = 'position' LIMIT 1" );
    if( !qry.exec() ){
        qDebug() << qry.lastError();
        return "DB ERROR";
    } else {
        while( qry.next() ){
            return qry.value(0).toString();
        }
        return "false";
    }
}

void in::on_enter_clicked() {
//    new database();

    if(ui -> car_num -> isEnabled()){
        QString input_car_num = ui -> car_num -> text();
        QString input_in_time = ui -> in_time -> text();
        QString input_place_id = ui -> pos -> text();

        QSqlQuery qry;
        QString sql = "INSERT INTO `spaces` (`car_num`, `place_id`, `in_time`) VALUES ('"+ input_car_num +"', '"+ input_place_id +"', '"+ input_in_time +"')";

        qry.prepare(sql);

        if( !qry.exec() ) {
            qDebug() << qry.lastError();
        } else {
            QString  sql_up = "UPDATE `car_pos` SET `status` = 'full' WHERE id = '"+input_place_id+"'";
            qry.prepare(sql_up);
            if( !qry.exec() )
                qDebug() << qry.lastError();
        }
        QMessageBox msgBox;
        msgBox.setText("用车成功!");
        msgBox.exec();
        this -> initWindow();
        this->close();
        YouChe *w = new YouChe();
        w->show();
    } else {
        QMessageBox msgBox;
        msgBox.setText("车已用完,不要乱点!!");
        msgBox.exec();
    }
}

