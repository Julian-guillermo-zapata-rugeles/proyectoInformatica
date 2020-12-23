#include "bala.h"


void bala::moverRectilineamente()
{
    this->moverRU();
    this->moving=true;

}

void bala::moverParabolicamente()
{
    this->mover();
    moving=false;
}

bala::bala(signed short posX, signed short posY, signed short angle, unsigned short velInit, signed short ancho, signed short alto):
    MovimientoParabolico(posX,posY,angle,velInit),MovRU(posX,posY,angle,velInit)
{
    this->setPos(posX,posY);
    this->ancho=ancho;
    this->alto=alto;
}

QRectF bala::boundingRect() const
{
    //return QRectF(MovRU::posX,MovRU::posY,ancho,alto);
    if(moving==true){
        return QRectF(MovRU::posX,MovRU::posY,ancho,alto);
    }
    else{
        return QRectF(MovimientoParabolico::posX,MovimientoParabolico::posY,ancho,alto);
    }

}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
