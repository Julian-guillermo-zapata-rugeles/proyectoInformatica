#include "planeta.h"
#include <fstream>

Planeta::Planeta(float posX, float posY, float masa, float radio, float velX, float velY, float AcX, float AcY)
{
    planeta = new Ship(posX, posY, masa, radio, velX, velY, AcX, AcY);
    short int op = 1+rand()%33;
    eleccionPixmap(op);
}

Planeta::~Planeta()
{

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

void Planeta::eleccionPixmap(short opcion)
{
    switch (opcion) {
    case 1:{
        this->setPixmap(QPixmap(":/multimedia/planets/1.png"));
        this->setScale(0.2);
        break;
    }
    case 2:{
        this->setPixmap(QPixmap(":/multimedia/planets/2.png"));
        this->setScale(0.2);
        break;
    }
    case 3:{
        this->setPixmap(QPixmap(":/multimedia/planets/3.png"));
        this->setScale(0.2);
        break;
    }
    case 4:{
        this->setPixmap(QPixmap(":/multimedia/planets/4.png"));
        this->setScale(0.2);
        break;
    }
    case 5:{
        this->setPixmap(QPixmap(":/multimedia/planets/5.png"));
        this->setScale(0.2);
        break;
    }
    case 6:{
        this->setPixmap(QPixmap(":/multimedia/planets/6.png"));
        this->setScale(0.2);
        break;
    }
    case 7:{
        this->setPixmap(QPixmap(":/multimedia/planets/7.png"));
        this->setScale(0.2);
        break;
    }
    case 8:{
        this->setPixmap(QPixmap(":/multimedia/planets/8.png"));
        this->setScale(0.2);
        break;
    }
    case 9:{
        this->setPixmap(QPixmap(":/multimedia/planets/9.png"));
        this->setScale(0.2);
        break;
    }
    case 10:{
        this->setPixmap(QPixmap(":/multimedia/planets/10.png"));
        this->setScale(0.2);
        break;
    }
    case 11:{
        this->setPixmap(QPixmap(":/multimedia/planets/11.png"));
        this->setScale(0.2);
        break;
    }
    case 12:{
        this->setPixmap(QPixmap(":/multimedia/planets/12.png"));
        this->setScale(0.2);
        break;
    }
    case 13:{
        this->setPixmap(QPixmap(":/multimedia/planets/13.png"));
        this->setScale(0.2);
        break;
    }
    case 14:{
        this->setPixmap(QPixmap(":/multimedia/planets/14.png"));
        this->setScale(0.2);
        break;
    }
    case 15:{
        this->setPixmap(QPixmap(":/multimedia/planets/15.png"));
        this->setScale(0.2);
        break;
    }
    case 16:{
        this->setPixmap(QPixmap(":/multimedia/planets/16.png"));
        this->setScale(0.2);
        break;
    }
    case 17:{
        this->setPixmap(QPixmap(":/multimedia/planets/17.png"));
        this->setScale(0.1);
        break;
    }
    case 18:{
        this->setPixmap(QPixmap(":/multimedia/planets/18.png"));
        this->setScale(0.1);
        break;
    }
    case 19:{
        this->setPixmap(QPixmap(":/multimedia/planets/19.png"));
        this->setScale(0.1);
        break;
    }
    case 20:{
        this->setPixmap(QPixmap(":/multimedia/planets/20.png"));
        this->setScale(0.1);
        break;
    }
    case 21:{
        this->setPixmap(QPixmap(":/multimedia/planets/21.png"));
        this->setScale(0.1);
        break;
    }
    case 22:{
        this->setPixmap(QPixmap(":/multimedia/planets/22.png"));
        this->setScale(0.1);
        break;
    }
    case 23:{
        this->setPixmap(QPixmap(":/multimedia/planets/23.png"));
        this->setScale(0.1);
        break;
    }
    case 24:{
        this->setPixmap(QPixmap(":/multimedia/planets/24.png"));
        this->setScale(0.1);
        break;
    }
    case 25:{
        this->setPixmap(QPixmap(":/multimedia/planets/25.png"));
        this->setScale(0.1);
        break;
    }
    case 26:{
        this->setPixmap(QPixmap(":/multimedia/planets/26.png"));
        this->setScale(0.1);
        break;
    }
    case 27:{
        this->setPixmap(QPixmap(":/multimedia/planets/27.png"));
        this->setScale(0.1);
        break;
    }
    case 28:{
        this->setPixmap(QPixmap(":/multimedia/planets/28.png"));
        this->setScale(0.1);
        break;
    }
    case 29:{
        this->setPixmap(QPixmap(":/multimedia/planets/29.png"));
        this->setScale(0.1);
        break;
    }
    case 30:{
        this->setPixmap(QPixmap(":/multimedia/planets/30.png"));
        this->setScale(0.1);
        break;
    }
    case 31:{
        this->setPixmap(QPixmap(":/multimedia/planets/31.png"));
        this->setScale(0.1);
        break;
    }
    case 32:{
        this->setPixmap(QPixmap(":/multimedia/planets/32.png"));
        this->setScale(0.1);
        break;
    }
    case 33:{
        this->setPixmap(QPixmap(":/multimedia/planets/33.png"));
        this->setScale(0.1);
        break;
    }
    }
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
