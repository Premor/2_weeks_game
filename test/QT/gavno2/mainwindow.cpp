
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "logic.cpp"
#include "frame.h"
#include "info.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //init_world();
    QMediaPlaylist *playlist=new QMediaPlaylist();
    playlist->addMedia(QUrl::fromLocalFile("1.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("2.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("3.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("4.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer *player = new QMediaPlayer;
    player->setPlaylist(playlist);
    //player->setMedia(QUrl::fromLocalFile("10.mp3"));
    player->setVolume(10);
    player->play();


    init_event();
    //init_event_desc(&desc);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::v_gorod);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::next_day);
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::new_frame);
    QObject::connect(ui->start_game,&QPushButton::clicked,this,&MainWindow::begin_game);
    QObject::connect(ui->pushButton_4,&QPushButton::clicked,this,&MainWindow::info);
    ui->picture->hide();
    ui->pushButton_3->setStyleSheet("border-image: url(:/images/btn_bottom.png) stretch;");
    ui->pushButton_2->setStyleSheet("border-image: url(:/images/btn_bottom.png) stretch;");
    ui->pushButton->setStyleSheet("border-image: url(:/images/btn_bottom.png) stretch;");
    ui->picture->setPixmap(QPixmap(":/images/map.png"));
    ui->bg->setPixmap(QPixmap(":/images/bg.jpg"));
    ui->calendarWidget->hide();
    ui->pushButton_3->setFixedSize(100,30);
    ui->pushButton->setFixedSize(100,30);
    ui->pushButton_2->setFixedSize(100,30);
    ui->pushButton_4->setFixedSize(100,30);

   // ui->pushButton_2->setText(QString::fromStdString(std::to_string(g.get_incom())));
    ui->pushButton->hide();
    ui->pushButton_4->hide();
    ui->polosa1->hide();
    ui->polosa2->hide();
    ui->polosa3->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();

}

void MainWindow::init_event(){
    game_event *first;
    for(int i=one.get_day()*4-3;i<=one.get_day()*4;i++){
    first=new game_event(i);
    all_event.push_back(first);}

}
void MainWindow::showEvent(QShowEvent *){
    update_polosi();
}
void MainWindow::info(){
    Info *f=new Info(&one);
    f->show();
}

void MainWindow::update_polosi(){
    QLabel *paper[3];
    paper[0]=ui->polosa1;
    paper[1]=ui->polosa2;
    paper[2]=ui->polosa3;
    int i=0;
    for(auto it=polosi_gazeti.begin();it!=polosi_gazeti.end();it++,i++)
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

MainWindow::~MainWindow()
{
    delete ui;
   // for ()

}
void MainWindow::new_frame(){
    Dialog *dl=new Dialog(&one);
    dl->show();
}

void MainWindow::next_day(){
    if(polosi_gazeti.size()<3){

    }
        else{
    QDate date=(ui->calendarWidget)->selectedDate();
    date=date.addDays(Q_INT64_C(1));
    (ui->calendarWidget)->setSelectedDate(date);
    game_event *buf[3];
    auto it=polosi_gazeti.end();
    int i=3;
    do{
        --it;
        --i;
        buf[i]=*it;
    }while(it!=polosi_gazeti.begin()||i!=0);
    polosi_gazeti.clear();
    //
    one.get_paper()->add_money(-500);
    one.get_nat()->change_stat(50.);
    one.get_soc()->change_stat(-50.);
    //
    one.get_nat()->change_stat(buf[0]->get_change_wealth_nat()+buf[1]->get_change_wealth_nat()*0.8+buf[2]->get_change_wealth_nat()*0.6);
    one.get_soc()->change_stat(buf[0]->get_change_wealth_soc()+buf[1]->get_change_wealth_soc()*0.8+buf[2]->get_change_wealth_soc()*0.6);
    one.get_nat()->change_relation(buf[0]->get_change_relation_nat()+buf[1]->get_change_relation_nat()*0.8+buf[2]->get_change_relation_nat()*0.6);
    one.get_soc()->change_relation(buf[0]->get_change_relation_soc()+buf[1]->get_change_relation_soc()*0.8+buf[2]->get_change_relation_soc()*0.6);
    one.get_paper()->add_money((int)(buf[0]->get_incom()+buf[1]->get_incom()*0.8+buf[2]->get_incom()*0.6));
    one.get_paper()->change_trust(buf[0]->get_change_truthfulness()+buf[1]->get_change_truthfulness()*0.8+buf[2]->get_change_truthfulness()*0.6);
    one.new_day();
    all_event.clear();
    init_event();
    update_polosi();
        end_game();}
}
void MainWindow::end_game(){
    if(one.get_day()>7||one.get_paper()->get_money()<0||one.get_nat()->get_relation()<(-1000))
        this->close();
}

void MainWindow::begin_game(){

    //init();
    /*world one;
    newspaper player;
    society good;
    nation beach;
    other_org org;*/
}

void MainWindow::v_gorod(){
    Frame *f=new Frame(all_event.begin(),all_event.end(),&polosi_gazeti,&one,this);
    this->hide();
    f->show();


}


/*void MainWindow::on_pushButton_clicked()
{
    g=gavno();
    (ui->label)->setText(QString::fromStdString(std::to_string(g)));
    QWidget::window();
}*/
/*void MainWindow::s1(int i)
{
    g=i;
   // (ui->label)->setText(QString::fromUtf8("gavno"));

}*/
//



