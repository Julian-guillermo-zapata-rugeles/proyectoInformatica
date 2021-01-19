#include "mundoterrestre.h"

mundoTerrestre::mundoTerrestre()
{
    srand(time(NULL));

    // creacion y anexo de personajes  //
    scene->addItem(personajePrincipal);


    // connects MAPPERS
    // se usará mapper para conectar varios timers a una única función encargada
    // de la generación de "protagonistas" de la escena.
    // la idea es que al finalizar cada timer * del generador
    // se invoque al slot generar (int) con un entero que represente
    // el condicional que generará.

    QSignalMapper *signalMapper = new QSignalMapper();
    connect(generadorAsteroides,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorEnemigos,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorEnemigosGigantes,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorNubes,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(generadorDeLuna,SIGNAL(timeout()),signalMapper,SLOT(map()));
    connect(ticks,SIGNAL(timeout()),this,SLOT(ticksPersonaje()));

    signalMapper->setMapping(generadorAsteroides,1);
    signalMapper->setMapping(generadorEnemigos,2);
    signalMapper->setMapping(generadorEnemigosGigantes,3);
    signalMapper->setMapping(generadorNubes,4);
    signalMapper->setMapping(generadorDeLuna,5);

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

    //tiempo de juego
    tiempoJuego->setPos(30,40);
    scene->addItem(tiempoJuego);

    short int n = 1+ rand() % 5;
    switch (n) {
    case 1:{
        vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG apocalyptic 1.jpg)");
        break;
    }
    case 2:{
        vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG apocalyptic 2.jpg)");
        break;
    }
    case 3:{
        vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG apocalyptic 3.jpg)");
        break;
    }
    case 4:{
        vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG alien 2.jpg)");
        break;
    }
    case 5:{
        vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG alien 1.jpg)");
        break;
    }
    }
    //
    // fondo de pantalla se puede mejorar
    // se deshabilitará temporalmente para visualización.
    //vista->setStyleSheet("border-image: url(:/multimedia/fondo3.jpg)");
    // IMAGEN DE FONDO DESHABILITADA.

    vista->show();
    vista->setFixedSize(1300,600);
    vista->setSceneRect(0,0,1300,600);

    // iniciador de timers
    generadorAsteroides->start(12000);
    generadorEnemigos->start(6000);
    generadorNubes->start(8000);
    generadorEnemigosGigantes->start(10000);
    generadorDeLuna->start(35000);
    ticks->start(30);

}

void mundoTerrestre::generador(int tipo)
{
    // 1 para generar asteroides
    // 2 para generar enemigos
    // 3 para generar enemigos Gigantes
    // 4 para generar nubes


    // ****************** GENERACION ASTEROIDES Y EVENTOS ************************ //
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
            for(short int a=0;a< 2+rand()%4;a++){
                scene->addItem(new asteroides(false));
            }
        }
        else{
            // en caso de ser un numero que no corresponde al %3
            // se generará un asteroide común.
            scene->addItem(new asteroides());
        }
    }

    // ****************** GENERACION ENEMIGO COMÚN ************************ //

    if(tipo==2){
        scene->addItem(new enemigo(personajePrincipal->getLastPosition()));
    }

    // ****************** GENERACION ENEMIGO GIGANTE ************************ //
    if(tipo==3){
        if((1+rand()%10)%2==0){
            // los enemigos gigantes tiene diferentes cualidades , una de ellas es saltar
            // estos pueden desplazarse saltando por lo cual
            // se generán de forma aleatorio
            // si el numero al azar es par el enemigo saltará
            scene->addItem(new enemigoGigante(personajePrincipal->getLastPosition(),true));
        }
        else{
            // de no ser par el enemigo no saltará
            scene->addItem(new enemigoGigante(personajePrincipal->getLastPosition(),false));
        }
        // cada vez que se genere un enemigo gigante el timer
        // cambiará aleatoriamente para generar la sensación de situacione imprevista
        // y poco rutinarias
        // julian guillermo z.
        generadorEnemigosGigantes->setInterval(5000+rand()%25000);
    }

    // ****************** GENERACION DE NUBES  ************************ //
    if(tipo==4){
        scene->addItem(new nubes());
    }

    if(tipo==5){
        scene->addItem(new lunaCreciente());
         personajePrincipal->setStatus_gravitatorio(true);
         sonido->setMedia(QUrl("qrc:/multimedia/luna.mp3"));
         sonido->play();
    }
}

void mundoTerrestre::ticksPersonaje()
{
    // este evento handler verificará si el personaje debe saltar
    bool lunaActiva = false;
    QList<QGraphicsItem *> it = scene->items();
    for(int i=0;i< it.size();i++){
        // balas que colisionan con los enemigos
        if(typeid (*(it[i]))==typeid (lunaCreciente)){
            lunaActiva=true;
            }
        }
     if(lunaActiva==true){
         personajePrincipal->setStatus_gravitatorio(true);
     }
     else{
         personajePrincipal->setStatus_gravitatorio(false);
     }

    personajePrincipal->eventHandler();

    //Administracion de colisiones del personaje con los diferentes objetos
    QList<QGraphicsItem *> elementosColisionables  = scene->items();

    for(int i=0;i< elementosColisionables.size();i++){
        // balas que colisionan con los enemigos

        if(typeid (*(elementosColisionables[i]))==typeid (enemigo)){
            if(elementosColisionables[i]->collidesWithItem(personajePrincipal)){
                qDebug() <<"me alcanzo un enemigo" <<endl;
            }
        }

        if(typeid (*(elementosColisionables[i]))==typeid (asteroides)){
            if(elementosColisionables[i]->collidesWithItem(personajePrincipal)){
                qDebug() <<"me aplasto un asteroide" <<endl;
                //scene->removeItem(personajePrincipal);
                //ticks->stop();
                //delete personajePrincipal;
            }
        }

        if(typeid (*(elementosColisionables[i]))==typeid (enemigoGigante)){
            if(elementosColisionables[i]->collidesWithItem(personajePrincipal)){
                qDebug() <<"me alcanzo un saltador" <<endl;
            }
        }
    }

    if(tiempoJuego->getTime() < 6){
        //Generamos un asteroide gigante para terminar el nivel
        short int n=1;
        //scene->addItem(new asteroides(n));
        generadorAsteroides->stop();
        ticks->stop();
        generadorEnemigos->stop();
        generadorEnemigosGigantes->stop();
    }
}
