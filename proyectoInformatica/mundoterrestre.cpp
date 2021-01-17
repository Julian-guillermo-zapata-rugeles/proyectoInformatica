#include "mundoterrestre.h"

mundoTerrestre::mundoTerrestre()
{
    srand(time(NULL));
    // creacion y anexo de personajes  //
    scene->addItem(personajePrincipal);


    // connects MAPPERS
    QSignalMapper *signalMapper = new QSignalMapper();
    connect(generadorAsteroides,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorEnemigos,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorEnemigosGigantes,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorNubes,SIGNAL(timeout()),signalMapper,SLOT(map()));

    connect(ticks,SIGNAL(timeout()),this,SLOT(ticksManager()));

    signalMapper->setMapping(generadorAsteroides,1);
    signalMapper->setMapping(generadorEnemigos,2);
    signalMapper->setMapping(generadorEnemigosGigantes,3);
    signalMapper->setMapping(generadorNubes,4);

    connect(signalMapper,SIGNAL(mapped(int )),this,SLOT(generador(int)));



}

void mundoTerrestre::iniciarMundo()
{
    vista->setScene(scene);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Puntaje
    puntaje->setPos(1000,40);
    scene->addItem(puntaje);

    //
    // fondo de pantalla se puede mejorar
    // se deshabilitará temporalmente para visualización.
    //vista->setStyleSheet("border-image: url(:/multimedia/fondo2.png)");
    // IMAGEN DE FONDO DESHABILITADA.

    vista->show();
    vista->setFixedSize(1300,600);
    vista->setSceneRect(0,0,1300,600);

    // iniciador de timers
    generadorAsteroides->start(15000);
    generadorEnemigos->start(6000);
    generadorNubes->start(8000);
    generadorEnemigosGigantes->start(10000);
    ticks->start(30);



}

void mundoTerrestre::generador(int tipo)
{
    // 1 para generar asteroides
    // 2 para generar enemigos
    // 3 para .....
    //

    if (tipo==1){
        // esta sección genera asteroides  y bajo ciertas circunstancias
        // desata el evento asteroides sorpresa.
        // se genera constantemente un numero aleatorio de 1 a 100
        // para iniciar el proceso si ese numero %3 == 0

        short int sorpresa_asteroide= 1+rand()%100;
        qDebug() <<"numero sorpresa :"<<sorpresa_asteroide;
        if(sorpresa_asteroide%3==0){
            // al desatarse el evento se genera un sonido de alerta
            // para avisar del evento.
           sonido->stop();
           sonido->setMedia(QUrl("qrc:/multimedia/sorpresaAsteroides.mp3"));
           sonido->play();

           qDebug() << "-- evento sorpresa INICIADO -- ";
           // durante este ciclo generamos aleatoriamente  un numero
           // que representará la cantidad de asteroides que salndrán
           for(short int a=0;a< 2+rand()%5;a++){
               scene->addItem(new asteroides(false));
           }
        }
        else{
            // en caso de ser un numero que no corresponde al %3
            // se generará un asteroide común.
            scene->addItem(new asteroides());
        }
    }

    //--------------------------------------
    if(tipo==2){
        scene->addItem(new enemigo(personajePrincipal->getLastPosition()));
    }
    if(tipo==3){
        scene->addItem(new enemigoGigante(personajePrincipal->getLastPosition()));
        // cada vez que se genere un enemigo gigante el timer
        // cambiará aleatoriamente para generar la sensación de situacione imprevista
        // y poco rutinarias
        // julian guillermo z.
        generadorEnemigosGigantes->setInterval(5000+rand()%25000);
    }
    if(tipo==4){
        scene->addItem(new nubes());
    }

}

void mundoTerrestre::ticksManager()
{
    //
}
