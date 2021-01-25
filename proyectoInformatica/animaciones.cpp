#include "animaciones.h"

Animaciones::Animaciones(qreal posx, qreal posy, short tipo)
{
    if(tipo == 1){
        deadpix = new QPixmap(":/multimedia/animaciones/bloodSp.png");
    }
    if(tipo == 2){
        deadpix = new QPixmap(":/multimedia/animaciones/hitSprite.png");
    }
    if(tipo == 3){
        deadpix = new QPixmap(":/multimedia/animaciones/xplot.png");
    }
    setPos(posx, posy);
    this->ancho = 100;
    this->alto = 100;

}

Animaciones::~Animaciones()
{
    scene()->removeItem(this);
    delete this;
    qDebug() << "Animacion terminada "<<endl;
}

QRectF Animaciones::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Animaciones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*deadpix,frame,0,ancho,alto);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Animaciones::animar()
{

}

void Animaciones::actualizar()
{

}
