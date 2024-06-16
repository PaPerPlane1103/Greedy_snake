#include "MyWin.h"
#include <qpainter.h>
#include <qtimer.h>
#include <QKeyEvent>
#include <qmessagebox.h>
#include <QIcon>
#include <QKeyEvent>
#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QColor>
#include <QWidget>
#include <QPushButton>
MyWin::MyWin(QWidget *parent)
    : QWidget(parent)
{
  resize(1095,631);
  QMessageBox::information(this, QString::fromLocal8Bit(" "), QString::fromLocal8Bit("游戏即将开始"));
/*
  QVBoxLayout laybox;
  laybox.setContentsMargins(0,0,0,0);
  this->setAttribute(Qt::WA_TranslucentBackground);


*/


  this->setWindowFlags(Qt::FramelessWindowHint);

  QFont font("KaiTi", 18);
  //score
  label_score_1 = new QLabel(this);
  label_score_1->setFont(font);
  label_score_1->setText(QString::fromLocal8Bit("游戏得分："));
  label_score_1->setGeometry(950, 10, 100, 30);
  label_score_1->show();
  label_score_2 = new QLabel(this);
  label_score_2->setText(QString::number(m_snake->score));
  label_score_2->setFont(font);
  label_score_2->setGeometry(1050, 16, 40, 20);
  label_score_2->show();



  timer = new QTimer(this);
  timer->start(time);

  QPushButton *add_speed=new QPushButton(this);//加速
  QIcon add;
  add.addPixmap(QPixmap(":/game/add.png"));
  add_speed->setIcon(add);
  add_speed->setIconSize(QSize(60,40));
  add_speed->setFocusPolicy(Qt::NoFocus);
  add_speed->setStyleSheet("QPushButton{border:0px;}");
  add_speed->move(950,50);
  (void)connect(add_speed, &QPushButton::pressed, [=](){
      timer->start(time-=50);
      if (pause_flag == 1) timer->stop();

    });


  QPushButton *cur_speed=new QPushButton(this);//减速
  QIcon cur;
  cur.addPixmap(QPixmap(":/game/jian.png"));
  cur_speed->setIcon(cur);
  cur_speed->setIconSize(QSize(60,40));
  cur_speed->setFocusPolicy(Qt::NoFocus);
  cur_speed->setStyleSheet("QPushButton{border:0px;}");
  cur_speed->move(1000,50);
 (void)connect(cur_speed, &QPushButton::pressed, [=]() {

     timer->start(time+=50);
     if (pause_flag == 1) timer->stop();
  });

      (void)connect(timer, &QTimer::timeout, [=](){
      step_count++;
      if (step_count == INT_MAX - 10) step_count = 1;
      int flag = m_snake->moveSnake();

      QGraphicsDropShadowEffect *effect=new QGraphicsDropShadowEffect(this);
      effect->setBlurRadius(40);
      effect->setColor(color[rand()%7]);

      effect->setOffset(0,0);
      // signal_fun(update_color,25);
      this->setGraphicsEffect(effect);

      label_score_2->setText(QString::number(m_snake->score));

      switch (flag)
      {
      case 0:
          timer->stop();
          QMessageBox::information(this, QString::fromLocal8Bit("Game Over"), QString::fromLocal8Bit("Game Over!"));
          break;

      case 1:
          update();
          break;

      case 2:
          m_snake->newFood1();
          m_snake->newFood2();
          update();

      default:
          break;
      }
  });


}


void MyWin::keyPressEvent(QKeyEvent* event)//键盘监听事件
{
  if (1)
  {
    switch (event->key())
    {
    case Qt::Key_Up:
    case 'w':
    case 'W':
      if (m_snake->direction == 'D') break;
      m_snake->direction = 'U';
      break;
    case Qt::Key_Down:
    case 's':
    case 'S':
      if (m_snake->direction == 'U') break;
      m_snake->direction = 'D';
      break;
    case Qt::Key_Left:
    case 'a':
    case 'A':
      if (m_snake->direction == 'R') break;
      m_snake->direction = 'L';
      break;
    case Qt::Key_Right:
    case 'd':
    case 'D':
      if (m_snake->direction == 'L') break;
      m_snake->direction = 'R';
      break;
    case Qt::Key_Space:
        switch (pause_flag)
        {
            case 0:
            timer->stop();
            pause_flag = 1;
            QMessageBox::information(this, QString::fromLocal8Bit("Pause"), QString::fromLocal8Bit("The Game is Paused"));
            break;
            case 1:
            timer->start(time);
            pause_flag = 0;
            break;
            default:    break;
        }
    break;
    case Qt::Key_Escape:
        this->close();
        break;
    default:    break;
    }
  }
}

// 绘画事件
void MyWin::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/game/playwindow.png");
    painter.drawPixmap(10,10,width()-20,height()-20,pix);


  // body，蛇类绘画控件对象
  QPainter painterSnakeBody(this);
  painterSnakeBody.setPen(Qt::green);
  painterSnakeBody.setBrush(Qt::green);
  painterSnakeBody.setRenderHint(QPainter::Antialiasing);
  int i = 0;
  for (; i < m_snake->snake_node.size()-1; i++)
  {
    int site_x = begin_x + m_snake->snake_node[i][0] * single_size;
    int site_y = begin_y + m_snake->snake_node[i][1] * single_size;
    painterSnakeBody.drawRoundedRect(site_x, site_y, single_size, single_size, 10, 10);
  }


  int site_x = begin_x + m_snake->snake_node[i][0] * single_size;
  int site_y = begin_y + m_snake->snake_node[i][1] * single_size;

  QPainter painterSnakeHead(this);
  QPixmap head;
  head.load(":/game/Head.PNG");
  painterSnakeHead.drawPixmap(site_x , site_y , single_size +4, single_size + 4,head);


  // food
  QPainter painterFood1(this);
  painterFood1.setPen(Qt::red);
  painterFood1.setBrush(Qt::red);
  painterFood1.setRenderHint(QPainter::Antialiasing);
  site_x= begin_x + m_snake->food1_x * single_size;
  site_y= begin_y + m_snake->food1_y * single_size;
  painterFood1.drawRoundedRect(site_x + 2, site_y + 2, single_size - 4, single_size - 4, 10, 10);

  QPainter painterFood2(this);
  QColor color;
  color.setRgb(rand()%256,rand()%256,rand()%256);
  painterFood2.setPen(color);
  painterFood2.setBrush(color);
  painterFood2.setRenderHint(QPainter::Antialiasing);
  site_x= begin_x + m_snake->food2_x * single_size;
  site_y= begin_y + m_snake->food2_y * single_size;
  painterFood2.drawRoundedRect(site_x + 2, site_y + 2, single_size +8, single_size+8, 10, 10);

}


MyWin::~MyWin()
{
}
