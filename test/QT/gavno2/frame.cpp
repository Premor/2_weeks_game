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
    polosi=_polosi;
    update_polosi();
    QObject::connect(ui->remove,&QPushButton::clicked,this,&Frame::pop_polosi);
    QObject::connect(ui->exit,&QPushButton::clicked,this,&Frame::close);
    ui->desc_1->setText(QString::fromStdString((*begin)->get_desc()));
    ui->desc_1->hide();
    ui->desc_pict_1->hide();
    ui->event_1->installEventFilter(this);
    ui->desc_2->setText(QString::fromStdString((*(begin+1))->get_desc()));
    ui->desc_2->hide();
    ui->desc_pict_2->hide();
    ui->event_2->installEventFilter(this);
    ui->desc_3->setText(QString::fromStdString((*(begin+2))->get_desc()));
    ui->desc_3->hide();
    ui->desc_pict_3->hide();
    ui->event_3->installEventFilter(this);
    ui->desc_4->setText(QString::fromStdString((*(begin+3))->get_desc()));
    ui->desc_4->hide();
    ui->desc_pict_4->hide();
    ui->event_4->installEventFilter(this);
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
            ui->event_marker->hide();
            ui->desc_pict_1->show();
            ui->incom->setText(QString::fromStdString(std::to_string((*begin)->get_incom())));
            ui->truthful->setText(QString::fromStdString(std::to_string((*begin)->get_change_truthfulness())));
            ui->stat_nat->setText(QString::fromStdString(std::to_string((*begin)->get_change_wealth_nat())));
            ui->stat_soc->setText(QString::fromStdString(std::to_string((*begin)->get_change_wealth_soc())));
            ui->relation_nat->setText(QString::fromStdString(std::to_string((*begin)->get_change_relation_nat())));
            ui->relation_soc->setText(QString::fromStdString(std::to_string((*begin)->get_change_relation_soc())));
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
            ui->event_marker->show();
            ui->truthful->setText(QString::fromStdString(std::to_string(0)));
            ui->incom->setText(QString::fromStdString(std::to_string(0)));
            ui->stat_nat->setText(QString::fromStdString(std::to_string(0)));
            ui->stat_soc->setText(QString::fromStdString(std::to_string(0)));
            ui->relation_nat->setText(QString::fromStdString(std::to_string(0)));
            ui->relation_soc->setText(QString::fromStdString(std::to_string(0)));
        }
    }
    if(watched==ui->event_2){
        if(event->type()==QEvent::Enter){
            ui->desc_2->show();
            ui->event_marker_2->hide();
            ui->desc_pict_2->show();
            ui->incom->setText(QString::fromStdString(std::to_string((*(begin+1))->get_incom())));
            ui->truthful->setText(QString::fromStdString(std::to_string((*(begin+1))->get_change_truthfulness())));
            ui->stat_nat->setText(QString::fromStdString(std::to_string((*(begin+1))->get_change_wealth_nat())));
            ui->stat_soc->setText(QString::fromStdString(std::to_string((*(begin+1))->get_change_wealth_soc())));
            ui->relation_nat->setText(QString::fromStdString(std::to_string((*(begin+1))->get_change_relation_nat())));
            ui->relation_soc->setText(QString::fromStdString(std::to_string((*(begin+1))->get_change_relation_soc())));
    }
        if(event->type()==QEvent::MouseButtonPress){//сделать не пресет эвенты
            if(polosi->size()<3){
                polosi->push_back(*(begin+1));
                this->update_polosi();

            }
        }
        if(event->type()==QEvent::Leave){
            ui->desc_2->hide();
            ui->desc_pict_2->hide();
            ui->event_marker_2->show();
            ui->truthful->setText(QString::fromStdString(std::to_string(0)));
            ui->incom->setText(QString::fromStdString(std::to_string(0)));
            ui->stat_nat->setText(QString::fromStdString(std::to_string(0)));
            ui->stat_soc->setText(QString::fromStdString(std::to_string(0)));
            ui->relation_nat->setText(QString::fromStdString(std::to_string(0)));
            ui->relation_soc->setText(QString::fromStdString(std::to_string(0)));
        }
    }
    if(watched==ui->event_3){
        if(event->type()==QEvent::Enter){
            ui->desc_3->show();
            ui->event_marker_3->hide();
            ui->desc_pict_3->show();
            ui->incom->setText(QString::fromStdString(std::to_string((*(begin+2))->get_incom())));
            ui->truthful->setText(QString::fromStdString(std::to_string((*(begin+2))->get_change_truthfulness())));
            ui->stat_nat->setText(QString::fromStdString(std::to_string((*(begin+2))->get_change_wealth_nat())));
            ui->stat_soc->setText(QString::fromStdString(std::to_string((*(begin+2))->get_change_wealth_soc())));
            ui->relation_nat->setText(QString::fromStdString(std::to_string((*(begin+2))->get_change_relation_nat())));
            ui->relation_soc->setText(QString::fromStdString(std::to_string((*(begin+2))->get_change_relation_soc())));
    }
        if(event->type()==QEvent::MouseButtonPress){//сделать не пресет эвенты
            if(polosi->size()<3){
                polosi->push_back(*(begin+2));
                this->update_polosi();

            }
        }
        if(event->type()==QEvent::Leave){
            ui->desc_3->hide();
            ui->desc_pict_3->hide();
            ui->event_marker_3->show();
            ui->truthful->setText(QString::fromStdString(std::to_string(0)));
            ui->incom->setText(QString::fromStdString(std::to_string(0)));
            ui->stat_nat->setText(QString::fromStdString(std::to_string(0)));
            ui->stat_soc->setText(QString::fromStdString(std::to_string(0)));
            ui->relation_nat->setText(QString::fromStdString(std::to_string(0)));
            ui->relation_soc->setText(QString::fromStdString(std::to_string(0)));
        }
    }
    if(watched==ui->event_4){
        if(event->type()==QEvent::Enter){
            ui->desc_4->show();
            ui->event_marker_4->hide();
            ui->desc_pict_4->show();
            ui->incom->setText(QString::fromStdString(std::to_string((*(begin+3))->get_incom())));
            ui->truthful->setText(QString::fromStdString(std::to_string((*(begin+3))->get_change_truthfulness())));
            ui->stat_nat->setText(QString::fromStdString(std::to_string((*(begin+3))->get_change_wealth_nat())));
            ui->stat_soc->setText(QString::fromStdString(std::to_string((*(begin+3))->get_change_wealth_soc())));
            ui->relation_nat->setText(QString::fromStdString(std::to_string((*(begin+3))->get_change_relation_nat())));
            ui->relation_soc->setText(QString::fromStdString(std::to_string((*(begin+3))->get_change_relation_soc())));
    }
        if(event->type()==QEvent::MouseButtonPress){//сделать не пресет эвенты
            if(polosi->size()<3){
                polosi->push_back(*(begin+3));
                this->update_polosi();

            }
        }
        if(event->type()==QEvent::Leave){
            ui->desc_4->hide();
            ui->desc_pict_4->hide();
            ui->event_marker_4->show();
            ui->truthful->setText(QString::fromStdString(std::to_string(0)));
            ui->incom->setText(QString::fromStdString(std::to_string(0)));
            ui->stat_nat->setText(QString::fromStdString(std::to_string(0)));
            ui->stat_soc->setText(QString::fromStdString(std::to_string(0)));
            ui->relation_nat->setText(QString::fromStdString(std::to_string(0)));
            ui->relation_soc->setText(QString::fromStdString(std::to_string(0)));
        }
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
