#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <QMainWindow>
#include "game.h"
namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(std::vector<game_event*>::iterator _begin, std::vector<game_event*>::iterator _end,std::vector<game_event*>* polosi,world *_one,QMainWindow * _main, QWidget *parent = 0);
    ~Frame();
    bool eventFilter(QObject *watched, QEvent *event);
    void closeEvent(QCloseEvent *event);
//private slots:
    //void hover_1();
//signals:


private:
    std::vector<game_event*>::iterator begin;
    std::vector<game_event*>::iterator end;
    QMainWindow *main;
    world *one;
    Ui::Frame *ui;
};

#endif // FRAME_H
