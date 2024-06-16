#pragma once

#include <vector>
#include <conio.h>


using namespace std;

class Snake
{
public:
  // 构造函数
  Snake();
  // 蛇身结点
  vector<vector<int>> snake_node;
  // 蛇当前朝向
  char direction;
  // 蛇头坐标
  int head_x;
  int head_y;
  // 食物坐标
  int food1_x;
  int food1_y;
  int food2_x;
  int food2_y;
  // 游戏得分
  int score;

  vector<int> mapFlag{ vector<int>(961,1) };
  int snake_length = 2;

  // 生成新的食物
  void newFood1();
  void newFood2();
  // 移动蛇
  int moveSnake();

};

