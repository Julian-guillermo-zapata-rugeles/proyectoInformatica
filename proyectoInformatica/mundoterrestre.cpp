#include "mundoterrestre.h"

mundoTerrestre::mundoTerrestre(QString userName, short p):GameSave()
{
    scene  = new QGraphicsScene();
    vista = new QGraphicsView(scene);
    for (short int i=0; i<p ; i++ ) {
        Jugadores.append(new personaje);
    }

    players = new MultiPlayer();
    players->setPlayer1(Jugadores[0]);
    if(p == 2){
        players->setPlayer2(Jugadores[1]);
    }
    scene->addItem(players);
    sonido = new QMediaPlayer();

    // VARIABLE QUE GUARDARÁ EL NOMBRE DEL USUARIO PARA ACCEDER A LOS METODOS DE GAMESAVE
    this->nombreUsuario=userName.toStdString();
    /*
    sección de información para el nivel y el usuario en partida
    */
    tiempoJuego->setUser_name(userName); // lo recibí desde el cliente principal
    level_complete=false;
    level=2;
    level_time=10;

    tiempo_asterides=12000;
    tiempo_enemigos=6000;
    tiempo_enemigos_gigantes=10000;
    tiempo_nubes=8000;
    tiempo_luna=30000;

    //Puntaje
    puntaje->setPos(1000,40);
    scene->addItem(puntaje);

    //tiempo de juego
    tiempoJuego->setPos(30,40);
    scene->addItem(tiempoJuego);

    srand(time(NULL));
    for (short int i =0; i<p ; i++) {
        scene->addItem(Jugadores[i]);
    }

    vista->setScene(scene);

    if(p == 2){
        global_PositionP2 = Jugadores[1]->getLastPosition();
        gp2 = &global_PositionP2;
    }
    globar_position = Jugadores[0]->getLastPosition();

    gp = &globar_position;

    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->show();
    vista->setFixedSize(1300,600);
    vista->setSceneRect(0,0,1300,600);

    // creacion y anexo de personajes  //
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

    animacionPersonaje->start(50);
    connect(animacionPersonaje, SIGNAL(timeout()),this,SLOT(updateAnimation()));

    signalMapper->setMapping(generadorAsteroides,1);
    signalMapper->setMapping(generadorEnemigos,2);
    signalMapper->setMapping(generadorEnemigosGigantes,3);
    signalMapper->setMapping(generadorNubes,4);
    signalMapper->setMapping(generadorDeLuna,5);

    connect(signalMapper,SIGNAL(mapped(int )),this,SLOT(generador(int)));
    sonido->setVolume(50);

    connect(generadorNaves,SIGNAL(timeout()),this,SLOT(actualizar()));
    generadorNaves->start(1);
}







void mundoTerrestre::iniciarMundo()
{
    if(level%3 == 0){
        short int m = 1+rand()%5;
        switch (m) {
        case 1:{
            vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG space 1.jpg)");
            break;
        }
        case 2:{
            vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG space 2.jpg)");
            break;
        }
        case 3:{
            vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG space 3.jpg)");
            break;
        }
        case 4:{
            vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG space 4.jpg)");
            break;
        }
        case 5:{
            vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG space 5.jpg)");
            break;
        }
        }
    }
    else{
        short int n = 1+ rand() % 8;
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
        case 6:{
            vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG alien 3.jpg)");
            break;
        }
        case 7:{
            vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG alien 4.jpg)");
            break;
        }
        case 8:{
            vista->setStyleSheet("border-image: url(:/multimedia/Backgrounds/BG alien 5.jpg)");
            break;
        }
        }
    }
    ticks->start(20);
}








void mundoTerrestre::createShips()
{
    sistema.append(new Planeta(0,0,80000,200));
    sistema.append(new Planeta(-5000,0,70,70,0,-2));
    sistema.append(new Planeta(5000,0,70,70,0,2));
    sistema.append(new Planeta(0,-5000,70,70,2,0));
    sistema.append(new Planeta(0,5000,70,70,-2,0));
    origen = calculoCentroMasas(sistema);
    s = calculoEscala();
    inception();
    for(int i=0 ; i<sistema.size() ; i++){
        sistema.at(i)->asignarEscala(s);
        scene->addItem(sistema.at(i));
    }
}








