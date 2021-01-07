#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include "cuerpo.h"
#include "bala.h"
#include <QVector>

class personaje : public cuerpo , public QGraphicsItem
{

private:

public:
    personaje(short int x , short int y, short int widht , short int height );
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
    bala *tmp_disparo;
    bool direccion;

    // movimientos asociados al personaje (heredó del cuerpo.h)
    void saltar();
    void adelante();
    void atras();
    bala * disparar();
    // función advance del personaje
    void advance(int phase);
};

#endif // PERSONAJE_H
