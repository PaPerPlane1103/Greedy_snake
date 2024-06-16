#ifndef FOOD_H
#define FOOD_H

#include <QRectF>
#include <QPaintEvent>
#include <QPainter>

class food
{
public:
    food();
    void addfood();
    QRectF reward;

    int nodewidth = 20;
    int nodeheight = 20;
    QRectF getrect()
    {
        return reward;
    }

};


class confood:public food
{
public:
    confood(){};
    int nodewidth = 20;
    int nodeheight = 20;
    void draw_confood();
};

class bigfood:public food
{
public:
    bigfood(){};
    int nodewidth=30;
    int nodeheight=30;
    void draw_bigfood();
};


#endif // FOOD_H
