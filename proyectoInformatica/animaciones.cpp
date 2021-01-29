#include "animaciones.h"

Animaciones::Animaciones(qreal posx, qreal posy, short tipo, bool v)
{
    /*
    Constructor :
        en esta sección se usará el tipo de animación que se presentará
        todos los sprites presentan diferentes dimensiones
        por ello cada elección cargará el pixmap y sus dimensiones no genéricas

    */
    if(tipo == 1){
        // Esta animación se usará para la sangre al morir un enemigo
        deadpix = new QPixmap(":/multimedia/animaciones/bloodSp.png");
        this->limite = 600;
        this->ancho = 100;
        this->alto = 100;
    }

    if(tipo == 2){
        // Esta animación se usará para la explosión de asteroides o saltos
        deadpix = new QPixmap(":/multimedia/animaciones/hitSprite.png");
        this->limite = 6500;
        this->ancho = 500;
        this->alto = 500;
        this->setScale(0.5);
    }

    if(tipo == 3){
        // esta animación se usará para la muerte del zombie gigante
        // esta recibe además un booleano que representa la dirección
        // para generar la animación muerte en el sentido correcto

        deadpix = new QPixmap(":/multimedia/zombieGigante/zombDie.png");
        this->limite = 2000;
        this->ancho = 153.8;
        this->alto = 118;
        this->setScale(1.05);
    }

    if(tipo == 4){
        // Este sprite se usará para las explosiones pequeñas , sin embargo se cuenta
        // con un pixmap grande del mismo tipo de ser necesario
        deadpix = new QPixmap(":/multimedia/animaciones/minixplot.png");
        this->limite = 335;
        this->ancho = 47.85;
        this->alto = 50;
    }

    //Animaciones de muertes de las dos Aves
    if(tipo == 5){
        // Este sprite se usará para las explosiones pequeñas , sin embargo se cuenta
        // con un pixmap grande del mismo tipo de ser necesario
        deadpix = new QPixmap(":/multimedia/aves/dieBird1.png");
        this->limite = 13785;
        this->ancho = 919;
        this->alto = 912;
        setScale(0.15);
        caer = true;
    }

    if(tipo == 6){
        // Este sprite se usará para las explosiones pequeñas , sin embargo se cuenta
        // con un pixmap grande del mismo tipo de ser necesario
        deadpix = new QPixmap(":/multimedia/aves/DieBird2.png");
        this->limite = 2012;
        this->ancho = 201.2;
        this->alto = 300;
        setScale(0.5);
        caer = true;
    }

    // establecemos la ubicación del sprite (basada en la que recibimos por constructor)
    // que representa el lugar donde muere el enemigo/asteroide/etc
    setPos(posx, posy);


    tiempoVida->start(100); // el tiempo de vida será la tasa de refresco de los cuadros
    connect(tiempoVida,SIGNAL(timeout()),this,SLOT(actualizar()));
    //this->setTransformOriginPoint(this->boundingRect().center());
    if(v == true){
        setTransform(QTransform(-1, 0, 0, 1, 0, 0));
    }
    if(caer == true){
        ground = ground - posy;
        caida = ground/(limite/ancho);
    }
}



Animaciones::~Animaciones()
{
    /*
     el destructor tendrá unicamente como objetivo
     eliminar de memoria y de la escena respectivamente
    */
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
    /*
    IMPORTANTE:
        esta función usará el pixmap asignado en el constructor
        lo recorrerá una vez y lanzará el llamado al destructor
        la animación puede ser o no prolongada dependiendo al numero de cuadros
        que esta pueda tener
    */
    if(caer == true){
        setPos(pos().x(),pos().y()+caida);
    }
    this->update();
    if(frame < limite){
        frame += ancho;
    }
    else {
        // llamado a destruirse si sobrepasamos el limite asignado para cada sprite
        delete this;
    }
}


void Animaciones::actualizar()
{
    // slot que ejecuta la función animar
    animar();
}
