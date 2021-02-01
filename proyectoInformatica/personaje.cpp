#include "personaje.h"


short personaje::getDisparos_disponibles() const
{
    return disparos_disponibles;
}

void personaje::setState(std::string estado)
{
    if (estado == "stand"){
        fila = 0;
    }
    else if (estado == "walk") {
        fila = 131;
    }
    else if (estado == "run") {
        fila =262;
    }
    else if (estado == "jump") {
        fila =393;
    }
    else if (estado == "shoot") {
        fila =524;
    }
    else if (estado == "attack") {
        fila =655;
    }
    else if (estado == "slide") {
        fila =786;
    }
    else if (estado == "hit") {
        fila =917;
    }
    else if (estado == "fly") {
        fila =1048;
    }
    else if (estado == "die") {
        fila =1179;
    }
}

void personaje::actualizarEstado()
{
    if(stateSlide == true){
        if(dir == false && pos().x()-30>0){
            setPos(pos().x()-30,pos().y());
        }
        if(dir == true && pos().x()+30<1300){
            setPos(pos().x()+30,pos().y());
        }
    }

    columna = columna+ancho;

    if (columna > limite){
        columna=0;
        stateShoot = false;
        if(flying == true){
            impulsos -= 1;
            qDebug()<< "salte, debo restar"<<endl;
        }
        stateSlide = false;
        stateKatana= false;
        flying = false;
    }

    this->update(-ancho/2,-alto/2,ancho,alto);

}


QRectF personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixPersonaje,columna,fila,ancho,alto);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(option)
    Q_UNUSED(widget)
}


bool personaje::getPressKey() const
{
    return pressKey;
}

void personaje::setPressKey(bool value)
{
    pressKey = value;
}

bool personaje::getStateShoot() const
{
    return stateShoot;
}

short personaje::getVida_disponible() const
{
    return vida_disponible;
}

short personaje::getImpulsos() const
{
    return impulsos;
}

short personaje::getPuntos() const
{
    return puntos;
}

void personaje::setPuntos(short value)
{
    puntos = value;
}

void personaje::setDisparos_disponibles(short value)
{
    disparos_disponibles = value;
}

void personaje::setVida_disponible(short value)
{
    vida_disponible = value;
}

personaje::personaje():movimientos(550){
    /*
        método contructor
        en principio el personaje cuenta con 5 disparos
        y se ubica en la siguiente dirección.
    */

    this->pressKey=false;
    this-> stateShoot=false;
    this-> stateSlide=false;
    this-> stateKatana = false;
    this-> flying=false;
    this-> puntos=0,
    this->limite = 1550;
    this->impulsos =3;
    this->setRect(0,0,100,131);
    this->setPos(600,550);
    this->dir = true ;
    this->status_saltando=true;
    this->status_gravitatorio=false;
    this->disparos_disponibles=10;
    this->ancho = 130.08;
    this->alto = 131;
    this->fila = 0;
    this->columna = 0;
    this->vida_disponible=100;
    this->sonido->setVolume(30);
    this->pixPersonaje = new QPixmap(":/multimedia/personaje/playerSprite.png");
    this->setState("stand");
    this->GlobalPuntos=&puntos;
}

// función del keypressEvent
/*
    Dotar de movimiento báscio sin desaceleracíon (se planea implementar)
    REPORTE :

*/