float mundoTerrestre::calculoEscala()
{
    float max =0, dx=0, dy=0;

    for(int i = 0; i<sistema.size(); i++) {
        dx = origen.at(0) - sistema.at(i)->obtenerCuerpo()->getX();
        dy = origen.at(1) - sistema.at(i)->obtenerCuerpo()->getY();
        if(sqrt(dx*dx + dy*dy) > max){
            max = sqrt(dx*dx + dy*dy);
        }
    }
    max = v_lim/(2*max);
    return max;
}









QList<float> mundoTerrestre::calculoCentroMasas(QList<Planeta *> planetas)
{
    float Mx=0, My=0, Mt=0;
    QList<float> punto;
    for(int i = 0; i<planetas.size(); i++)
    {
        Mx += planetas.at(i)->obtenerCuerpo()->getMasa() * planetas.at(i)->obtenerCuerpo()->getY();
        My += planetas.at(i)->obtenerCuerpo()->getMasa() * planetas.at(i)->obtenerCuerpo()->getX();
        Mt += planetas.at(i)->obtenerCuerpo()->getMasa();
    }
    punto.append(My/Mt);
    punto.append(Mx/Mt);
    return punto;
}








void mundoTerrestre::calculoAceleracion()
{
    float ax = 0, ay = 0;
    int n = sistema.size();
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            ax= sistema.at(i)->obtenerCuerpo()->calcularAcX(*sistema.at(j)->obtenerCuerpo());
            ay= sistema.at(i)->obtenerCuerpo()->calcularAcY(*sistema.at(j)->obtenerCuerpo());
            sistema.at(i)->obtenerCuerpo()->sumarAceleracion(ax,ay);

            ax= sistema.at(j)->obtenerCuerpo()->calcularAcX(*sistema.at(i)->obtenerCuerpo());
            ay= sistema.at(j)->obtenerCuerpo()->calcularAcY(*sistema.at(i)->obtenerCuerpo());
            sistema.at(j)->obtenerCuerpo()->sumarAceleracion(ax,ay);
        }
    }
}










void mundoTerrestre::inception()
{
    float dx = h_lim/(2*s) - origen.at(0);
    float dy = v_lim/(2*s) - origen.at(1);
    for(int i = 0; i<sistema.size(); i++)
    {
        sistema.at(i)->obtenerCuerpo()->asignarPosicion(dx,dy);
    }
}









void mundoTerrestre::guardarInformacion()
{

    // -----------------------------------------------------------------------------
    // ZONA PARA LA ESCRITURA DE ARCHIVOS //
    // file << puntaje <<" "<<shoots<<" "<<level <<" "<<life_level; //
    // actualizaré las variables para escritura

    GameSave::puntaje=puntaje->getScore();
    GameSave::level=level;
    GameSave::shoots=tiempoJuego->getDisparos();
    GameSave::life_level = tiempoJuego->getVidaRestante();

    // llamaré a escribir la información.
    GameSave::escribirInformacion(nombreUsuario);
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

        short int sorpresa_asteroide= 1+rand()%10;

#ifdef DEBUG_MUNDOTERRESTRE
        qDebug() <<"numero sorpresa :"<<sorpresa_asteroide;
#endif
        if(sorpresa_asteroide%3==0){
            // al desatarse el evento se genera un sonido de alerta
            // para avisar del evento.
            if(level%5!= 0){
                sonido->stop();
                sonido->setMedia(QUrl("qrc:/multimedia/sorpresaAsteroides.mp3"));
                sonido->play();
                for(short int a=0;a< 2+rand()%1;a++){
                    scene->addItem(new asteroides(false));

                }
            }
            else{
#ifdef DEBUG_MUNDOTERRESTRE
        qDebug()<<"evento omitido nivel %5";
#endif
            }
#ifdef DEBUG_MUNDOTERRESTRE
        qDebug() << "-- evento sorpresa INICIADO -- ";
#endif
            // durante este ciclo generamos aleatoriamente  un numero
            // que representará la cantidad de asteroides que salndrán
        }
        else{
            // en caso de ser un numero que no corresponde al %3
            // se generará un asteroide común.
            if(level%5==0){
                scene->addItem(new asteroides(false));
            }
            else{
                scene->addItem(new asteroides());
            }
        }
    }

    // ****************** GENERACION ENEMIGO COMÚN ************************ //

    if(tipo==2){
        if(level%4 == 0){
            if(1+rand()%2 == 1){
                scene->addItem(new Aves(1));
            }
            else{
                scene->addItem(new Aves());
            }
        }
        else{
            scene->addItem(new enemigo(gp));
        }
    }

    // ****************** GENERACION ENEMIGO GIGANTE ************************ //
    if(tipo==3){
        if((1+rand()%10)%2==0){
            // los enemigos gigantes tiene diferentes cualidades , una de ellas es saltar
            // estos pueden desplazarse saltando por lo cual
            // se generán de forma aleatorio
            // si el numero al azar es par el enemigo saltará
            scene->addItem(new enemigoGigante(Jugadores[0]->getLastPosition()));
        }
        else{
            // de no ser par el enemigo no saltará
            scene->addItem(new enemigoGigante(Jugadores[0]->getLastPosition()));
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
        //personajePrincipal->setStatus_gravitatorio(true);
        sonido->setMedia(QUrl("qrc:/multimedia/luna.mp3"));
        sonido->play();
        generadorDeLuna->stop(); // luna desactivada one shoot
    }
}










