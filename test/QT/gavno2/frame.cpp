#include "frame.h"
#include "ui_frame.h"
#include "game.h"
Frame::Frame(std::vector<game_event*>::iterator _begin, std::vector<game_event*>::iterator _end, std::vector<game_event*>* _polosi, world *_one, QMainWindow *_main, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
    end=_end;
    one=_one;
    main=_main;
    begin=_begin;
    //desc=_desc;
    polosi=_polosi;
    update_polosi();
    QObject::connect(ui->remove,&QPushButton::clicked,this,&Frame::pop_polosi);
    ui->desc_1->setText(QString::fromStdString((*begin)->get_desc()));
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
void Frame::closeEvent(QCloseEvent *){
    main->show();
}
void Frame::pop_polosi(){
    if(polosi->size()>0)
        polosi->pop_back();
    update_polosi();
}

void Frame::update_polosi(){
    QLabel *paper[3];
    paper[0]=ui->polosa1;
    paper[1]=ui->polosa2;
    paper[2]=ui->polosa3;
    int i=0;
    for(auto it=polosi->begin();it!=polosi->end();it++,i++)
        (paper[i])->setText(QString::fromStdString((*it)->get_desc()));
    switch (i) {
    case 0:
        (paper[i])->setText(QString::fromStdString("Полоса 1"));
        (paper[i+1])->setText(QString::fromStdString("Полоса 2"));
        (paper[i+2])->setText(QString::fromStdString("Полоса 3"));
        break;
    case 1:
        (paper[i])->setText(QString::fromStdString("Полоса 2"));
        (paper[i+1])->setText(QString::fromStdString("Полоса 3"));
        break;
    case 2:
        (paper[i])->setText(QString::fromStdString("Полоса 3"));
    default:
        break;
    }

}

bool Frame::eventFilter(QObject *watched, QEvent *event){
    if(watched==ui->event_1){
        if(event->type()==QEvent::Enter){
            ui->desc_1->show();
            ui->desc_pict_1->show();
            ui->truthful->setText(QString::fromStdString(std::to_string((*begin)->get_change_truthfulness())));
    }
        if(event->type()==QEvent::MouseButtonPress){//сделать не пресет эвенты
            if(polosi->size()<3){
                polosi->push_back(*begin);
                this->update_polosi();

            }
        }
        if(event->type()==QEvent::Leave){
            ui->desc_1->hide();
            ui->desc_pict_1->hide();
            ui->truthful->setText(QString::fromStdString(std::to_string(0)));}
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
