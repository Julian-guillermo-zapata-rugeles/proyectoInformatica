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

#include <personaje.h> // propia
#include <asteroides.h> // propia
#include <enemigo.h> // propia
#include <enemigoGigante.h> // propia
#include <nubes.h> // propia
#include "score.h" //propia
#include "lunacreciente.h" // propia
#include "timeGame.h"
#include "planeta.h"
#include "ship.h"
#include "aves.h"
#include <QMainWindow>
#include <multiplayer.h>
#include "rocket.h"
#include "gamesave.h"
#include "gameover.h"
#include "cliente.h"
#define dt 1

class mundoTerrestre : public QObject , public QGraphicsRectItem , public GameSave
{
    Q_OBJECT
public:
    // se estudia la posibilidad de sobrecargar al constructor o generar aleatoriedad en cada mundo
    // pese a que existe cierto grado se pueden generar multiples niveles modificando los timers
    // y el spawn del enemigos
    // algunas condiciones de gravedad (mas o mensos) y ambientación

    mundoTerrestre(QString userName, short int p);
    void iniciarMundo();

 private:

    QList<personaje *> Jugadores;
    MultiPlayer *players;
    QGraphicsScene * scene;
    personaje * personajePrincipal;
    personaje * personajeSecundario;
    QGraphicsView * vista;
    QMediaPlayer *sonido;
    std::string nombreUsuario;
    cliente *nuevoCliente;
    GameOver *finJuego;

    //Naves
    float s; //escala
    Planeta *planet;
    QList<Planeta *> sistema;
    QList<float> origen;

    //metodos para la naves
    void createShips();
    float calculoEscala();
    QList<float> calculoCentroMasas(QList<Planeta*> planetas);
    void calculoAceleracion();                                  //calcula la aceleracion de cada cuerpo
    void inception();
    void guardarInformacion();
    void finalizarJuego();

    // Niveles y configuración
    bool level_complete;
    short int level;
    short int level_time ;
    short int tiempo_asterides;
    short int tiempo_enemigos;
    short int tiempo_enemigos_gigantes;
    short int tiempo_nubes;
    short int tiempo_luna;
    qreal globar_position , *gp;
    qreal global_PositionP2, *gp2;

    /*
       zona de scores y de  QGraphicsText
       aquí estarán los objetos que mostrará información del personaje y sobre el estado de juego
    */
    Score *puntaje = new Score;
    timeGame *tiempoJuego = new timeGame;

    /* timers para el control de generación
        NOTA : se investigará sí existe una manera más eficiente para controlar la generación.

    */
    QTimer *ticks = new QTimer();
    QTimer *generadorAsteroides = new QTimer();
    QTimer *generadorEnemigos = new QTimer();
    QTimer *generadorEnemigosGigantes = new QTimer();
    QTimer *generadorNubes = new QTimer();
    QTimer *generadorDeLuna = new QTimer();
    QTimer *animacionPersonaje = new QTimer();

    //Naves
    QTimer *generadorNaves = new QTimer();

public slots:
  void generador(int);
  void ticksPersonaje();
  void actualizar_nivel();

  //actualizar las naves
  void actualizar();
  void updateAnimation();


};

#endif // MUNDOTERRESTRE_H
