#include "personaje.h"
#include "mainwindow.h"

bala * personaje::crearDisparo()
{
    shoot = new bala(this->Movimiento::posX,this->Movimiento::posY,1,50,20,8);
    std::cout <<"disparo "<<  this->posX << " - "<< this->posY << std::endl;
    return  shoot;
}

void personaje::actualizar()
{
    this->setPos(Movimiento::posX,Movimiento::posY);
    this->saltar();
    //std::cout << "pos X : " << posX<< endl;
    //std::cout << "pos Y : " << posY<< endl;
}

personaje::personaje(signed short int posX_, signed short int  posY_, signed short angle, unsigned short velInit, unsigned short int ancho, unsigned short int alto):
    Movimiento(posX_,posY_,angle,velInit)
{
    this->ancho=ancho;
    this->alto=alto;
}

QRectF personaje::boundingRect() const
{
    return QRectF(this->posX,this->posY,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

