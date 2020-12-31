#include "obstaculo.h"

Obstaculo::Obstaculo(signed short posx, signed short posy, signed short ancho, signed short alto)
{
    this->posX=posx;
    this->posY=posy;
    this->ancho=ancho;
    this->alto=alto;
}

QRectF Obstaculo::boundingRect() const
{
    return QRectF(posX,posY,ancho,alto);
}

void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
