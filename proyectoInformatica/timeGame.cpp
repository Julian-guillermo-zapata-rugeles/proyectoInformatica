#include "timeGame.h"

timeGame::timeGame(QGraphicsItem *parent): QGraphicsTextItem(parent)
{

    timeCount = 10;
    levelworld = 0 ;


    int id = QFontDatabase::addApplicationFont(":/multimedia/Cosmic Blaster.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(timeCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Tiempo",24));
    startTimer(1000);
}

void timeGame::decrease()
{
    if(0 != timeCount){
        timeCount --;
        setPlainText(QString("Resiste : ") + QString::number(timeCount)+"\nNivel : "+ QString::number(levelworld));
    }
}

int timeGame::getTime()
{
    return timeCount;
}

short timeGame::getTimeCount() const
{
    return timeCount;
}

void timeGame::setTimeCount(short value)
{
    timeCount = value;
}

void timeGame::setLevelworld(short value)
{
    levelworld = value;
}

short timeGame::getLevelworld() const
{
    return levelworld;
}

void timeGame::timerEvent(QTimerEvent *event)
{
    decrease();
}
