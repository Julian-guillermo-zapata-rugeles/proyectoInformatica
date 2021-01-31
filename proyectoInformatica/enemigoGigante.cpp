#include "enemigoGigante.h"

void enemigoGigante::asignarCaracteristicas()
{
    sonido->stop();
    sonido->setMedia(QUrl("qrc:/multimedia/suspensoCreciente.mp3"));
    sonido->play();
    short int aleatorio = 1+rand() %10;
    //aleatorio=0;

    if(aleatorio%2==0){
        setPos(1300,530);
        this->direction=false;
        this->columnas=0;
        this->alto=150;
        this->ancho=100;
        pixmap_zombie = new QPixmap(":/multimedia/zombieGigante/corredorMini.png");

    }
    else{
        setPos(-300 ,530);
        this->direction=true;
        this->columnas=1700;
        this->alto=150;
        this->ancho=100;
        pixmap_zombie = new QPixmap(":/multimedia/zombieGigante/corredorMiniIzquierda.png");

    }
    //this->setScale(0.8);
}

enemigoGigante::enemigoGigante(qreal lastPosition)
{
    timer = new QTimer();
    sonido = new QMediaPlayer();
    srand(time(NULL));
    this->setRect(0,0,50,50);
    this->last_position=lastPosition;
    this->disparosSoportados=5;

    timer->start(20);
    connect(timer,SIGNAL(timeout()),this,SLOT(moverEnemigo()));
    asignarCaracteristicas();
    sonido->setVolume(30);
}

enemigoGigante::~enemigoGigante()
{
    // se pretende agregar aquí el objeto de bonus
    // para que al crearse este tome las posiciones del enemigo gigante.
    scene()->addItem(new Animaciones(pos().x(),pos().y(),3,direction));
    scene()->addItem(new bonus_municion(this->pos().x(),this->pos().y()));
    scene()->removeItem(this);

#ifdef DEBUG_ENEMIGO_GIGANTE
    qDebug()<< " personaje gigante eliminado " ;
#endif

}


void enemigoGigante::moverEnemigo()
{
    if(direction == false){
        setPos(pos().x()-5,pos().y());
    }
    else {
        setPos(pos().x()+5,pos().y());
    }
    cambiarAnimacion();
}

QRectF enemigoGigante::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void enemigoGigante::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap_zombie,columnas,0,ancho,alto);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}


/*
void enemigo::disparar()
{
    proyectil *disparo = new proyectil(false);
    scene()->addItem(disparo);
    disparo->setPos(this->x(),this->y());
}
*/

void enemigoGigante::cambiarAnimacion()
{
    // Este método se encarga de refrescar el personaje mediante el llamado del TIMER
    // --> x --> x1 --> x2 --> x3 --> de forma horizontal (avanzando por columnas).
     /*
        para corregir la animación que se desplaza hacia la derecha e izquierda
        es necesario que algunas iteraciones se hagan al reveź. por estar razón
        el atributo direction : determinará en qué secuencia se motrará el pixmap.
    */

    if(direction==false){
        columnas=columnas+ancho;
        if (columnas>=1700){
            columnas=0;
        }
    }
    if(direction==true){
        columnas=columnas-ancho;
        if (columnas<=5){
            columnas=1700-ancho;
        }
    }
     this->update(-ancho/2,-alto/2,ancho,alto);
}
