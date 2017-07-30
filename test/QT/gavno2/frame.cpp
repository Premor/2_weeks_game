#include "frame.h"
#include "ui_frame.h"
#include "game.h"
Frame::Frame(std::vector<game_event*>::iterator _begin, std::vector<game_event*>::iterator _end, std::vector<game_event*>* polosi, std::vector<event_desc *> *_desc, world *_one, QMainWindow *_main, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
    end=_end;
    one=_one;
    main=_main;
    begin=_begin;
    desc=_desc;
    ui->desc_1->setText(QString::fromStdString((*desc)[0]->desc));
    ui->desc_1->hide();
    ui->desc_pict_1->hide();
    ui->event_1->installEventFilter(this);
    //ui->event_1->setPixmap(QPixmap(":/images/event_1.png"));
    //QObject::connect(ui->event_1,&QLabel::,this,&Frame::hover_1);
    //ui->truthful->setText(QString::fromStdString(std::to_string((*begin)->get_change_truthfulness())));
}
//void Frame::hover_1(){
   // ui->truthful->setText(QString::fromStdString(std::to_string((*begin)->get_change_truthfulness())));
//}
/*
void Frame::enterEvent(QEvent *e){
    if (e->HoverEnter)
         ui->truthful->setText(QString::fromStdString(std::to_string((*begin)->get_change_truthfulness())));
}
void Frame::leaveEvent(QEvent *){
     ui->truthful->setText(QString::fromStdString(std::to_string(0)));
}*/
void Frame::closeEvent(QCloseEvent *event){
    main->show();
}
bool Frame::eventFilter(QObject *watched, QEvent *event){
    if(watched==ui->event_1 && event->type()==QEvent::Enter){
        ui->desc_1->show();
        ui->desc_pict_1->show();
        ui->truthful->setText(QString::fromStdString(std::to_string((*begin)->get_change_truthfulness())));
    }
    if(watched==ui->event_1 && event->type()==QEvent::Leave){
        ui->desc_1->hide();
        ui->desc_pict_1->hide();
        ui->truthful->setText(QString::fromStdString(std::to_string(0)));
    }
    return true;
}

/*void Frame::enterEvent(QEvent *){
    ui->truthful->setText(QString::fromStdString(std::to_string((*begin)->get_change_truthfulness())));
}*/
Frame::~Frame()
{

    delete ui;

}
