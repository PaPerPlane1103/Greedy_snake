#include "food.h"

food::food() {}

void food::addfood()
{
    reward=QRectF(
        rand()%(1905/20)*20,
        rand()%(631/20)*20,
        nodewidth,nodeheight);
}

void confood::draw_confood()
{
   QPainter painter;
   QPen pen;
   QBrush brush;
   pen.setColor(Qt::red);
   brush.setColor(Qt::red);
   brush.setStyle(Qt::SolidPattern);
   painter.setPen(pen);
   painter.setBrush(brush);
   painter.drawEllipse(reward);
}

void bigfood::draw_bigfood()
{
    QPainter painter;
    QBrush brush;
    QColor rancolor2(rand()%256,rand()%256,rand()%256);
    brush.setColor(rancolor2);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(QPen(Qt::darkBlue));
    painter.setBrush(brush);
    painter.drawEllipse(reward);
}


