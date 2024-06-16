#pragma once

#include "Snake.h"
#include <QWidget>
#include <qpainter.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qdebug.h>
#include <QString>
#include <QKeyEvent>
#include <QPixmap>
#include <thread>
#include <functional>
#include <chrono>


class MyWin : public QWidget
{
  Q_OBJECT

public:
  MyWin(QWidget* parent = Q_NULLPTR);
  ~MyWin();

  int mode;
  int time=350;
  QString game_mode;

  Snake* m_snake = new Snake;
  void paintEvent(QPaintEvent*);
  void keyPressEvent(QKeyEvent* event);

  QTimer* timer;

  QColor color[7]={"#FF3300","#FF9900","#FFFF00","#00FF00","#00FFFF","#0066FF","#7F00FF"};

private:
  // �����е�ͼ���Ͻ����꣬���ڵ�ͼ�������ת��
  int begin_x = 0;
  int begin_y = 0;
  // ����ߴ�
  int single_size = 30;


  QLabel* label_score_1;
  QLabel* label_score_2;
  QLabel* label_cur_speed_1;
  QLabel* label_cur_speed_2;
  QLabel* label_speed;

  int pause_flag = 0;
  // ���̵����ڶ��������˻���
  int step_count = 1;
  int step_key_input = 0;

public slots:



};
