#include "personaje.h"



QRectF personaje::boundingRect() const
{
    return QRectF(posX,posY,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}
