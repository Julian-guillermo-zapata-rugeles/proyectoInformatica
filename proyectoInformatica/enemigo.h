#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <proyectil.h>
#include <random>
#include <movimientos.h>
#include <QMediaPlayer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include "animaciones.h"
#include "personaje.h"

class enemigo : public QObject , public QGraphicsRectItem , public movimientos
{
    Q_OBJECT
private:
    bool direction; // true Derecha // false izquierda
    QPixmap *pixmap_zombie;
    QMediaPlayer *sonido = new QMediaPlayer();
    qreal columnas, alto, ancho, *last_position;
    long int velocidad;
    short int  amplitud ,  limite , velocidad_dezplazamiento;
    unsigned short int temporal=0;
    bool habilidad=false;


    // metodos privados

    void cambiarAnimacion(); // encargado el movimiento del sprite // refresco
    void asignarCaracteristicas(); // asignar aleatoriamente pixmap y posicion.


public:
    enemigo(qreal *lastPosition);

    ~enemigo();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

public:
    void advance(int phase);
};

#endif // ENEMIGO_H
