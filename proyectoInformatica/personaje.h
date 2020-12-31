#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "movimiento.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <bala.h>
#include <QVector>

class personaje : public Movimiento , public QGraphicsItem
{
private:
    float  ancho , alto ;
    float nivelVida;
    bala *shoot;

public:
    bala* crearDisparo();
    void actualizar();
    personaje(float posX, float posY, signed short angle, unsigned short velInit, float ancho, float alto);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

};

#endif // PERSONAJE_H
