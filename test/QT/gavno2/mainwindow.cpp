
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "logic.cpp"
#include "frame.h"
#include "info.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //init_world();
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
    game_event *first=new game_event(1);
    all_event.push_back(first);
    first=new game_event(2);
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
    QDate date=(ui->calendarWidget)->selectedDate();
    date=date.addDays(Q_INT64_C(1));
    (ui->calendarWidget)->setSelectedDate(date);


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



