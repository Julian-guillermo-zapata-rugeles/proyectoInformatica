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
    mundoTerrestre();
    void iniciarMundo();

 private:
    QGraphicsScene * scene  = new QGraphicsScene();
    personaje * personajePrincipal = new personaje();
    QGraphicsView * vista = new QGraphicsView(scene);
    QMediaPlayer *sonido = new QMediaPlayer();

    //Puntaje
    Score *puntaje = new Score;

    //Tiempo de juego
    timeGame *tiempoJuego = new timeGame;

    // timers
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
