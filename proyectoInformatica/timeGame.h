#ifndef TIME_H
#define TIME_H

#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include <QFontDatabase>

class timeGame: public QGraphicsTextItem
{
public:
    timeGame(QGraphicsItem *parent=0);

    void decrease();
    int getTime();

private:
    short int timeCount;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // TIME_H
