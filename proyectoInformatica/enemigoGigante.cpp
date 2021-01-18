#include "enemigoGigante.h"

enemigoGigante::enemigoGigante(qreal lastPosition , bool saltando_ ):movimientos(560)
{

    srand(time(NULL));
    this->setRect(0,0,50,100);
    this->last_position=lastPosition;
    this->disparosSoportados=5;
    this->intervaloSuma=0.1;
    status_saltando=saltando_;
    saltando=saltando_;
    sonido->stop();
    sonido->setMedia(QUrl("qrc:/multimedia/suspensoCreciente.mp3"));
    sonido->play();


    short int aleatorio = 1+rand() %10;

    if(aleatorio%2==0){
        setPos(1300, 590- this->rect().height());
        dir=false;
    }
    else{
        setPos(-300 , 590 - this->rect().height());
        dir=true;
    }
    timer->start(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(moverEnemigo()));
}

enemigoGigante::~enemigoGigante()
{
    // se pretende agregar aquí el objeto de bonus
    // para que al crearse este tome las posiciones del enemigo gigante.
    scene()->addItem(new bonus_municion(this->pos().x(),this->pos().y()));
    scene()->removeItem(this);
    qDebug()<< " personaje gigante eliminado " ;
}



void enemigoGigante::moverEnemigo()
{
    status_saltando=saltando;
    saltar();
    if(dir==true){
        if(status_saltando){
            setPos(pos().x()+5,posY);
        }
        else{
            setPos(pos().x()+5,pos().y());
        }

    }
    else{
        if(status_saltando){
         setPos(pos().x()-5,posY);
        }
        else{
         setPos(pos().x()-5,pos().y());
        }
    }
    if(pos().x()>1400 || pos().x()<-400){
        delete this;
    }
    /*
    if(last_position < pos().x()){
        setPos(x()-1,y());
    }
    else if(last_position> pos().x()){
        setPos(x()+1,y());
    }
    */
}

/*
void enemigo::disparar()
{
    proyectil *disparo = new proyectil(false);
    scene()->addItem(disparo);
    disparo->setPos(this->x(),this->y());
}
*/
