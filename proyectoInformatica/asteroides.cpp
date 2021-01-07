#include "asteroides.h"


asteroides::asteroides(short posX, short posY, short ancho, short alto)
    :cuerpo(posX,posY,ancho,alto)
{

}

QRectF asteroides::boundingRect() const
{
    return QRectF(coordenadaX,coordenadaY,ancho,alto);
}

void asteroides::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void asteroides::advance(int phase)
{
    this->caidaLibre();
}
