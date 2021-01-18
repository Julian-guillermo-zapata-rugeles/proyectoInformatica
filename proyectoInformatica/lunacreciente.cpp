#include "lunacreciente.h"

lunaCreciente::lunaCreciente()
{
    this->setPixmap(QPixmap(":/multimedia/lunaCreciente.png"));
    this->setPos(-500,-300);
    //this->setTransformOriginPoint(this->boundingRect().center());
    this->escalaLunar=0.5;
    this->setScale(escalaLunar);
    connect(timer,SIGNAL(timeout()),this,SLOT(crecer()));
    timer->start(20);
}

void lunaCreciente::crecer()
{
    this->setScale(escalaLunar);
    //escalaLunar=escalaLunar+0.0010;
    this->setPos(pos().x()+10,pos().y());
    if(pos().x()>1500){
        scene()->removeItem(this);
        delete this;
    }
}
