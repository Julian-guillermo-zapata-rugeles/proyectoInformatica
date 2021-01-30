#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QMediaPlayer>
#include <QList>
#include <enemigo.h>
#include <enemigoGigante.h>
#include <asteroides.h>

class proyectil : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    // direccion True  para derecha
    // direccion False para izquierda
    bool direccion;
    short int *puntosP;

public:
    proyectil(bool dir, short int *puntos);

public slots:
    void moverProyectil();
};

#endif // PROYECTIL_H
