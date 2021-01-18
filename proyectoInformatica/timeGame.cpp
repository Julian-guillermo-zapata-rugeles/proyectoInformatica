#include "timeGame.h"

timeGame::timeGame(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    timeCount = 300;

    int id = QFontDatabase::addApplicationFont(":/multimedia/Cosmic Blaster.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(timeCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Tiempo",25));
    startTimer(1000);
}

void timeGame::decrease()
{
    if(0 != timeCount){
        timeCount --;
        setPlainText(QString("") + QString::number(timeCount));
    }
}

int timeGame::getTime()
{
    return timeCount;
}

void timeGame::timerEvent(QTimerEvent *event)
{
    decrease();
}
