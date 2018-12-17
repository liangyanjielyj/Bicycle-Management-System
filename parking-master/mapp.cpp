#include "mapp.h"
#include "ui_mapp.h"
#include <QVariant>
#include <QAbstractEventDispatcher>
#include <QUrl>
#include <QDebug>
#include <QDir>
mapp::mapp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mapp)
{
    ui->setupUi(this);
    ui->addrLineEdit->setText("https://www.baidu.com/");
    this->showAddrWeb();

    connect(ui->goPushButton,SIGNAL(clicked(bool)),this,SLOT(showAddrWeb()));
    connect(ui->mapBtn,SIGNAL(clicked(bool)),this,SLOT(showBaiduMap()));
}

mapp::~mapp()
{
    delete ui;
}

void mapp::webShow(const QString &url){
    ui->webBrowser->dynamicCall("Navigate(const QString&)", url);
}

void mapp::showAddrWeb(){
    QString addr=ui->addrLineEdit->text();
    //if((addr.indexOf("www")!=0)&&(addr.indexOf("http")!=0))  return;
    webShow(addr);
}
void mapp::showBaiduMap(){
    QString mapHtml=QDir::currentPath()+"/MapFile/BaiduMap.html";
    qDebug()<<QDir::currentPath();
    //qDebug()<<myurl;
    ui->addrLineEdit->setText("地图");
    webShow(mapHtml);
}
