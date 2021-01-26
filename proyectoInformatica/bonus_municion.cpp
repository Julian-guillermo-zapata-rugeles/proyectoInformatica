#include "bonus_municion.h"

bonus_municion::bonus_municion(qreal x, qreal y)
{
    this->setPos(x,560-this->boundingRect().height());
    this->setPixmap(QPixmap(":/multimedia/bonus_balas.png"));
    timer->start(10000);
    qDebug()<<"caja generada en  "<<pos().x() << " " << pos().y() ;
    connect(timer,SIGNAL(timeout()),this,SLOT(destruirCaja()));
    Q_UNUSED(y);
}

void bonus_municion::destruirCaja()
{
    timer->stop();
    scene()->removeItem(this);
    qDebug() << "caja eliminada (BONUS)" ;
    delete this;
}
