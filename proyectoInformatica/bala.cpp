#include "bala.h"
#include <iostream>


bala::bala(signed short int  posX_, signed short int posY_, signed short angle, unsigned short velInit, unsigned short int ancho, unsigned short alto):
    Movimiento(posX_,posY_,angle,velInit){
    this->setPos(posX_,posY_);
    this->ancho=ancho;
    this->alto=alto;
    pixmap = new QPixmap(":/sprite_bala/disparo.png");
}

QRectF bala::boundingRect() const
{
     return QRectF(this->posX,this->posY,ancho,alto);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posX,posY,*pixmap,0,0,ancho,alto);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
