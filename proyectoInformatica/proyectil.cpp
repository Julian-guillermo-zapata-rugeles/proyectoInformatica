#include "proyectil.h"

proyectil::proyectil(bool dir)
{
    this->setRect(0,0,10,10);
    this->direccion = dir ;
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverProyectil()));
    timer->start(10);
}

void proyectil::moverProyectil()
{
    if(direccion){
        setPos(x()+5,y());
    }
    else{
        setPos(x()-5,y());
    }
    if(pos().x()>1300 + rect().width() or pos().x() < 0 ){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Proyectil eliminado de la pantalla ";
    }
    QList<QGraphicsItem *> elementosColisionables  = collidingItems() ;
    for(int i=0;i< elementosColisionables.size();i++){

        // balas que colisionan con los enemigos
        if(typeid (*(elementosColisionables[i]))==typeid (enemigo)){
                scene()->removeItem(this); // eliminamos la bala
                delete elementosColisionables[i];
                delete this;
                break;
            }

        // balas que colisionan con los asteroides //
        // unicamente se eliminan las balas //

        if(typeid (*(elementosColisionables[i]))==typeid (asteroides)){
                scene()->removeItem(this);
                delete this;
                break;
                scene()->removeItem(elementosColisionables[i]);
                //delete this;
            }


        // personaje gigante siendo impactado por balas //
        // se debe eliminar la bala y restar un punto del maximo de resistencia del enemigo
        //
        if(typeid (*(elementosColisionables[i]))==typeid (enemigoGigante)){
                scene()->removeItem(this);
                delete this;
                break;
            }
        }

}
