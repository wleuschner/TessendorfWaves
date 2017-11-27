#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "oceanwaves.h"

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
    void changeClicked();
    void update();

private:
    double t=0.0;
    unsigned char* analysisImage;

    OceanWaves simulation;
    QTimer updateTimer;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
