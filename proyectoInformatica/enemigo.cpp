#include "enemigo.h"
#include "personaje.h"


enemigo::enemigo(qreal lastPosition):movimientos(560)
{
    // constructor

    this->setRect(0,0,30,50);
    this->setTransformOriginPoint(this->boundingRect().center());
    // establecer dimensiones del personaje 30 x 50
    qDebug() << "Generacion : Enemigo común ";
    srand(time(NULL));
    this->setScale(0.7);

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
    sonido->setVolume(30);

}

enemigo::~enemigo()
{
    // este destructor eliminará automaticamente el personaje de la escena dando así la oportunidad
    // elimar únicamente de la memoria (en caso de eliminar de la escena en otra clase)
    // se advertirá sobre la inexistencia del objeto en pantalla. NO deberia afectar.
    scene()->addItem(new Animaciones(pos().x(),pos().y(),1));
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
    Q_UNUSED(option)
    Q_UNUSED(widget)
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
    columnas = columnas+ancho;
    if (columnas >= limite){
        columnas=0;
    }
        /*
    if(direction==false){
        columnas = columnas+ancho;
        if (columnas>=limite){
            columnas=0;
        }
    }

    if(direction==true){
        columnas = columnas-ancho;
        if (columnas<=5){
            columnas=limite-ancho;
        }
    }
    */
    qDebug() << "ancho: "<< -ancho/2 << " alto: " << -alto/2 << " ancho positivo: " << ancho << " alto positivo: " << alto <<endl;
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

        this->ancho=97.2;
        this->alto=100;
        this->columnas=0;
        this->direction=false; // el zombie irá hacia la izquierda
        this->limite = 1458;

        setPos(1300,590 - this->rect().height());
        pixmap_zombie = new QPixmap(":/multimedia/zombies/zombie_hacha.png");
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/zombie_gruendo.mp3"));
        sonido->play();

    }

    else{
        // zombie candidato #2
        this->ancho=97.2;
        this->alto=100;
        this->columnas=1458;
        this->limite = 1458;
        this->direction=true; // el zombie irá hacia la derecha

        setPos(-30 , 590 -this->rect().height());
        pixmap_zombie = new QPixmap(":/multimedia/zombies/zombie_hacha_izquierda.png");
        setTransform(QTransform(-1, 0, 0, 1, boundingRect().width(), 0));
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/zombie-demon-spawn.mp3"));
        sonido->play();
    }
}


