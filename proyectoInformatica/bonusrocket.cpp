#include "bonusrocket.h"

BonusRocket::BonusRocket(qreal x, qreal y): movimientos(560)
{
    //status_saltando = true;
    timeLife = new QTimer();

    short int op = 1+rand()%3;
    switch (op) {
    case 1:{
        //pixBonus = new QPixmap(":/multimedia/proyectiles/Gem-1.png");
        this->setPixmap(QPixmap(":/multimedia/proyectiles/Gem-1.png"));
        break;
    }
    case 2:{
        //pixBonus = new QPixmap(":/multimedia/proyectiles/Gem-2.png");
        this->setPixmap(QPixmap(":/multimedia/proyectiles/Gem-2.png"));
        break;
    }
    case 3:{
        //pixBonus = new QPixmap(":/multimedia/proyectiles/Gem-3.png");
        this->setPixmap(QPixmap(":/multimedia/proyectiles/Gem-3.png"));
        break;
    }
    }
    this->opacidad = 1;
    setScale(0.06);
    this->setPos(x,y);
    connect(timeLife,SIGNAL(timeout()),this,SLOT(actualizar()));
    timeLife->start(50);
    intervaloSuma =0.6;
    velocidadY= 40 * sin((90*3.1416)/180);
}

BonusRocket::~BonusRocket()
{
    scene()->removeItem(this);
}

void BonusRocket::actualizar()
{
    if(status_saltando == true){
        saltar();
        setPos(pos().x(),posY);
    }
    else{
        lifeTime +=50;
        if(opacidad >= 0){
            opacidad  -= 0.01;
            this->setOpacity(opacidad);
        }
    }
    if(lifeTime >= 5000){
        delete this;
    }
}
