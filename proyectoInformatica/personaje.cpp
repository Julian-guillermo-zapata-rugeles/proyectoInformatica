#include "personaje.h"


personaje::personaje():movimientos(575){
    this->setRect(0,0,30,30);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(600,560);
    this->dir = true ;
    this->disparos_disponibles=5;

}


//

void personaje::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        if(pos().x()>0){
            if(status_gravitatorio==false){
                setPos(x()-10,y());
            }
            else{
                // bajo efecto de gravedad
                setPos(x()-1,y());
            }
            dir=false;
        }
    }

    if(event->key() == Qt::Key_D){
        if(pos().x()<1300-30){
            if(status_gravitatorio==false){
                setPos(x()+10,y());
            }
            else{
                // bajo efecto de gravedad
                setPos(x()+1,y());
            }
            dir=true;
        }
    }

    if(event->key() == Qt::Key_W){
        setStatus_saltando(true);
    }
    if(event->key() == Qt::Key_Space){
        // disparo desde el personaje
        if(disparos_disponibles>=0){
            proyectil *disparo = new proyectil(dir);
            qDebug() <<"posicion x "<< this->x();
            qDebug() <<"posicion y "<< this->y();
            scene()->addItem(disparo);
            disparo->setPos(this->x(),this->y());
            sonido->setMedia(QUrl("qrc:/multimedia/laser1.mp3"));
            sonido->play();
            disparos_disponibles=disparos_disponibles-1;
        }
        else{
            sonido->stop();
            sonido->setMedia(QUrl("qrc:/multimedia/cargar_arma.mp3"));
            sonido->play();
        }
    }
}

qreal personaje::getLastPosition()
{
    return pos().x();
}

void personaje::eventHandler()
{

    saltar();
    gravitar();

    if(status_saltando==true){
        this->setPos(pos().x(),posY);
    }
    if(status_gravitatorio==true || status_gravitatorio==false){
        this->setPos(pos().x(),posY);
    }

    QList<QGraphicsItem *> elementosColisionables  = collidingItems() ;

    for(int i=0;i< elementosColisionables.size();i++){
        // balas que colisionan con los enemigos
        if(typeid (*(elementosColisionables[i]))==typeid (bonus_municion)){
                disparos_disponibles=disparos_disponibles+5;
                scene()->removeItem(elementosColisionables[i]);
                delete elementosColisionables[i];
                break;
            }
    }
}

