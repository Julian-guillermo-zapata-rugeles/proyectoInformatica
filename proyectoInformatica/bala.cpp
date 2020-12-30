#include "bala.h"
#include <iostream>


bala::bala(signed short posX_, signed short posY_, signed short angle, unsigned short velInit, signed short ancho, signed short alto):
    Movimiento(posX_,posY_,angle,velInit){
    this->setPos(posX_,posY_);
    this->ancho=ancho;
    this->alto=alto;
}

QRectF bala::boundingRect() const
{
    //return QRectF(MovRU::posX,MovRU::posY,ancho,alto);
     return QRectF(posX,posY,ancho,alto);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
