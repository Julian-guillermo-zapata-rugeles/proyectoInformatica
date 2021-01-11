#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <proyectil.h>
#include <random>

class enemigo : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
private:
    //QTimer *timer = new QTimer();
public:
    enemigo();
    void moverEnemigo(float position);

/*public slots:
    void disparar();
    */
};

#endif // ENEMIGO_H
