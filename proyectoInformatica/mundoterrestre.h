#ifndef MUNDOTERRESTRE_H
#define MUNDOTERRESTRE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <personaje.h> // propia
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <asteroides.h> // propia
#include <enemigo.h> // propia
#include <QVector>
#include <QSignalMapper>


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
    // timers
    QTimer *ticks = new QTimer();
    QTimer *generadorAsteroides = new QTimer();


public slots:
  void generador(int);
  void ticksManager();
};

#endif // MUNDOTERRESTRE_H
