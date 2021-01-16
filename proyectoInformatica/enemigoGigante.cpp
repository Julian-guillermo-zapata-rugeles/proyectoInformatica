#include "enemigoGigante.h"

enemigoGigante::enemigoGigante()
{
    srand(time(NULL));
    this->setRect(0,0,50,100);
    short int aleatorio = 1+rand() %10;
    if(aleatorio%2==0){
        setPos(1300,450);
    }
    else{
        setPos(-30 , 560);
    }
    //timer->start(5000);
    //connect(timer,SIGNAL(timeout()),this,SLOT(disparar()));
}

void enemigoGigante::moverEnemigo(float position)
{
    if(position < pos().x()){
        setPos(x()-3,y());
    }
    else if(position> pos().x()){
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
