#include "mainwindow.h"
#include "pugixml-1.7/src/pugixml.hpp"
#include <QApplication>
#include <iostream>
#include <QTextEdit>

using namespace std;

int main(int argc, char *argv[1])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTextEdit *PI = new QTextEdit();
    QTabWidget *tab = new QTabWidget;
    QPalette *pal = new QPalette;

    return a.exec();
}
