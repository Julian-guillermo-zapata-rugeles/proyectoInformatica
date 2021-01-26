#include "planeta.h"

Planeta::Planeta(float posX, float posY, float masa, float radio, float velX, float velY, float AcX, float AcY)
{
    planeta = new Ship(posX, posY, masa, radio, velX, velY, AcX, AcY);
    this->setPixmap(QPixmap(":/multimedia/planets/1.png"));
    this->setScale(0.05);
}

Planeta::~Planeta()
{
    delete planeta;
}

void Planeta::asignarEscala(float s)
{
    escala = s;
}

void Planeta::actualizar(float dt)
{
    if(planeta->getCentro() == true){
        planeta->asignarMov();
    }
    else {
        planeta->calcularPosicion(dt);
        planeta->asignarAceleracion();
        setPos(planeta->getX()*escala, v_lim - planeta->getY() * escala);
    }
}

Ship *Planeta::obtenerCuerpo()
{
    return planeta;
}

/*
QRectF Planeta::boundingRect() const
{
    return QRectF( -1*escala*planeta->getRadio() , -1*escala*planeta->getRadio() , 2*escala*planeta->getRadio() , 2*escala*planeta->getRadio() );
}

void Planeta::paint(QPainter *pintar, const QStyleOptionGraphicsItem *opcion, QWidget *widget)
{
    pintar->setBrush(Qt::white);
    pintar->drawEllipse(boundingRect());
    painter->drawPixmap(-ancho/2,-alto/2,*AvePix,columnas,0,ancho,alto);
    Q_UNUSED(opcion);
    Q_UNUSED(widget);
}
*/
