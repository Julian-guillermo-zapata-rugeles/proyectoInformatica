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
#include <aves.h>

class proyectil : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    // direccion True  para derecha
    // direccion False para izquierda
    bool direccion;

public:
    proyectil(bool dir);
    ~proyectil();
public:
    void advance(int phase);
};

#endif // PROYECTIL_H
