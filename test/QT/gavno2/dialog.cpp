#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(world *one, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->stat_1->setText(QString::fromStdString(std::to_string((one->get_nat())->get_stat())));
    ui->stat_2->setText(QString::fromStdString(std::to_string((one->get_soc())->get_stat())));
    ui->relation_1->setText(QString::fromStdString(std::to_string((one->get_nat())->get_stat())));
    ui->relation_2->setText(QString::fromStdString(std::to_string((one->get_soc())->get_stat())));
}

Dialog::~Dialog()
{
    delete ui;
}
