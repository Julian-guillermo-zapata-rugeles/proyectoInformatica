#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <proyectil.h>
#include <random>
#include <QTimer>
#include <movimientos.h>

class enemigo : public QObject , public QGraphicsRectItem , public movimientos
{
    Q_OBJECT
private:
     QTimer *timer;
     qreal last_position;

public:
    enemigo(qreal lastPosition);
    ~enemigo();
private slots:
    void moverEnemigo();

};

#endif // ENEMIGO_H
