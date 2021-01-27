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


    void setTimeCount(short value);
    void setVidaRestante(short value);
    void setLevelworld(short value);
    void setDisparos(short value);

    short getLevelworld() const;
    short getTimeCount() const;
    short getVidaRestante() const;


private:
    short int timeCount;
    short int levelworld;
    short int disparos;
    short int vidaRestante;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // TIME_H