void personaje::teclas(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        pressKey = true;
        // Condición movimiento izquierda :
        //      movimiento del personaje hacia la izquierda
        //       status_gravitatorio :
        //          si el personaje está en estado de gravedad su movimiento
        //          lateral se verá impedido (avanza menos)

        //      NOTA: se puede simplificar el conjunto de instrucciones para acortar código
        if(pos().x()>0){
            // si no existe estado de gravedad el personaje se mueve normalmente
            if(status_gravitatorio==false){
                setPos(x()-10,y());
                setTransform(QTransform());
                if(disparos_disponibles > 0){
                    setState("run");
                }
                else {
                    setState("walk");
                }
            }
            else{
                // bajo efecto de gravedad (avance lateral)
                setPos(x()-1,y());
                if(disparos_disponibles > 0){
                    setState("run");
                }
                else {
                    setState("walk");
                }
            }
            // establece la dirección en la que mira el personaje para crear
            // la bala en esa dirección
            dir=false;
        }
    }

    if(event->key() == Qt::Key_D){
        pressKey = true;
        if(pos().x()<1300-30){
            if(status_gravitatorio==false){
                setPos(x()+10,y());
                setTransform(QTransform(-1, 0, 0, 1, 0, 0));
                if(disparos_disponibles > 0){
                    setState("run");
                }
                else {
                    setState("walk");
                }
            }
            else{
                // bajo efecto de gravedad
                setPos(x()+1,y());
                if(disparos_disponibles > 0){
                    setState("run");
                }
                else {
                    setState("walk");
                }
            }
            dir=true;
        }
    }

    if(event->key() == Qt::Key_W){
        /*
        Evento de salto : se establece en verdadero ()
        */
        setStatus_saltando(true);
        setState("jump");
    }


    if(event->key() == Qt::Key_Space){
        stateShoot = true;
        columna = 0;
        /*
          este segmento genera un disparo y lo agrega a la escena
          también se genera un sonido que simula el disparo
        */
        if(disparos_disponibles>=0){
            proyectil *disparo = new proyectil(dir,GlobalPuntos);
            disparo->setPixmap(QPixmap(":/multimedia/proyectiles/proyectilPersonaje.png"));
            scene()->addItem(disparo);
            setState("shoot");
            disparo->setPos(this->x()+10,this->y());
            // se añade a la escena y se ubica en la posición del personaje
            // zona de sonidos y descuento de proyectiles //
            // sonido de descarga (sin munición)
            sonido->stop();
            sonido->setMedia(QUrl("qrc:/multimedia/laser1.mp3"));
            sonido->play();
            disparos_disponibles=disparos_disponibles-1;
        }
        else{
            stateShoot = true;
            stateKatana=true;
            sonido->stop();
            sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/espadaSamurai.mp3"));
            sonido->play();
            setState("attack");
        }
    }

    if(event->key() == Qt::Key_S){
        stateShoot = true;
        stateSlide = true;
        columna=655;
        if(status_saltando == true){
            flying = true;
            setState("fly");
        }
        else{
            setState("slide");
        }
    }
    if(event->key() == Qt::Key_F){
#ifdef DEBUG_PERSONAJE
        qDebug()<< "Puntaje: "<<puntos<<endl;
#endif
        if(puntos > 10){
            puntos -= 10;
            scene()->addItem(new Rocket(pos().x(),pos().y()));
        }
    }
}


void personaje::teclas2(QKeyEvent *event)
{
    if(event->key() == Qt::Key_J){
        pressKey = true;
        // Condición movimiento izquierda :
        //      movimiento del personaje hacia la izquierda
        //       status_gravitatorio :
        //          si el personaje está en estado de gravedad su movimiento
        //          lateral se verá impedido (avanza menos)

        //      NOTA: se puede simplificar el conjunto de instrucciones para acortar código
        if(pos().x()>0){
            // si no existe estado de gravedad el personaje se mueve normalmente
            if(status_gravitatorio==false){
                setPos(x()-10,y());
                setTransform(QTransform());
                if(disparos_disponibles > 0){
                    setState("run");
                }
                else {
                    setState("walk");
                }
            }
            else{
                // bajo efecto de gravedad (avance lateral)
                setPos(x()-1,y());
                if(disparos_disponibles > 0){
                    setState("run");
                }
                else {
                    setState("walk");
                }
            }
            // establece la dirección en la que mira el personaje para crear
            // la bala en esa dirección
            dir=false;
        }
    }

    if(event->key() == Qt::Key_L){
        pressKey = true;
        if(pos().x()<1300-30){
            if(status_gravitatorio==false){
                setPos(x()+10,y());
                setTransform(QTransform(-1, 0, 0, 1, 0, 0));
                if(disparos_disponibles > 0){
                    setState("run");
                }
                else {
                    setState("walk");
                }
            }
            else{
                // bajo efecto de gravedad
                setPos(x()+1,y());
                if(disparos_disponibles > 0){
                    setState("run");
                }
                else {
                    setState("walk");
                }
            }
            dir=true;
        }
    }

    if(event->key() == Qt::Key_I){
        /*
        Evento de salto : se establece en verdadero ()
        */
        setStatus_saltando(true);
        setState("jump");
    }


    if(event->key() == Qt::Key_B){
        stateShoot = true;
        columna = 0;
        /*
          este segmento genera un disparo y lo agrega a la escena
          también se genera un sonido que simula el disparo
        */
        if(disparos_disponibles>=0){
            proyectil *disparo = new proyectil(dir,GlobalPuntos);
            disparo->setPixmap(QPixmap(":/multimedia/proyectiles/proyectilPersonaje.png"));
            scene()->addItem(disparo);
            setState("shoot");
            disparo->setPos(this->x()+10,this->y());
            // se añade a la escena y se ubica en la posición del personaje
            // zona de sonidos y descuento de proyectiles //
            // sonido de descarga (sin munición)
            sonido->stop();
            sonido->setMedia(QUrl("qrc:/multimedia/laser1.mp3"));
            sonido->play();
            disparos_disponibles=disparos_disponibles-1;
        }
        else{
            stateShoot = true;
            stateKatana=true;
            sonido->stop();
            sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/espadaSamurai.mp3"));
            sonido->play();
            setState("attack");
        }
    }

    if(event->key() == Qt::Key_K){
        stateShoot = true;
        stateSlide = true;
        columna=655;
        if(status_saltando == true){
            flying = true;
            setState("fly");
        }
        else{
            setState("slide");
        }
    }
}

