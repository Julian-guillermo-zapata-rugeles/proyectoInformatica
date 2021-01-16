#include "enemigoGigante.h"

enemigoGigante::enemigoGigante(qreal lastPosition)
{

    srand(time(NULL));
    this->setRect(0,0,50,100);
    this->last_position=lastPosition;
    this->disparosSoportados=5;

    short int aleatorio = 1+rand() %10;

    if(aleatorio%2==0){
        setPos(1300, 560- this->rect().height());
    }
    else{
        setPos(-30 , 560 - this->rect().height());
    }
    timer->start(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(moverEnemigo()));
}

void enemigoGigante::moverEnemigo()
{
    if(last_position < pos().x()){
        setPos(x()-3,y());
    }
    else if(last_position> pos().x()){
        setPos(x()+3,y());
    }
}

/*
void enemigo::disparar()
{
    proyectil *disparo = new proyectil(false);
    scene()->addItem(disparo);
    disparo->setPos(this->x(),this->y());
}
*/
