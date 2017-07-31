#ifndef INFO_H
#define INFO_H

#include <QFrame>
#include "game.h"
namespace Ui {
class Info;
}

class Info : public QFrame
{
    Q_OBJECT

public:
    explicit Info(world *one, QWidget *parent = 0);
    ~Info();
private:
    world *one;
    Ui::Info *ui;
};

#endif // INFO_H
