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
    signed short int  ancho , alto ;
    signed short int nivelVida;
    bala *shoot;

public:
    bala* crearDisparo();
    void actualizar();
    personaje(signed short posX, signed short posY, signed short angle, unsigned short velInit, signed short ancho, signed short alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

};

#endif // PERSONAJE_H
