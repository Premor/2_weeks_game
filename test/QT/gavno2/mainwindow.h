#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "game.h"

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
    //void on_pushButton_clicked();
    void update();
    void next_day();
    void begin_game();
    void new_frame();
signals:
    void s1();

private:
    //friend world;
    //friend int gavno();
    int g;
    Ui::MainWindow *ui;


public:
    void mocha();


};

#endif // MAINWINDOW_H
