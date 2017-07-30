#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init_event();
private slots:
    //void on_pushButton_clicked();
    void v_gorod();
    void next_day();
    void begin_game();
    void new_frame();
signals:
    void s1();

private:
    //friend world;
    //friend int gavno();
    world one;
    std::vector<game_event *> all_event;
    std::vector<game_event *> polosi_gazeti;
    std::vector<event_desc *> desc;
    Ui::MainWindow *ui;


public:
    void mocha();


};

#endif // MAINWINDOW_H
