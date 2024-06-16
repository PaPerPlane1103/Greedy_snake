#ifndef DIFCHOOSE_H
#define DIFCHOOSE_H

#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class DifChoose;
}

class DifChoose : public QWidget
{
    Q_OBJECT

public:
    explicit DifChoose(QWidget *parent = nullptr);
    ~DifChoose();
    void paintEvent(QPaintEvent *event);


private:
    Ui::DifChoose *ui;

public slots:
    void Jump_easy();
    void Jump_mid();
    void Jump_dif();
};

#endif // DIFCHOOSE_H
