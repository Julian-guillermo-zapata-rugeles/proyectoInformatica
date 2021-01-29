#include "proyectil.h"

proyectil::proyectil(bool dir)
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
}

proyectil::~proyectil()
{
    //qDebug() << "Proyectil eliminado de la pantalla "; // DEBUG
    scene()->removeItem(this);
}





void proyectil::advance(int phase)
{
    if(direccion){
        setPos(x()+10,y());
    }
    else{
        setPos(x()-10,y());
    }

    if(pos().x()>1300 + this->boundingRect().width() or pos().x() < 0 ){
        delete this;
    }





    QList<QGraphicsItem *> elementosColisionables  = collidingItems() ;
    for(int i=0;i< elementosColisionables.size();i++){

        // balas que colisionan con los enemigos
        if(typeid (*(elementosColisionables[i]))==typeid (enemigo)){
            delete elementosColisionables[i];
            delete this;
            break;
        }

        // balas que colisionan con los asteroides //
        // unicamente se eliminan las balas //

        if(typeid (*(elementosColisionables[i]))==typeid (asteroides)){
            delete this;
            break;
            scene()->removeItem(elementosColisionables[i]);
            //delete this;
        }


        // personaje gigante siendo impactado por balas //
        // se debe eliminar la bala y restar un punto del maximo de resistencia del enemigo
        //
        if(typeid (*(elementosColisionables[i]))==typeid (enemigoGigante)){
            delete elementosColisionables[i]; // eliminamos el enemigo gigante
            delete this;
            break;
        }
        if(typeid (*(elementosColisionables[i]))==typeid (Aves)){
            delete elementosColisionables[i]; // eliminamos el ave
            delete this;
            break;
        }
    }
}

