#include "timeGame.h"
#include <QFont>
#include <QFontDatabase>

timeGame::timeGame(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    this->impulsos = 0;
    this->timeCount = 10;
    this->levelworld = 0 ;
    this->disparos=0;
    this->vidaRestante = 100;
    QString user_name = "";

    int id = QFontDatabase::addApplicationFont(":/multimedia/Fuentes/CHERL.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(timeCount));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("CHERL",15));
    startTimer(1000);
}

void timeGame::decrease()
{
    if(0 != timeCount){
        timeCount --;
        /*
        Agregé el usuario al incio
        este se usará para identificar al jugador durante la partida y posterior almacén de datos
         */
        setPlainText("Usuario : "+user_name+QString("\nResiste : ") + QString::number(timeCount)+"\nNivel : "+ QString::number(levelworld)
                     +"\nDisparos : "+QString::number(disparos)
                +"\nVida Restante :"+QString::number(vidaRestante)+"%\n"+"Impulsos : "+QString::number(impulsos));
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

void timeGame::setDisparos(short value)
{
    disparos = value;
}

short timeGame::getVidaRestante() const
{
    return vidaRestante;
}

void timeGame::setUser_name(const QString &value)
{
    user_name = value;
}

void timeGame::setImpulsos(short value)
{
    impulsos = value;
}

short timeGame::getDisparos() const
{
    return disparos;
}

void timeGame::setVidaRestante(short value)
{
    vidaRestante = value;
}

void timeGame::timerEvent(QTimerEvent *event)
{
    decrease();
    Q_UNUSED(event);
}
