#include "personaje.h"
#include "mainwindow.h"

bala * personaje::crearDisparo()
{
    shoot = new bala(this->posX,this->posY,1,50,20,8);
    return  shoot;
}

void personaje::actualizar()
{
    this->setPos(posX,posY);
    this->saltar();

}

personaje::personaje(float posX, float posY, signed short angle, unsigned short velInit, float ancho, float alto):
    Movimiento(posX,posY,angle,velInit)
{
    this->ancho=ancho;
    this->alto=alto;
    this->setPos(posX,posY);
}

QRectF personaje::boundingRect() const
{
    return QRectF(Movimiento::posX/2,Movimiento::posY/2,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    cout<< posX << "  " << posY;
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

