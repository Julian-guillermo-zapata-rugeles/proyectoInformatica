#ifndef MUNDOTERRESTRE_H
#define MUNDOTERRESTRE_H
#define DEBUG_MUNDOTERRESTRE

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QVector>
#include <QSignalMapper>
#include <QMediaPlayer>
#include <QMainWindow>

#include "personaje.h" // propia
#include "asteroides.h" // propia
#include "enemigo.h" // propia
#include "enemigoGigante.h" // propia
#include "nubes.h" // propia
#include "score.h" //propia
#include "lunacreciente.h" // propia
#include "timeGame.h"
#include "planeta.h"
#include "ship.h"
#include "aves.h"
#include "multiplayer.h"
#include "rocket.h"
#include "gamesave.h"
#include "gameover.h"
#include "cliente.h"
#define dt 1

class mundoTerrestre : public QObject , public QGraphicsRectItem , public GameSave
{
    Q_OBJECT

public:
    /*
       ------------------------------------------------------------------------
                            CONSTRUCTOR DE LA CLASE
       ------------------------------------------------------------------------

       userName : nombre del jugador o equipo (se usará para guardar la información)
       p        : cantidad de personajes (multiplayer max 2)
    */
    mundoTerrestre(QString userName, short int p);
    void iniciarMundo(); // iniciar el mundo


private:

    /*
       ------------------------------------------------------------------------
                     INICIALIZACIÓN DE ATRIBUTOS PRIVADOS
       ------------------------------------------------------------------------
    */
    bool level_complete;
    short int level;
    short int level_time ;
    short int tiempo_asteroides;
    short int tiempo_enemigos;
    short int tiempo_enemigos_gigantes;
    short int tiempo_nubes;
    short int tiempo_luna;

    // segmento del multiplayer //

    qreal globar_position , *gp;
    qreal global_PositionP2, *gp2;

    QList<personaje *> Jugadores;
    MultiPlayer *players;
    personaje * personajePrincipal;
    personaje * personajeSecundario;

    // escena y multimedia //
    QGraphicsScene * scene;
    QGraphicsView * vista;
    QMediaPlayer *sonido;

    // usuario y salida //
    std::string nombreUsuario;
    cliente *nuevoCliente;
    GameOver *finJuego;
    Score *puntaje;
    timeGame *screenInformation;

    // Naves espaciales //
    float s; //escala
    Planeta *planet;
    QList<Planeta *> sistema;
    QList<float> origen;
    QList<float> calculoCentroMasas(QList<Planeta*> planetas);

    // Timers Generadores spaw de enemgigos //

    QTimer *ticksEventosGlobales;
    QTimer *generadorAsteroides;
    QTimer *generadorEnemigos;
    QTimer *generadorEnemigosGigantes;
    QTimer *generadorNubes;
    QTimer *generadorDeLuna;
    QTimer *animacionPersonaje;
    QTimer *generadorNaves;

    /*
       ------------------------------------------------------------------------
                            INICIALIZACIÓN DE MÉTODOS  PRIVADOS
       ------------------------------------------------------------------------
    */

    //metodos para la naves (plane)
    void crearPlanetas(); // genración de planetas (4)
    float calculoEscala(); // calculo escalas
    void calculoAceleracion();  //calcula la aceleracion de cada cuerpo
    void inception();

    //métodos del juego  //
    void guardarInformacion();       // guardar en archivo con nombre userName
    void finalizarJuego();           // fin del juego llamado a reiniciar
    void actualizarNivel();          // actualizar un nivel.
    void comprobadorCambioNivel();   // comprobar si un nivel está proximo a cambiar.


private slots:
    /*
       ------------------------------------------------------------------------
                            SLOTS PRIVADOS DE LA CLASE
       ------------------------------------------------------------------------
    */
    void generadorEntidades(int);
    void capturadorEventosGlobales();

    //actualizar los planetas
    void actualizar();
    void updateAnimation();


};

#endif // MUNDOTERRESTRE_H
