#include "enemigo.h"
#include "personaje.h"


enemigo::enemigo(qreal lastPosition):movimientos(560)
{
    qDebug() << "sonido de zoombie emitido ";


    srand(time(NULL));
    qDebug() << "enemigo generado";
    pixmap_zombie = new QPixmap(":/multimedia/zombies/zombie_hacha.png");
    this->ancho=100;
    this->alto=100;
    this->columnas=0;
    this->setRect(0,0,30,50);
    this->last_position=lastPosition;
    short int aleatorio = 1+rand() %10;

    if(aleatorio%2==0){
        setPos(1300,590 - this->rect().height());
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/zombie_gruendo.mp3"));
        sonido->play();
    }

    else{
        setPos(-30 , 590 -this->rect().height());
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/zombie-demon-spawn.mp3"));
        sonido->play();
    }

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverEnemigo()));
    timer->start(60);

}

enemigo::~enemigo()
{
    scene()->removeItem(this);
    qDebug() << " enemigo eliminado ";
}

QRectF enemigo::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap_zombie,columnas,0,ancho,alto);
}


void enemigo::moverEnemigo()
{

    if(last_position  < pos().x()){
        setPos(x()-5,pos().y());
    }
    else if(last_position > pos().x()){
        setPos(x()+5,pos().y());
    }
    else{
        // acción del enemigo //
    }
    cambiarAnimacion();
}

void enemigo::cambiarAnimacion()
{
    this->update(-ancho/2,-alto/2,ancho,alto);
    columnas=columnas+97;
    if (columnas>=1450){
        columnas=0;
    }
}


