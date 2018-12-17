#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mibao.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this -> adminConfig = new config();
    setWindowTitle("共享单车管理系统");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_in_clicked() {
   /* in *inWindow;
    inWindow = new in();
    this -> close();
    inWindow -> show();*/
    register_show *register_sh = new register_show();
    register_sh->show();
    this->close();

}

void MainWindow::on_out_clicked() {
    /*out *outWindow;
    outWindow = new out();
    this -> hide();
    outWindow -> show();*/
    login_show *login_sh = new login_show();
    login_sh->show();
    this->close();
}

void MainWindow::on_admin_clicked() {
    Dialog *loginDialog = new Dialog();
    loginDialog -> show();
    this ->close();
}



void MainWindow::on_pushButton_clicked()
{
    mibao *c = new mibao();
    c->show();
    this->close();
}
