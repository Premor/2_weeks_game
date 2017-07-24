#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(nation *bad, society *good, newspaper *player, other_org *org, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->stat_1->setText(QString::fromStdString(std::to_string(bad->get_stat())));
    ui->stat_2->setText(QString::fromStdString(std::to_string(good->get_stat())));
    ui->relation_1->setText(QString::fromStdString(std::to_string(bad->get_stat())));
    ui->relation_2->setText(QString::fromStdString(std::to_string(good->get_stat())));
}

Dialog::~Dialog()
{
    delete ui;
}
