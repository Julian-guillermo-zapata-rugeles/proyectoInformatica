#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <proyectil.h>
#include <random>
#include <QTimer>
#include <movimientos.h>
#include <QMediaPlayer>

class enemigo : public QObject , public QGraphicsRectItem , public movimientos
{
    Q_OBJECT
private:
     QTimer *timer;
     qreal last_position;
     QMediaPlayer *sonido = new QMediaPlayer();
public:
    enemigo(qreal lastPosition);
    ~enemigo();
private slots:
    void moverEnemigo();


};

#endif // ENEMIGO_H
