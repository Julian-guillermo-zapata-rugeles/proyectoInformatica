#include "personaje.h"
#include "mainwindow.h"

bala * personaje::crearDisparo()
{

    shoot = new bala(this->posX,this->posY,1,50,130,20);
    return  shoot;
}

void personaje::actualizar()
{
    this->setPos(posX,posY);
    this->saltar();

}

personaje::personaje(signed short posX, signed short posY, signed short angle, unsigned short velInit, signed short ancho, signed short alto):
    Movimiento(posX,posY,angle,velInit)
{
    this->ancho=ancho;
    this->alto=alto;
    this->setPos(posX,posY);
}

QRectF personaje::boundingRect() const
{
    return QRectF(posX,posY,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

