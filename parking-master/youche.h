#ifndef YOUCHE_H
#define YOUCHE_H

#include <QWidget>

namespace Ui {
class YouChe;
}

class YouChe : public QWidget
{
    Q_OBJECT

public:
    explicit YouChe(QWidget *parent = 0);
    ~YouChe();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::YouChe *ui;
};

#endif // YOUCHE_H
