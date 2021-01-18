#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <proyectil.h>
#include <bonus_municion.h>
#include <movimientos.h>


class personaje : public QGraphicsRectItem , public movimientos
{
private:
    QMediaPlayer *sonido = new QMediaPlayer();
    bool dir;
    short int disparos_disponibles;
public:
    personaje();
    void keyPressEvent(QKeyEvent *event);
    qreal getLastPosition();
    void eventHandler();

    bool ifcollide();
};

#endif // PERSONAJE_H
