#ifndef ENEMIGOGIGANTE_H
#define ENEMIGOGIGANTE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <proyectil.h>
#include <random>

class enemigoGigante : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
private:
    //QTimer *timer = new QTimer();
public:
    enemigoGigante();
    void moverEnemigo(float position);

/*public slots:
    void disparar();
    */
};

#endif // ENEMIGO_H
