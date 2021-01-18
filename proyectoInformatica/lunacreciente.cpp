#include "lunacreciente.h"

lunaCreciente::lunaCreciente()
{
    this->setPixmap(QPixmap(":/multimedia/lunaCreciente.png"));
    this->setPos(-100,-100);
    //this->setTransformOriginPoint(this->boundingRect().center());
    this->escalaLunar=0.1;
    this->setScale(escalaLunar);
    connect(timer,SIGNAL(timeout()),this,SLOT(crecer()));
    timer->start(20);
}

void lunaCreciente::crecer()
{
    this->setScale(escalaLunar);
    escalaLunar=escalaLunar+0.0005;
    this->setPos(pos().x()+2,pos().y());
    if(pos().x()>1800){
        scene()->removeItem(this);
        delete this;
    }
}
