#include "difchoose.h"
#include "ui_difchoose.h"
#include "MyWin.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>

DifChoose::DifChoose(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DifChoose)
{
    ui->setupUi(this);
    resize(1095,631);

    QMessageBox::information(this
                             , QString::fromLocal8Bit("Introduction")
                             , QString::fromUtf8("吃大豆子得两分\n吃小豆子得一分\n按空格键暂停/开始\n按esc键退出游戏"));



    QPushButton *button_easy=new QPushButton(this);
    QIcon easy;
    easy.addPixmap(QPixmap(":/DIfChoose/easy_button.png"));
    button_easy->setIcon(easy);
    button_easy->setIconSize(QSize(300,200));
    button_easy->setStyleSheet("QPushButton{border:0px;}");
    button_easy->move(400,300);
    connect(button_easy,SIGNAL(clicked(bool)),this,SLOT(Jump_easy()));


    QPushButton *button_mid =new QPushButton(this);
    QIcon mid;
    mid.addPixmap(QPixmap(":/DIfChoose/mid_button.png"));
    button_mid->setIcon(mid);
    button_mid->setIconSize(QSize(300,200));
    button_mid->setStyleSheet("QPushButton{border:0px;}");
    button_mid->move(600,300);
    connect(button_mid,SIGNAL(clicked(bool)),this,SLOT(Jump_mid()));


    QPushButton *button_dif =new QPushButton(this);
    QIcon dif;
    dif.addPixmap(QPixmap(":/DIfChoose/dif_button.png"));
    button_dif->setIcon(dif);
    button_dif->setIconSize(QSize(200,200));
    button_dif->setStyleSheet("QPushButton{border:0px;}");
    button_dif->move(850,300);
    connect(button_dif,SIGNAL(clicked(bool)),this,SLOT(Jump_dif()));
}

DifChoose::~DifChoose()
{
    delete ui;
}

void DifChoose::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/DIfChoose/diffchoose_bg.png");
    painter.drawPixmap(0,0,width(),height(),pix);
}


void DifChoose::Jump_easy()
{
    MyWin *p=new MyWin;
    p->mode=1;
    p->show();
    this->close();
}

void DifChoose::Jump_mid()
{
    MyWin *p=new MyWin;
    p->mode=2;
    p->show();
    this->close();
}

void DifChoose::Jump_dif()
{
    MyWin *p=new MyWin;
    p->mode=3;
    p->show();
    this->close();
}


