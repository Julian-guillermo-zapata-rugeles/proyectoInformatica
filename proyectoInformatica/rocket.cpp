#include "rocket.h"

Rocket::Rocket(qreal x, qreal y):movimientos(y)
{
    //status_saltando = true;
    timeRocket = new QTimer();
    pixRocket = new QPixmap(":/multimedia/proyectiles/ROCKET0000.png");
    this->setRotation(-90);
    setScale(0.2);
    this->setPos(x,y);
    connect(timeRocket,SIGNAL(timeout()),this,SLOT(actualizarR()));
    timeRocket->start(50);
    intervaloSuma =0.3;
    velocidadY= 90 * sin((90*3.1416)/180);
}

Rocket::~Rocket()
{
    scene()->addItem(new Animaciones(pos().x(),pos().y(),9));
    scene()->removeItem(this);
}

QRectF Rocket::boundingRect() const
{
    return QRectF(-563/2,-226/2,563,226);
}

void Rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-563/2,-226/2,*pixRocket,0,0,563,226);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Rocket::actualizarR()
{
    if(status_saltando == true){
        saltar();
        setPos(pos().x(),posY);
    }
    else {
        delete this;
    }
}
