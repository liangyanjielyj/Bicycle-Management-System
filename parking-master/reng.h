#ifndef RENG_H
#define RENG_H

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
class reng;
}

class reng : public QWidget
{
    Q_OBJECT

public:
    explicit reng(QWidget *parent = 0);
    ~reng();

private slots:
    void on_pushButton_clicked();

private:
    Ui::reng *ui;
};

#endif // RENG_H
