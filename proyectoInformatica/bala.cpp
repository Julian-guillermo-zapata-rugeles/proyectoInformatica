#include "bala.h"
#include <iostream>

bala::bala(short posX, short posY , short ancho, short alto , bool dir):
    cuerpo(posX,posY,ancho,alto)
{
    this->direccion=dir;
}

QRectF bala::boundingRect() const
{
     return QRectF(coordenadaX,coordenadaY,ancho,alto);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawPixmap(posX,posY,*pixmap,0,0,ancho,alto);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(coordenadaX,coordenadaY,ancho,alto);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void bala::adelante()
{
    moverDerecha();
}

void bala::atras()
{
    moverIzquierda();
}

void bala::advance(int phase)
{
    if(direccion){
        this->adelante();
    }
    else{
        this->atras();
    }
}
