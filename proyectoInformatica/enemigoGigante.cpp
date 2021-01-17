#include "enemigoGigante.h"

enemigoGigante::enemigoGigante(qreal lastPosition)
{

    srand(time(NULL));
    this->setRect(0,0,50,100);
    this->last_position=lastPosition;
    this->disparosSoportados=5;

    short int aleatorio = 1+rand() %10;

    if(aleatorio%2==0){
        setPos(1300, 590- this->rect().height());
    }
    else{
        setPos(-30 , 590 - this->rect().height());
    }
    timer->start(20);
    connect(timer,SIGNAL(timeout()),this,SLOT(moverEnemigo()));
}

enemigoGigante::~enemigoGigante()
{
    scene()->removeItem(this);
    // se pretende agregar aquí el objeto de bonus
    // para que al crearse este tome las posiciones del enemigo gigante.

    qDebug()<< " personaje gigante eliminado " ;
}



void enemigoGigante::moverEnemigo()
{
    if(last_position < pos().x()){
        setPos(x()-1,y());
    }
    else if(last_position> pos().x()){
        setPos(x()+1,y());
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