void mundoTerrestre::ticksPersonaje()
{
    /*
    if(Jugadores.length() == 2){
        tiempoJuego->setImpulsos(Jugadores[1]->getImpulsos());
        //global_PositionP2=Jugadores[1]->getLastPosition();
        tiempoJuego->setVidaRestante(Jugadores[0]->getVida_disponible());
        // este evento handler verificará si el personaje debe saltar
        //bool lunaActiva = false;
        Jugadores[0]->eventHandler();
        tiempoJuego->setDisparos(Jugadores[0]->getDisparos_disponibles());
        puntaje->setScore(Jugadores[0]->getPuntos());
        //qDebug() <<personajePrincipal->getPuntos()<<endl;
    }
    */

    tiempoJuego->setImpulsos(Jugadores[0]->getImpulsos());
    globar_position=Jugadores[0]->getLastPosition();
    tiempoJuego->setVidaRestante(Jugadores[0]->getVida_disponible());

    // este evento handler verificará si el personaje debe saltar
    //bool lunaActiva = false;

    for (short int i =0; i< Jugadores.size() ; i++) {
        Jugadores[i]->eventHandler();
    }

    tiempoJuego->setDisparos(Jugadores[0]->getDisparos_disponibles());
    puntaje->setScore(Jugadores[0]->getPuntos());
    //qDebug() <<personajePrincipal->getPuntos()<<endl;

    if(tiempoJuego->getTime() < 12){
        //ticks->stop();ddddd
        generadorAsteroides->stop();
        generadorEnemigos->stop();
        generadorEnemigosGigantes->stop();
        if(tiempoJuego->getTime()==6){
            generadorDeLuna->start(1000);
        }
        if(level%3==0 && tiempoJuego->getTime()==5){

            for(int i=0 ; i<sistema.size() ; i++){
                scene->addItem(new Animaciones(sistema.at(i)->pos().x(),sistema.at(i)->pos().y(),2));
                scene->removeItem(sistema.at(i));
                sistema.removeAt(i);
            }
            //generadorNubes->stop();
        }
        if(tiempoJuego->getTime() < 4){
            //qDebug() << "Entro a mostrar splash del siguiente nivel "<<endl;
            if((level+1)%2 ==0){
                vista->setStyleSheet("border-image: url(:/multimedia/next level.png)");
            }
            if((level+1)%3 ==0 || (level+1)%5 ==0 ){
                vista->setStyleSheet("border-image: url(:/multimedia/nextlevel35.png)");
            }
            if((level+1)%4 == 0){
                vista->setStyleSheet("border-image: url(:/multimedia/nextlevel4.png)");
            }
        }
        if(tiempoJuego->getTime()==0){
            this->actualizar_nivel();
        }
    }

    QList<QGraphicsItem *> elementosColisionables  = scene->items() ;
    for(int i=0;i< elementosColisionables.size();i++){
        if(typeid (*(elementosColisionables[i]))==typeid (Rocket)){
            for (short int a=0; a<sistema.size() ; a++ ) {
                if(elementosColisionables[i]->collidesWithItem(sistema.at(i))){
                    scene->addItem(new Animaciones(sistema.at(i)->pos().x(),sistema.at(i)->pos().y(),10));
                    scene->removeItem(sistema.at(i));
                    sistema.removeAt(i);
                }
            }
        }
    }
}










