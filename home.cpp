#include "home.h"
#include "./ui_home.h"
#include "difchoose.h"

Home::Home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);

    resize(1095,631);

    QPushButton *button =new QPushButton(this);
    QIcon start;
    start.addPixmap(QPixmap(":/Home/Start.jpg"));
    button->setIcon(start);
    button->setIconSize(QSize(400,100));
    button->setStyleSheet("QPushButton{border:0px;}");
    button->move(350,500);

    connect(button,SIGNAL(clicked(bool)),this,SLOT(Jump()));
}

Home::~Home()
{
    delete ui;
}

void Home::Jump()
{
    DifChoose *p=new DifChoose;
    p->show();
    this->close();
}

void Home::paintEvent(QPaintEvent *event)//绘图背景
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Home/homebackground.png");
    painter.drawPixmap(0,0,width(),height(),pix);
}

