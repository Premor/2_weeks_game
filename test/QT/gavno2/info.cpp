#include "info.h"
#include "ui_info.h"
#include "game.h"

Info::Info(world *_one,QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
    one=_one;
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&Info::close);
    ui->money->setText(QString::fromStdString(std::to_string((one->get_paper())->get_money())));
    ui->trust->setText(QString::fromStdString(std::to_string((one->get_paper())->get_trust())));
}

Info::~Info()
{
    delete ui;
}
