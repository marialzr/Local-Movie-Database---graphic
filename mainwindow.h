#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller &ctr, QWidget *parent = 0): QMainWindow(parent),  ui(new Ui::MainWindow), ctrl{ctr}
    {
        ui->setupUi(this);
        MainWindow::makePlot();
    }

    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void makePlot();


private:
    Ui::MainWindow *ui;
    Controller& ctrl;
};

#endif // MAINWINDOW_H