void mundoTerrestre::actualizar_nivel()
{


    level=level+1;
    qDebug() << "nivel " << level;
    //sonido->
    if(level==1){
        level_complete=true;
        generadorAsteroides->start(8000);
        generadorEnemigos->start(1000);
        generadorNubes->start(8000);
        generadorEnemigosGigantes->start(10000);
        //generadorDeLuna->start(30000);
        //ticks->start(20);
    }

    else if(level%3 == 0){
        createShips();
        tiempoJuego->setTimeCount(20);
        generadorEnemigos->start(3000);
        this->iniciarMundo();
    }

    else if(level%4 == 0){
        generadorEnemigos->start(3000);
        tiempoJuego->setTimeCount(30);
        generadorNubes->start(8000);
        this->iniciarMundo();
    }

    else if(level%5==0){
#ifdef DEBUG_MUNDOTERRESTRE
        qDebug()<< "nivel asteroides asesinos"<<endl;
#endif

        // este nivel es sobre asteroides , el personaje deberá aguantar la caida de estos
        //generadorNubes->start(8000);
        generadorAsteroides->start(1000);
        sonido->stop();
        sonido->setMedia(QUrl("qrc:/multimedia/Sonidos/suspenso_asteroides2.mp3"));
        this->iniciarMundo();
        tiempoJuego->setTimeCount(35);
        sonido->play();
    }
    else{
        generadorAsteroides->start(12000);
        this->tiempo_enemigos= this->tiempo_enemigos-500;
        this->tiempo_enemigos_gigantes=tiempo_enemigos_gigantes-500;
        generadorEnemigos->start(tiempo_enemigos);
        generadorEnemigosGigantes->start(tiempo_enemigos_gigantes);

#ifdef DEBUG_MUNDOTERRESTRE
        qDebug()<<" nivel "<< level;
#endif
        this->iniciarMundo();
        tiempoJuego->setTimeCount(60);

    }
    tiempoJuego->setLevelworld(level);

    // ------ GUARDADO DE INFORMACION ------//
    guardarInformacion();



}











void mundoTerrestre::actualizar()
{
    if(sistema.length() != 0){
        calculoAceleracion();   //actualiza las aceleraciones de todos los cuerpos
        for(int i = 0; i<sistema.size(); i++){
            sistema.at(i)->actualizar(dt);
        }
    }
}








void mundoTerrestre::updateAnimation()
{
    /*
    personajePrincipal->actualizarEstado();

    if(personajePrincipal->getStatus_saltando() == false &&
            personajePrincipal->getPressKey() == false &&
            personajePrincipal->getStateShoot() == false)
    {
        personajePrincipal->setState("stand");
    }
    else if (personajePrincipal->getPressKey() == true && personajePrincipal->getStateShoot() == false){
        personajePrincipal->setPressKey(false);
        //personajePrincipal->setState("stand");
    }
    */

    //MULTIPLAYER
    for (short int i=0; i<Jugadores.length() ; i++ )
    {
        Jugadores[i]->actualizarEstado();
        if(Jugadores[i]->getStatus_saltando() == false &&
                Jugadores[i]->getPressKey() == false &&
                Jugadores[i]->getStateShoot() == false)
        {
            Jugadores[i]->setState("stand");
        }
        else if (Jugadores[i]->getPressKey() == true && Jugadores[i]->getStateShoot() == false)
        {
            Jugadores[i]->setPressKey(false);
            //Jugadores[i]->setState("stand");
            //personajePrincipal->setState("stand");
        }
    }
}


