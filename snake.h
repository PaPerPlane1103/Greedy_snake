#pragma once

#include <vector>
#include <conio.h>


using namespace std;

class Snake
{
public:
  // ���캯��
  Snake();
  // ������
  vector<vector<int>> snake_node;
  // �ߵ�ǰ����
  char direction;
  // ��ͷ����
  int head_x;
  int head_y;
  // ʳ������
  int food1_x;
  int food1_y;
  int food2_x;
  int food2_y;
  // ��Ϸ�÷�
  int score;

  vector<int> mapFlag{ vector<int>(961,1) };
  int snake_length = 2;

  // �����µ�ʳ��
  void newFood1();
  void newFood2();
  // �ƶ���
  int moveSnake();

};

