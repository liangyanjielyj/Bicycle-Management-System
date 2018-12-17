#include "widget.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    new database();
    Widget w;
    w.show();

    return a.exec();
}
