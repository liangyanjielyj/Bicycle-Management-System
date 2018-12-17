#ifndef CHEG_H
#define CHEG_H

#include <QWidget>
#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "database.h"
namespace Ui {
class cheg;
}

class cheg : public QWidget
{
    Q_OBJECT

public:
    explicit cheg(QWidget *parent = 0);
    ~cheg();
    void rfreshtab();


private slots:
    void sleep(unsigned int msec);
    void show();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::cheg *ui;


};

#endif // CHEG_H
