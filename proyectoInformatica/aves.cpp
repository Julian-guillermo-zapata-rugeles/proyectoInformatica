#include "aves.h"


/*
--------------------------------------------------------------------------------------------------
                                CONSTRUCTOR DEFECTO

*/
Aves::Aves()
{
    this->temporal=0;
    this->identity=false;
    this->ancho = 79.6;
    this->alto = 120;
    this->limite = 715;
    this->direction = false;
    pixmapAves = new QPixmap(":/multimedia/aves/flyS.png");
    setPos(1400,450);
    temporizadorAves = new QTimer();
    temporizadorAves->start(40);
    connect(temporizadorAves,SIGNAL(timeout()),this,SLOT(moverAves()));


    velocidad = 150;//80 + rand() % 120;
    amplitud =  5 + rand() % 10;
    generarDireccion();
    this->dir = true;

}




/*
--------------------------------------------------------------------------------------------------
                               CONSTRUCTOR SOBRECARGADO

*/

Aves::Aves(short op)
{
    this->temporal=0;
    identity = true;
    this->ancho = 91;
    this->alto = 131;
    this->limite = 1360;
    this->direction = false;
    pixmapAves = new QPixmap(":/multimedia/aves/aveSenoidal.png");
    setPos(1400,1000);
    temporizadorAves= new QTimer();
    temporizadorAves->start(40);
    connect(temporizadorAves,SIGNAL(timeout()),this,SLOT(moverAvesParabolicas()));

    velocidad = 120 + rand() % 180;
    amplitud =  3 + rand() % 8;
    generarDireccion();
    Q_UNUSED(op);
}






/*
--------------------------------------------------------------------------------------------------
                                DESTRUCTOR DE LA CLASE

*/
Aves::~Aves()
{
    short int num = 1+rand()%4;
    //explosiones disponibles para aves 7 y 10
    if(identity == false){
        switch (num) {
        case 1:{
            scene()->addItem(new Animaciones(pos().x(),pos().y(),10,direction));
            break;
        }
        case 2:{
            scene()->addItem(new Animaciones(pos().x(),pos().y(),7,direction));
            break;
        }
        default:{
            scene()->addItem(new Animaciones(pos().x(),pos().y(),5,direction));
            break;
        }
        }
    }
    else{
        switch (num) {
        case 1:{
            scene()->addItem(new Animaciones(pos().x(),pos().y(),10,direction));
            break;
        }
        case 2:{
            scene()->addItem(new Animaciones(pos().x(),pos().y(),7,direction));
            break;
        }
        default:{
            scene()->addItem(new Animaciones(pos().x(),pos().y(),6,direction));
            break;
        }
        }}
    scene()->removeItem(this);
}






//-------------------------------------------------------------------------------------------
                                    //GRÁFICOS

QRectF Aves::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Aves::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapAves,columnas,0,ancho,alto);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
//-------------------------------------------------------------------------------------------










/*
------------------------------------------------------------------------------------------------//
                                   ALEATORIEDAD
Alternar de forma aleatoria la ubicación del las aves enemigoas

*/
void Aves::generarDireccion()
{
    short int modo = 1+rand() % 2;
    if(modo == 1){
        direction = false;
        setPos(1400,100);
    }
    else{
        direction = true;
        setPos(-100,100);
        setTransform(QTransform(-1, 0, 0, 1, boundingRect().width(), 0));
    }
}










/*
-----------------------------------------------------------------------------------------------//
                                ANIMACIONES DEL SPRITE
Alternar sobre los sprites para dar animación a todos los objetos

*/
void Aves::cambiarAnimacion()
{
    columnas = columnas+ancho;
    if (columnas > limite){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}









/*
-----------------------------------------------------------------------------------------------//
                                    MOVIMIENTOS
movimiento :

*/
void Aves::moverAves()
{
    float dt = 0.02;
    tmp_sumador = tmp_sumador + dt;
    //qDebug()<< " sumador: " <<tmp_sumador<<endl;
    //qDebug()<< " columnas: " <<columnas << "posicion X: "<<pos().x()<<endl;


    if(direction == false){
        setPos(x()-velocidad*dt, y() + amplitud*sin(2*3.1415*tmp_sumador/2));
        setPos(pos().x()-0.5,pos().y());
        //qDebug()<< " velocidad: " <<velocidad<<endl;
    }
    else{
        setPos(x()+velocidad*dt, y() + amplitud*sin(2*3.1415*tmp_sumador/2));
        setPos(pos().x()+0.5,pos().y());
        //qDebug()<< " VELOCIDAD: " <<velocidad<<endl;
    }

    if(pos().x() < -200 || pos().x() > 1400){
        delete this;
    }
    cambiarAnimacion();
    // ------------------ Segmento para la creación de proyectiles tipo asteroides ------------------------ //
    temporal += 40;
    if(temporal > 3000){
        scene()->addItem(new asteroides(pos().x(),pos().y()));
        temporal = 0;
    }
}







/*
----------------------------------------------------------------------------------------------------------//
                                             MOVIMIENTOS #2
Movimiento parabolico : dotar de movimiento de tipo parabólico en aves

*/
void Aves::moverAvesParabolicas()
{
    float dt = 0.02;
    tmp_sumador = tmp_sumador + dt;

    if(direction == false){
        setPos(pos().x()-velocidad*dt , amplitud*sin(3.1415*tmp_sumador/2)+pos().y());
        setPos(pos().x()-0.5,pos().y());
    }
    else{
        setPos(pos().x()+velocidad*dt , amplitud*sin(3.1415*tmp_sumador/2)+pos().y());
        setPos(pos().x()+0.5,pos().y());
    }

    if(pos().x() < -200 || pos().x() > 1400){
        delete this;
    }
    cambiarAnimacion();
}
