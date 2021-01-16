#include "nubes.h"

nubes::nubes()
{
    srand(time(NULL));
    generarAspecto();

    if((0+rand()%10)%2==0){
        setPos(-10,20+rand()%400);
        dir = true;
    }
    else{
        setPos(1010,20+rand()%400);
        dir = false ;
    }
    timer->start(30);
    connect(timer, SIGNAL(timeout()),this,SLOT(moverNubes()));
}

nubes::~nubes()
{
    qDebug() << "nube eliminada (salió de escena) ";
    // otras acciones ...
}

void nubes::generarAspecto()
{
    // podriamos establecer varios pixmaps y generar de forma aleatorio estos mismos
    // para ello bastaria generar un número aleatorio y condicionar la salida.
    if((0+rand()%10)%2==0){
        this->setPixmap(QPixmap(":/multimedia/pixmap_asteroide.png"));
    }
    else{
        this->setPixmap(QPixmap(":/multimedia/pixmap_asteroide_rojo.png"));
    }
    // fin del condicionamiento
}

void nubes::moverNubes()
{
    if(dir==true){
        setPos(pos().x()+5,pos().y());
    }
    else{
        setPos(pos().x()+5,pos().y());
    }
    if(pos().x()<-100 || pos().x() > 1100){
        scene()->removeItem(this);
        delete this;
    }
}
