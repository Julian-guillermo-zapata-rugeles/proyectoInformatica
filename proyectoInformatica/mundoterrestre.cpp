#include "mundoterrestre.h"

mundoTerrestre::mundoTerrestre()
{
    // creacion y anexo de personajes  //
    scene->addItem(personajePrincipal);


    // connects
    QSignalMapper *signalMapper = new QSignalMapper();
    connect(generadorAsteroides,SIGNAL(timeout()),signalMapper,SLOT(map()));
    //connect(generadorEnemigos,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(ticks,SIGNAL(timeout()),this,SLOT(ticksManager()));

    signalMapper->setMapping(generadorAsteroides,1);
    //signalMapper->setMapping(generadorEnemigos,2);
    connect(signalMapper,SIGNAL(mapped(int )),this,SLOT(generador(int)));

    // iniciador de timers
    generadorAsteroides->start(10000);
    ticks->start(30);
    //generadorEnemigos->start(5000);
}

void mundoTerrestre::iniciarMundo()
{
    vista->setScene(scene);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->show();
    vista->setFixedSize(1300,600);
    vista->setSceneRect(0,0,1300,600);

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
    /*
    if(tipo==2){
        v_enemigos.push_back(new enemigo());
        scene->addItem(v_enemigos.last());
    }
    */

}

void mundoTerrestre::ticksManager()
{
    // esta slot se encargará de actualizar los objetos que se dispongan aquí
    /*
    for(auto& it :v_enemigos){
        it->moverEnemigo(personajePrincipal->x());
    }
    */
}
