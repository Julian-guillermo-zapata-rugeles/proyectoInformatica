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

    short getTimeCount() const;
    void setTimeCount(short value);
    void setLevelworld(short value);
    short getLevelworld() const;

    void setDisparos(short value);

private:
    short int timeCount;
    short int levelworld;
    short int disparos;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // TIME_H
