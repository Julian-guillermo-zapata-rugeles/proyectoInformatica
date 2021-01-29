#include "asteroides.h"


/*   ------------------- CONSTRUCTOR POR DEFECTO ------------------------ */

asteroides::asteroides(bool sound)
{

     //qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ;// DEBUG
    // aspecto y ubicación //
    generarAspecto();
    generarAleatoriedad();
    // reproducir sonido siempre y cuando se indique //
    if(sound){
        generarSonidos();
    }
}


/*   ------------------- CONSTRUCTOR  SOBRECARGADO #2 ----------------------- */
/* Generar asteroides basados en una ubicación concreta
 * se piensa emplear en el multijuador (el enemigo) que controla la caida de asteroides
*/

asteroides::asteroides(qreal x, qreal y)
{
    //qDebug()<<"asteroide generado en "<<pos().x() << " " << pos().y() ; // DEBUG
    setPos(x,y);
    this->setPixmap(QPixmap(":/multimedia/proyectiles/bulletEnemy.png"));
    this->setTransformOriginPoint(this->boundingRect().center());
    this->setScale(1.5);
    this->rotationAngle = 0;
    this->velocidad_caida=15;
    this->fire = true;
}




/*   ------------------- DESTRUCTOR  ----------------------- */

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





/*   ------------------- ADVANCE ----------------------- */

void asteroides::advance(int phase)
{
    setPos(x(),y()+velocidad_caida);

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
    Q_UNUSED(phase);
}



/*   -------------------GENERACION DE ASPECTOS ----------------------- */

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

void asteroides::generarAleatoriedad()
{
    this->rotationAngle=0;
    // alta resolución en la generación de semilla.
    long long semilla = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand((unsigned int )semilla);
    this->velocidad_caida=15+rand()%25;
    this->setTransformOriginPoint(this->boundingRect().center());
    setPos(1+rand()%1200,-1800 + ((1+rand()%500)*-1));

}

void asteroides::generarSonidos()
{
    sonido->stop();
    sonido->setMedia(QUrl("qrc:/multimedia/suspenso1.mp3"));
    sonido->play();
    sonido->setVolume(40);
}

