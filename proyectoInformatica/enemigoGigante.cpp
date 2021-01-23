#include "enemigoGigante.h"

void enemigoGigante::asignarCaracteristicas()
{
    sonido->stop();
    sonido->setMedia(QUrl("qrc:/multimedia/suspensoCreciente.mp3"));
    sonido->play();
    this->saltando=false;
    short int aleatorio = 1+rand() %10;
    //aleatorio=0;
    if(aleatorio%2==0){
        setPos(1300, 550-this->boundingRect().height());
        this->direction=false;
        this->columnas=0;
        this->alto=150;
        this->ancho=100;
        pixmap_zombie = new QPixmap(":/multimedia/zombieGigante/corredorMini.png");

    }
    else{
        setPos(-300 , 550 - this->boundingRect().height());
        this->direction=true;
        this->columnas=1700;
        this->alto=150;
        this->ancho=100;
        pixmap_zombie = new QPixmap(":/multimedia/zombieGigante/corredorMiniIzquierda.png");

    }
    this->setScale(0.8);
}

enemigoGigante::enemigoGigante(qreal lastPosition , bool saltando_ ):movimientos(560)
{

    srand(time(NULL));
    this->setRect(0,0,50,50);
    this->last_position=lastPosition;
    this->disparosSoportados=5;
    this->intervaloSuma=0.1; 
    status_saltando=saltando_;

    timer->start(20);
    connect(timer,SIGNAL(timeout()),this,SLOT(moverEnemigo()));
    asignarCaracteristicas();
}

enemigoGigante::~enemigoGigante()
{
    // se pretende agregar aquí el objeto de bonus
    // para que al crearse este tome las posiciones del enemigo gigante.
    scene()->addItem(new bonus_municion(this->pos().x(),this->pos().y()));
    scene()->removeItem(this);
    qDebug()<< " personaje gigante eliminado " ;
}



void enemigoGigante::moverEnemigo()
{
    status_saltando=saltando;
    saltar();
    if(direction==true){
        if(status_saltando){
            setPos(pos().x()+10,posY);
        }
        else{
            setPos(pos().x()+10,pos().y());
        }

    }
    else{
        if(status_saltando){
         setPos(pos().x()-10,posY);
        }
        else{
         setPos(pos().x()-10,pos().y());
        }
    }
    if(pos().x()>1400 || pos().x()<-400){
        delete this;
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
