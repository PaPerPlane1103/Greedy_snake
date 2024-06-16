#include "Snake.h"
#include "difchoose.h"
#include <stdlib.h>
#include <time.h>


Snake::Snake()
{
    // 初始化蛇身结点，蛇身长度为2
    vector<int> temp_node = { 0,1 };
    snake_node.push_back(temp_node);
    temp_node = { 1,1 };
    snake_node.push_back(temp_node);

    // 初始化蛇头朝向右边
    direction = 'R';

    // 初始化蛇头坐标
    head_x = 3;
    head_y = 3;

    // 初始化食物坐标
    food1_x = rand()%36;
    food1_y = rand()%21;
    food2_x = rand()%40;
    food2_y = rand()%30;
    mapFlag[119] = 2;

    // 初始化游戏得分
    score = 0;

    // 初始化地图标志
    for (size_t i = 0; i < snake_node.size(); i++)
    {
        int body_site = 16 * snake_node[i][1] + snake_node[i][0];
        mapFlag[body_site] = 0;
    }

}

int Snake::moveSnake()
{
    // 根据方向移动蛇头
    if (direction == 'U') head_y--;
    else if (direction == 'D') head_y++;
    else if (direction == 'L') head_x--;
    else head_x++;

    // 若移动不合法，吃到自己或撞墙
    int head_site =  31*head_y + head_x;
    if (head_x < 0 || head_x>36.5 || head_y < 0 || head_y>21) {
        return 0;
    }

    // 若遇见食物，进行吃食物操作
    if (head_x==food1_x && head_y==food1_y)//小豆子
    {
        mapFlag[head_site] = 0;
        vector<int> temp_node = { head_x,head_y };
        snake_node.push_back(temp_node);
        snake_length++;
        score++;
        return 2;
    }

    if (head_x==food2_x && head_y==food2_y)//大豆子
    {
        mapFlag[head_site] = 0;
        vector<int> temp_node = { head_x,head_y };
        snake_node.push_back(temp_node);
        snake_node.push_back(temp_node);
        snake_length+=2;
        score+=2;
        return 2;
    }

    // 通过以上两种情况判断，即蛇头移动到空白区域
    // 将蛇尾对应标志地图置为1，蛇头置为0
    int temp_site = snake_node[0][1] * 16 + snake_node[0][0];
    mapFlag[temp_site] = 1;
    mapFlag[head_site] = 0;

    // 将蛇头加入数组，并删除蛇尾
    vector<int> temp_node = { head_x,head_y };
    snake_node.push_back(temp_node);
    snake_node.erase(snake_node.begin());
    return 1;
}
//生成新食物
void Snake::newFood1()
{
    srand((unsigned)time(NULL));
    int site_food = rand() % (256 - snake_length);
    int i = 0;
    for (; i < 256; i++) {
        if (mapFlag[i] == 1) {
            site_food--;
            if (site_food == -1) break;
        }
    }
    food1_x = i % 16;
    food1_y = i / 16;
    mapFlag[i] = 2;

}

void Snake::newFood2()
{
    srand((unsigned)time(NULL));
    int site_food = rand() % (256 - snake_length);
    int i=0;
    for (; i < 256; i++) {
        if (mapFlag[i] == 1) {
            site_food--;
            if (site_food == -1) break;
        }
    }
    food2_x = rand()% 36;
    food2_y = rand()%16;
    mapFlag[i] = 3;

}
