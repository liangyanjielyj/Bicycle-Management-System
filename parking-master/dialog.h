#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include"admin.h"
#include "guanli.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    bool checkUser();

private slots:
    void on_login_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
