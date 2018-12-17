#include "youche.h"
#include "ui_youche.h"
#include "in.h"
#include "out.h"
#include "mainwindow.h"

YouChe::YouChe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YouChe)
{
    ui->setupUi(this);
}

YouChe::~YouChe()
{
    delete ui;
}

void YouChe::on_pushButton_3_clicked()
{
    this->close();
}

void YouChe::on_pushButton_clicked()
{
    in *inWindow;
    inWindow = new in();
    this -> close();
    inWindow -> show();
}

void YouChe::on_pushButton_2_clicked()
{
    out *outWindow;
    outWindow = new out();
    this -> hide();
    outWindow -> show();
}

void YouChe::on_pushButton_4_clicked()
{
    MainWindow *w;
    w = new MainWindow();
    this -> close();
    w -> show();
}
