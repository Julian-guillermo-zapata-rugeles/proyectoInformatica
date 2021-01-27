#include "animaciones.h"

Animaciones::Animaciones(qreal posx, qreal posy, short tipo, bool v)
{
    if(tipo == 1){
        deadpix = new QPixmap(":/multimedia/animaciones/bloodSp.png");
        this->limite = 600;
        this->ancho = 100;
        this->alto = 100;
    }
    if(tipo == 2){
        deadpix = new QPixmap(":/multimedia/animaciones/hitSprite.png");
        this->limite = 6500;
        this->ancho = 500;
        this->alto = 500;
        this->setScale(0.5);
    }
    if(tipo == 3){
        deadpix = new QPixmap(":/multimedia/zombieGigante/zombDie.png");
        this->limite = 2000;
        this->ancho = 153.8;
        this->alto = 118;
        this->setScale(1.05);
        if(v == true){
            setTransform(QTransform(-1, 0, 0, 1, 0, 0));
        }
    }
    if(tipo == 4){
        deadpix = new QPixmap(":/multimedia/animaciones/minixplot.png");
        this->limite = 335;
        this->ancho = 47.85;
        this->alto = 50;
    }
    setPos(posx, posy);

    tiempoVida->start(100);
    connect(tiempoVida,SIGNAL(timeout()),this,SLOT(actualizar()));
    //this->setTransformOriginPoint(this->boundingRect().center());
}

Animaciones::~Animaciones()
{
    scene()->removeItem(this);
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
    this->update();
    if(frame < limite){
        frame += ancho;
    }
    else {
        delete this;
    }
}

void Animaciones::actualizar()
{
    animar();
}
