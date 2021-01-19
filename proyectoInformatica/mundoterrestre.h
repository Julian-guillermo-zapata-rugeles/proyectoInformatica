#ifndef MUNDOTERRESTRE_H
#define MUNDOTERRESTRE_H

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

class mundoTerrestre : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    // se estudia la posibilidad de sobrecargar al constructor o generar aleatoriedad en cada mundo
    // pese a que existe cierto grado se pueden generar multiples niveles modificando los timers
    // y el spawn del enemigos
    // algunas condiciones de gravedad (mas o mensos) y ambientación

    mundoTerrestre();
    void iniciarMundo();


 private:
    QGraphicsScene * scene  = new QGraphicsScene();
    personaje * personajePrincipal = new personaje();
    QGraphicsView * vista = new QGraphicsView(scene);
    QMediaPlayer *sonido = new QMediaPlayer();

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


public slots:
  void generador(int);
  void ticksPersonaje();
};

#endif // MUNDOTERRESTRE_H
