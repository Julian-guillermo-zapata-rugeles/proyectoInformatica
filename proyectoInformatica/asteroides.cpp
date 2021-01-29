#include "asteroides.h"

void asteroides::generarAspecto()
{
    // podriamos establecer varios pixmaps y generar de forma aleatorio estos mismos
    // para ello bastaria generar un número aleatorio y condicionar la salida.
    short int aleatorio = 0 + rand()%3;
    if(aleatorio==0){
        this->setPixmap(QPixmap(":/multimedia/pixmap_asteroide.png"));
    }
    else if(aleatorio==1){
        this->setPixmap(QPixmap(":/multimedia/pixmap_asteroide_rojo.png"));
    }
    else if(aleatorio==2){
        this->setPixmap(QPixmap(":/multimedia/pixmap_asteroide_joven.png"));
    }
    // fin del condicionamiento
    this->setScale(0.5);
}

asteroides::asteroides(bool sound)
{
    long long semilla = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand((unsigned int )semilla);
    //this->setRect(0,0,200,200);
    generarAspecto();
    this->setTransformOriginPoint(this->boundingRect().center());
    //setScale();
    setPos(1+rand()%1200,-1800 + ((1+rand()%500)*-1));
    // reproducir sonido siempre y cuando se indique

    if(sound){
        sonido->stop();
        sonido->setMedia(QUrl("qrc:/multimedia/suspenso1.mp3"));
        sonido->play();
    }
    rotationAngle = 0;
    qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(5);
    sonido->setVolume(30);
}

asteroides::asteroides(short n)
{
    setPos(300,-1000);
    this->setPixmap(QPixmap(":/multimedia/lunaCreciente.png"));
    this->setTransformOriginPoint(this->boundingRect().center());
    this->setScale(2);
    rotationAngle = 0;
    qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(5);
    sonido->setVolume(30);
    Q_UNUSED(n);
}

asteroides::asteroides(qreal x, qreal y)
{
    setPos(x,y);
    this->setPixmap(QPixmap(":/multimedia/proyectiles/bulletEnemy.png"));
    this->setTransformOriginPoint(this->boundingRect().center());
    this->setScale(1.5);
    rotationAngle = 0;
    qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(10);
    fire = true;
}

asteroides::~asteroides()
{ 
    if(fire == true){
        scene()->addItem(new Animaciones(pos().x()+50,pos().y(),4));
    }
    else{
        scene()->addItem(new Animaciones(pos().x()+50,pos().y(),2));
        qDebug() << "asteroide eliminado";
        sonido->stop();
        sonido->setMedia(QUrl("qrc:/multimedia/explosion1.mp3"));
        sonido->play();
    }
    scene()->removeItem(this);
}


void asteroides::moverAsteroide()
{
    setPos(x(),y()+4);

    // rotación del asteroide
    // este rotará sobre su eje y dará efecto
    // TESTING
    setRotation(rotationAngle);
    if(rotationAngle<359){
        rotationAngle=rotationAngle+2.5;
    }
    else{
        rotationAngle=0;
    }


    if(pos().y() > 560 ){
        delete this;
    }

    // capacidad destructiva de los asteroides
    // zona que elimina los objetos que sean impactados
    // en la caida
    // ZONA DE CHOCQUE ASTEROIDES
    QList<QGraphicsItem *> elementosColisionables  = collidingItems() ;
    for(int i=0;i< elementosColisionables.size();i++){
        // balas que colisionan con los enemigos
        if(typeid (*(elementosColisionables[i]))==typeid (enemigo)){
                delete elementosColisionables[i];
                break;
            }
        if(typeid (*(elementosColisionables[i]))==typeid (enemigoGigante)){
                delete elementosColisionables[i];
                break;
            }
    }

}
