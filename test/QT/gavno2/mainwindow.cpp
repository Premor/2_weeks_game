
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "logic.cpp"
#include "frame.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //init_world();
    init_event();
    init_event_desc(&desc);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::v_gorod);
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::next_day);
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::new_frame);
    QObject::connect(ui->start_game,&QPushButton::clicked,this,&MainWindow::begin_game);
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

   // ui->pushButton_2->setText(QString::fromStdString(std::to_string(g.get_incom())));
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();

}

void MainWindow::init_event(){
    game_event *first=new game_event(1);
    all_event.push_back(first);
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
    Frame *f=new Frame(all_event.begin(),all_event.end(),&polosi_gazeti,&desc,&one,this);
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



