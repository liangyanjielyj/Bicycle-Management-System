#ifndef MAPP_H
#define MAPP_H

#include <QMainWindow>

namespace Ui {
class mapp;
}

class mapp : public QMainWindow
{
    Q_OBJECT

public:
    explicit mapp(QWidget *parent = 0);
    ~mapp();

    void webShow(const QString &url);

private slots:
    void showAddrWeb();
    void showBaiduMap();
private:
    Ui::mapp *ui;
};

#endif // MAPP_H
