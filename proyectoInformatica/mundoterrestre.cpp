#include "mundoterrestre.h"

mundoTerrestre::mundoTerrestre()
{
    // creacion y anexo de personajes  //
    scene->addItem(personajePrincipal);


    // connects
    QSignalMapper *signalMapper = new QSignalMapper();
    connect(generadorAsteroides,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorEnemigos,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorEnemigosGigantes,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(ticks,SIGNAL(timeout()),this,SLOT(ticksManager()));

    signalMapper->setMapping(generadorAsteroides,1);
    signalMapper->setMapping(generadorEnemigos,2);
    signalMapper->setMapping(generadorEnemigosGigantes,3);

    connect(signalMapper,SIGNAL(mapped(int )),this,SLOT(generador(int)));



}

void mundoTerrestre::iniciarMundo()
{
    vista->setScene(scene);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setStyleSheet("border-image: url(:/multimedia/fondo2.png)");
    vista->show();
    vista->setFixedSize(1300,600);
    vista->setSceneRect(0,0,1300,600);

    // iniciador de timers
    generadorAsteroides->start(10000);
    generadorEnemigos->start(5000);
    //generadorEnemigosGigantes->start(40000);
    ticks->start(30);



}

void mundoTerrestre::generador(int tipo)
{
    // 1 para generar asteroides
    // 2 para generar enemigos
    // 3 para .....
    //
    if (tipo==1){
        scene->addItem(new asteroides());
    }
    if(tipo==2){
        scene->addItem(new enemigo(personajePrincipal->getLastPosition()));
    }
    if(tipo==3){
        scene->addItem(new enemigoGigante(personajePrincipal->getLastPosition()));
    }

}

void mundoTerrestre::ticksManager()
{
    //
}
