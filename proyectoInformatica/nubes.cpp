#include "nubes.h"

nubes::nubes()
{
    srand(time(NULL));
    generarAspecto();

    if((0+rand()%10)% 2 ==0 ){
        setPos(-800,20+rand()% 200);
        dir = true;
    }
    else{
        setPos(1300, 20 + rand()%200);
        dir = false ;
    }
    timer->start(100);
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
    // aun no tenemos más aspectos de nube.
    if((0+rand()%10)%2==0){
        this->setPixmap(QPixmap(":/multimedia/pixmap_nube_grade.png"));
    }
    else{
        this->setPixmap(QPixmap(":/multimedia/pixmap_nube_grade.png"));
    }
    // fin del condicionamiento
}

void nubes::moverNubes()
{
    if(dir==true){
        setPos(pos().x()+5,pos().y());
    }
    else{
        setPos(pos().x()-5,pos().y());
    }

    if(pos().x()<-900 || pos().x() > 1500){
        scene()->removeItem(this);
        delete this;
    }
}
