#include "bonus_municion.h"

bonus_municion::bonus_municion(qreal x , qreal y)
{
    this->setPos(x,580-this->boundingRect().height());
    this->setPixmap(QPixmap(":/multimedia/pixmap_asteroide.png"));
    timer->start(10000);
    qDebug()<<"caja generada en  "<<pos().x() << " " << pos().y() ;
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
}

void bonus_municion::destruirCaja()
{
    timer->stop();
    scene()->removeItem(this);
    delete this;
}
