#include "enemigo.h"

enemigo::enemigo()
{
    srand(time(NULL));
    this->setRect(0,0,30,50);
    short int aleatorio = 1+rand() %10;
    if(aleatorio%2==0){
        setPos(1300,560);
    }
    else{
        setPos(-30 , 560);
    }
    //timer->start(5000);
    //connect(timer,SIGNAL(timeout()),this,SLOT(disparar()));
}

void enemigo::moverEnemigo(float position)
{
    if(position < pos().x()){
        setPos(x()-10,y());
    }
    else if(position> pos().x()){
        setPos(x()+10,y());
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