qreal personaje::getLastPosition()
{
    /* retorna la posición actual del personaje
     esta se usará para que los enemigos lo persigan
        NOTA :
            DEBEMOS IMPLEMENTAR LA MANERA DE QUE CÁDA ENEMIGO COMÚN PUEDA ENTERARSE EN TÓDO MOMENTO
            QUE EL PERSONAJE ESTÁ EN OTRA UBICACIÓN
            PARA ASÍ GENERAR QUE LO PERSIGAN.

     */
    qreal x=pos().x();
    return x;
}

void personaje::eventHandler()
{
    /*
    EL EVENTHANDLER del personaje pretende suplir las necesidades de timer
    este método será publico y permite llamar a las acciones del personaje
    (METODO TEMPORAL POR MOMENTO) mientras buscamos una solución al timer

    */

    saltar(); // método heredado de movimiento
    //gravitar(); // método heredado de movimiento

    // el movimiento parabolico se lleva a cabo con angulo de 90
    // se podrá implementar disparos en otros angulos variando el angulo y velocidad
    // se pretende sobrecargar el constructor de movimiento para otros objetos

    if(status_saltando==true){
        this->setPos(pos().x(),posY);
    }
    /*
    if(status_gravitatorio==true || status_gravitatorio==false){
        this->setPos(pos().x(),posY);
    }

    COLISIÓN CON LOS BONUS O BOX
    esta sección verifica si el personaje colisiona con el bonus
    de ser así añade nueva munición  y elimina de la escena y memoria el bonus

    */
    QList<QGraphicsItem *> elementosColisionables  = collidingItems() ;

    for(int i=0;i< elementosColisionables.size();i++){
        // balas que colisionan con los enemigos
        if(typeid (*(elementosColisionables[i]))==typeid (bonus_municion)){
            disparos_disponibles=disparos_disponibles+5;
            scene()->removeItem(elementosColisionables[i]);
            delete elementosColisionables[i];
            break;
        }
        //BonusRocket
        if(typeid (*(elementosColisionables[i]))==typeid (BonusRocket)){
            delete elementosColisionables[i];
            puntos += 2;
            break;
        }
        //BonusRocket
        /*
        if(typeid (*(elementosColisionables[i]))==typeid (Rocket)){
            vida_disponible -= 0.8;
            delete elementosColisionables[i];
            break;
        */
        if(typeid (*(elementosColisionables[i]))==typeid (enemigo)){
            vida_disponible=vida_disponible-0.1;
            if(stateKatana){
                delete elementosColisionables[i];
            }
            break;
        }

        if(typeid (*(elementosColisionables[i]))==typeid (enemigoGigante)){
            vida_disponible=vida_disponible-0.5;
            if(stateKatana){
                  delete elementosColisionables[i];
              }
              break;
        }
        if(typeid (*(elementosColisionables[i]))==typeid (asteroides)){
            vida_disponible-=0.4;
            break;
        }

        if(typeid (*(elementosColisionables[i]))==typeid (Aves)){
            vida_disponible=vida_disponible-0.3;
            if(stateKatana){
                delete elementosColisionables[i];
            }
            break;
        }

        if(typeid (*(elementosColisionables[i]))==typeid (Planeta)){
            vida_disponible=vida_disponible-0.4;
            break;
        }
    }
}

