#include "bala.h"



bala::bala(signed short posX, signed short posY, signed short angle, unsigned short velInit, signed short ancho, signed short alto):
    Movimiento(posX,posY,angle,velInit){
    this->setPos(posX,posY);
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
