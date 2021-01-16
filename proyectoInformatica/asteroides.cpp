#include "asteroides.h"

asteroides::asteroides()
{

    //this->setRect(0,0,200,200);
    this->setPixmap(QPixmap(":/multimedia/pixmap_asteroide.png"));
    this->setTransformOriginPoint(this->boundingRect().center());
    //setScale();
    setPos(1+rand()%1200,-1500);
    sonido->stop();
    sonido->setMedia(QUrl("qrc:/multimedia/suspenso1.mp3"));
    sonido->play();
    rotationAngle = 0;
    qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(5);
}


void asteroides::moverAsteroide()
{
    setPos(x(),y()+1);

    // rotación del asteroide
    // este rotará sobre su eje y dará efecto
    // TESTING
    setRotation(rotationAngle);
    if(rotationAngle<359){
        rotationAngle=rotationAngle+2;
    }
    else{
        rotationAngle=0;
    }


    if(pos().y() > 560 ){
        qDebug() << "asteroide eliminado";
        sonido->stop();
        sonido->setMedia(QUrl("qrc:/multimedia/explosion1.mp3"));
        sonido->play();
        scene()->removeItem(this);
        delete this;
    }

}
