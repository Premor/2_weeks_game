
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "game.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(nation *bad,society *good,newspaper *player,other_org *org,QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
