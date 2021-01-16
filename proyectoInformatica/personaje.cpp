#include "personaje.h"
#include "proyectil.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

personaje::personaje(){
    this->setRect(0,0,30,30);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(30,560);
    this->dir = true ;
}


//
void personaje::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        if(pos().x()>0){
            setPos(x()-10,y());
            dir=false;
        }
    }

    if(event->key() == Qt::Key_D){
        if(pos().x()<1300-30){
        setPos(x()+10,y());
        dir=true;
        }
     }

    if(event->key() == Qt::Key_W){
        setPos(x(),y()-10);
    }
    if(event->key() == Qt::Key_Space){
        // disparo desde el personaje
        proyectil *disparo = new proyectil(dir);
        qDebug() <<"posicion x "<< this->x();
        qDebug() <<"posicion y "<< this->y();
        scene()->addItem(disparo);
        disparo->setPos(this->x(),this->y());
        sonido->setMedia(QUrl("qrc:/multimedia/laser1.mp3"));
        sonido->play();
    }
}

qreal personaje::getLastPosition()
{
    return pos().x();
}

