#include "proyectil.h"

proyectil::proyectil(bool dir, short *puntos)
{
    //this->setRect(0,0,10,10);
    //this->setPixmap(QPixmap(":/multimedia/pixmap_disparo_sol.png"));
    // opacidad :
    //      No hemos definido aún si usaremos opacidad para simular algunas condiciones de iluminación
    //      sin embargo se dejará indicado
    //this->setOpacity();
    //

    this->setTransformOriginPoint(this->boundingRect().center());
    this->direccion = dir ;
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverProyectil()));
    timer->start(10);
    puntosP = puntos;
}

void proyectil::moverProyectil()
{
    if(direccion){
        setPos(x()+7,y());
    }
    else{
        setPos(x()-7,y());
    }
    if(pos().x()>1300 + this->boundingRect().width() or pos().x() < 0 ){
        scene()->removeItem(this);
        delete this;
#ifdef DEBUG_PROYECTIL
        qDebug() << "Proyectil eliminado de la pantalla ";
#endif
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
            *puntosP = *puntosP+4;
            scene()->removeItem(this); // eliminamos la bala
            delete elementosColisionables[i]; // eliminamos el enemigo gigante
            delete this;
            break;
            }

        if(typeid (*(elementosColisionables[i]))==typeid (Aves)){
            *puntosP = *puntosP+8;
            scene()->removeItem(this); // eliminamos la bala
            delete elementosColisionables[i]; // eliminamos el enemigo gigante
            delete this;
            break;
            }
        }
}
