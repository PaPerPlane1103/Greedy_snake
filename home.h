#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class Home;
}
QT_END_NAMESPACE

class Home : public QWidget
{
    Q_OBJECT

public:
    Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *ui;

private slots:
    void Jump();

protected:
    void paintEvent(QPaintEvent *event);//绘图事件
};
#endif // HOME_H
