#ifndef GUANLI_H
#define GUANLI_H

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
class guanli;
}

class guanli : public QWidget
{
    Q_OBJECT

public:
    explicit guanli(QWidget *parent = 0);
    ~guanli();
    void rfresushow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tabWidget_destroyed();

private:
    Ui::guanli *ui;
};

#endif // GUANLI_H
