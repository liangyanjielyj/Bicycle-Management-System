#include "mainwindow.h"
#include "database.h"
#include <QApplication>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    new database(); // Connect Databse
    //new config(); // Load config option


    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCoreApplication::setApplicationName("Active Qt Web Browser");
    QCoreApplication::setOrganizationName("QtProject");
    MainWindow w;
    w.show();

    return a.exec();
}
