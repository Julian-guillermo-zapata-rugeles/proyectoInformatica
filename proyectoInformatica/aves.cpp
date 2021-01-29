#include "aves.h"

Aves::Aves()
{
    this->ancho = 79.6;
    this->alto = 120;
    this->limite = 715;
    this->direction = false;
    this->AvePix = new QPixmap(":/multimedia/aves/flyS.png");
    this->setPos(1400,450);
    this->velocidad = 150;//80 + rand() % 120;
    this->amplitud =  5 + rand() % 10;
    this->birdAppearance();
    this->dir = true;
    this->senoidal=false;

}

Aves::Aves(short op)
{
    this->ancho = 91;
    this->alto = 131;
    this->limite = 1360;
    this->direction = false;
    this->AvePix = new QPixmap(":/multimedia/aves/aveSenoidal.png");
    this->setPos(1400,1000);
    this->velocidad = 120 + rand() % 180;
    this->amplitud =  3 + rand() % 8;
    this->birdAppearance();
    this->senoidal=true;
    Q_UNUSED(op);
    identity = true;
}

Aves::~Aves()
{
    if(identity == false){
        scene()->addItem(new Animaciones(pos().x(),pos().y(),5,direction));
    }
    else{
        scene()->addItem(new Animaciones(pos().x(),pos().y(),6,direction));
    }
    scene()->removeItem(this);
}

QRectF Aves::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Aves::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*AvePix,columnas,0,ancho,alto);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Aves::birdAppearance()
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

void Aves::cambiarAnimacion()
{
    columnas = columnas+ancho;
    if (columnas > limite){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}





void Aves::advance(int phase)
{
    if(this->senoidal==true){
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
    // ---------   ataque de las aves  ------------ //
        temporal += 40;
        if(temporal > 3000){
            scene()->addItem(new asteroides(pos().x(),pos().y()));
            temporal = 0;
        }
    }
    //-------------------------------------------------------------
    else{

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
}

