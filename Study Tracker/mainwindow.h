#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdialog.h>
#include <qfiledialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionImport_triggered();

    void on_actionExport_triggered();

    void on_Import_clicked();

    void on_Export_clicked();

    void on_StudImport_clicked();

    void on_StudExport_clicked();

//    void on_addUser_clicked();

    void on_CalculateScore_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
