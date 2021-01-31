#include "asteroides.h"

void asteroides::generarAspecto()
{
    // podriamos establecer varios pixmaps y generar de forma aleatorio estos mismos
    // para ello bastaria generar un número aleatorio y condicionar la salida.
    short int op = 1+rand()%9;
    switch (op) {
    //Meteoro M1
    case 1:{
        this->ancho = 149;
        this->alto = 200;
        this->frame = 1788;
        this->limite = 1788;
        meteoros = new QPixmap(":/multimedia/asteroides/M1.png");
        break;
    }
    //Meteoro M2
    case 2:{
        this->ancho = 151.08;
        this->alto = 201;
        this->frame = 1813;
        this->limite = 1813;
        meteoros = new QPixmap(":/multimedia/asteroides/M2.png");
        break;
    }
    //Meteoro M3
    case 3:{
        this->ancho = 131;
        this->alto = 201;
        this->frame = 1571;
        this->limite = 1571;
        meteoros = new QPixmap(":/multimedia/asteroides/M3.png");
        break;
    }
    //Meteoro m1
    case 4:{
        this->ancho = 74.5;
        this->alto = 100;
        this->frame = 894;
        this->limite = 894;
        meteoros = new QPixmap(":/multimedia/asteroides/m1.png");
        break;
    }
    //Meteoro m2
    case 5:{
        this->ancho = 75.16;
        this->alto = 100;
        this->frame = 902;
        this->limite = 902;
        meteoros = new QPixmap(":/multimedia/asteroides/m1.png");
        break;
    }
    //Meteoro m3
    case 6:{
        this->ancho = 65.16;
        this->alto = 100;
        this->frame = 782;
        this->limite = 782;
        meteoros = new QPixmap(":/multimedia/asteroides/m1.png");
        break;
    }
    case 7:{
        this->ancho = 200;
        this->alto = 150;
        this->frame =0;
        this->limite=0;
        meteoros = new QPixmap(":/multimedia/pixmap_asteroide.png");
        break;
    }
    case 8:{
        this->ancho = 200;
        this->alto = 150;
        this->frame =0;
        this->limite=0;
        meteoros = new QPixmap(":/multimedia/pixmap_asteroide_rojo.png");
        break;
    }
    case 9:{
        this->ancho = 100;
        this->alto = 100;
        this->frame =0;
        this->limite=0;
        meteoros = new QPixmap(":/multimedia/pixmap_asteroide_joven.png");
        break;
    }
}
    if(op <= 6){
        this->rotar=false;
        this->animado=true;
    }
    else{
        this->rotar=true;
        this->animado=false;
        this->setScale(0.5);
    }
}

void asteroides::animarMeteoro()
{
    frame = frame+ancho;
    if (frame >= limite){
        frame=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

asteroides::asteroides(bool sound)
{
    this->caida=1+rand()%5;
    sonido = new QMediaPlayer();
    this->fire=false;
    long long semilla = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand((unsigned int )semilla);
    generarAspecto();
    this->setTransformOriginPoint(this->boundingRect().center());
    setPos(1+rand()%1200,-1800 + ((1+rand()%500)*-1));
    // reproducir sonido siempre y cuando se indique
    if(sound){
        sonido->stop();
        sonido->setMedia(QUrl("qrc:/multimedia/suspenso1.mp3"));
        sonido->play();
    }
    rotationAngle = 0;

#ifdef DEBUG_ASTEROIDE
    qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ;
#endif

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(5);
    sonido->setVolume(30);
}

asteroides::asteroides(short n)
{
    this->caida=4;
    sonido = new QMediaPlayer();
    this->fire=false;
    setPos(300,-1000);
    meteoros = new QPixmap(":/multimedia/lunaCreciente.png");
    this->setTransformOriginPoint(this->boundingRect().center());
    this->setScale(2);
    rotationAngle = 0;

#ifdef DEBUG_ASTEROIDE
    qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ;
#endif

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(5);
    sonido->setVolume(30);
    Q_UNUSED(n);
}

asteroides::asteroides(qreal x, qreal y)
{
    this->caida=4;
    sonido = new QMediaPlayer();
    setPos(x,y);
    meteoros = new QPixmap(":/multimedia/proyectiles/balaAve.png");
    this->setTransformOriginPoint(this->boundingRect().center());
    this->setScale(0.5);
    rotationAngle = 0;

#ifdef DEBUG_ASTEROIDE
    qDebug()<<"Popo del Ave generado en: "<<pos().x() << " " << pos().y() ;
#endif

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(10);
    this->fire = true;
}

asteroides::~asteroides()
{ 
    if(fire == true){
        scene()->addItem(new Animaciones(pos().x()+50,pos().y(),4));
    }
    else{
        scene()->addItem(new Animaciones(pos().x()+50,pos().y(),8));

#ifdef DEBUG_ASTEROIDE
    qDebug() << "asteroide eliminado";
#endif

        sonido->stop();
        sonido->setMedia(QUrl("qrc:/multimedia/explosion1.mp3"));
        sonido->play();
    }
    scene()->removeItem(this);
}

QRectF asteroides::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void asteroides::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*meteoros,frame,0,ancho,alto);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void asteroides::moverAsteroide()
{
    if(animado == true){
        animarMeteoro();
    }
    setPos(x(),y()+caida);

    // rotación del asteroide
    // este rotará sobre su eje y dará efecto
    // TESTING
    if(rotar != false){
        setRotation(rotationAngle);
        if(rotationAngle<359){
            rotationAngle=rotationAngle+2.5;
        }
        else{
            rotationAngle=0;
        }
    }
    if(pos().y() > 560 ){
        delete this;
    }

    // capacidad destructiva de los asteroides
    // zona que elimina los objetos que sean impactados
    // en la caida
    // ZONA DE CHOQUE ASTEROIDES
    QList<QGraphicsItem *> elementosColisionables  = collidingItems() ;
    for(int i=0;i< elementosColisionables.size();i++)
    {
        if(typeid (*(elementosColisionables[i]))==typeid (enemigo))
        {
            delete elementosColisionables[i];
            break;
        }
        if(typeid (*(elementosColisionables[i]))==typeid (enemigoGigante))
        {
            delete elementosColisionables[i];
            break;
        }
    }
}
