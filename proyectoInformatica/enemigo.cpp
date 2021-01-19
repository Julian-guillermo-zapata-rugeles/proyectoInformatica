#include "enemigo.h"
#include "personaje.h"

enemigo::enemigo(qreal lastPosition):movimientos(560)
{
    qDebug() << "sonido de zoombie emitido ";


    srand(time(NULL));
    qDebug() << "enemigo generado";
    this->setRect(0,0,30,50);
    this->last_position=lastPosition;
    short int aleatorio = 1+rand() %10;

    if(aleatorio%2==0){
        setPos(1300,590 - this->rect().height());
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/zombie_gruendo.mp3"));
        sonido->play();
    }

    else{
        setPos(-30 , 590 -this->rect().height());
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/zombie-demon-spawn.mp3"));
        sonido->play();
    }

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverEnemigo()));
    timer->start(5);

}

enemigo::~enemigo()
{
    scene()->removeItem(this);
    qDebug() << " enemigo eliminado ";
}


void enemigo::moverEnemigo()
{

    if(last_position  < pos().x()){
        setPos(x()-2,pos().y());
    }
    else if(last_position > pos().x()){
        setPos(x()+2,pos().y());
    }
    else{
        // acción del enemigo //
    }
}


