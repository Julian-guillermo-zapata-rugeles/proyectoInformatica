#include "asteroides.h"

asteroides::asteroides()
{

    this->setRect(0,0,200,200);
    setPos(1+rand()%1200,-1500);
    sonido->stop();
    sonido->setMedia(QUrl("qrc:/multimedia/suspenso1.mp3"));
    sonido->play();
    qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(30);
}


void asteroides::moverAsteroide()
{
    setPos(x(),y()+5);
    if(pos().y() > 560 ){
        qDebug() << "asteroide eliminado";
        sonido->stop();
        sonido->setMedia(QUrl("qrc:/multimedia/explosion1.mp3"));
        sonido->play();
        scene()->removeItem(this);
        delete this;
    }

}
