#include "enemigo.h"
#include "personaje.h"


enemigo::enemigo(qreal lastPosition):movimientos(560)
{
    // constructor
    this->setRect(0,0,30,50); // establecer dimensiones del personaje 30 x 50
    qDebug() << "Generacion : Enemigo común ";
    srand(time(NULL));

    // inicialización de atributos
    this->last_position=lastPosition;

    // inicialización de reloj y slots
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverEnemigo()));
    timer->start(60);

    // llamado a metodos para personalizar el objeto creado
    // se asignará a travez de argumentos variaciones para este objeto
    // pasados por valor
    asignarCaracteristicas();

}


enemigo::~enemigo()
{
    // este destructor eliminará automaticamente el personaje de la escena dando así la oportunidad
    // elimar únicamente de la memoria (en caso de eliminar de la escena en otra clase)
    // se advertirá sobre la inexistencia del objeto en pantalla. NO deberia afectar.

    scene()->removeItem(this);
    qDebug() << "Eliminación : Enemigo común";
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
    /*
        Este método está encargado del movimiento del personaje
        Actualmente el enemigo se mueve en dirección hacia un punto (ultimo conocido)
        del personaje. se pretende que el enemigo además describa otros movimientos
        de forma inesperada (poco predecible para el jugador )
        Estos movimientos deben estar aquí :

            0) cambiarAnimación() FIJA //
            1) movimiento horizontales (implementados)

    */

    if(last_position  < pos().x()){
        setPos(x()-5,pos().y());
    }
    else if(last_position > pos().x()){
        setPos(x()+5,pos().y());
    }

    else{
        // que hacer si ya estoy en el punto  //
        // cambio de pixmap  ... etc  //
    }

    cambiarAnimacion(); // FIJA
}




void enemigo::cambiarAnimacion()
{
    // Este método se encarga de refrescar el personaje mediante el llamado del TIMER
    // --> x --> x1 --> x2 --> x3 --> de forma horizontal (avanzando por columnas).
     /*
        para corregir la animación que se desplaza hacia la derecha e izquierda
        es necesario que algunas iteraciones se hagan al reveź. por estar razón
        el atributo direction : determinará en qué secuencia se motrará el pixmap.
    */

    if(direction==false){
        columnas=columnas+145.8;
        if (columnas>=2185){
            columnas=0;
        }
    }
    if(direction==true){
        columnas=columnas-145.8;
        if (columnas<=5){
            columnas=2185-ancho;
        }
    }
     this->update(-ancho/2,-alto/2,ancho,alto);

}




void enemigo::asignarCaracteristicas()
{
    // Este método se encarga de asignar caracteristicas al Enemigo
    // algunas son de tipo aleatorios como la posición de spaw
    // NEXT :
    //        se buscará implementar la aparición de un zoombie en pantalla
    //        sin aparición lateral

    short int aleatorio = 1+rand() %10;

    if(aleatorio%2==0){
        //  zombie candidato #1

        this->ancho=145.8;
        this->alto=150;
        this->columnas=0;
        this->direction=false; // el zombie irá hacia la izquierda

        setPos(1300,590 - this->rect().height());
        pixmap_zombie = new QPixmap(":/multimedia/zombies/zombie_hachaGrande.png");
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/zombie_gruendo.mp3"));
        sonido->play();

    }

    else{
        // zombie candidato #2
        this->ancho=145.8;
        this->alto=150;
        this->columnas=2185;
        this->direction=true; // el zombie irá hacia la derecha

        setPos(-30 , 590 -this->rect().height());
        pixmap_zombie = new QPixmap(":/multimedia/zombies/zombie_hachaGrande_izq.png");
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/zombie-demon-spawn.mp3"));
        sonido->play();
    }
}

