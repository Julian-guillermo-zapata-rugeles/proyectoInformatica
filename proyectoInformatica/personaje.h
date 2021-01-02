#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "movimiento.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <bala.h>
#include <QVector>

class personaje :public QGraphicsItem ,  public Movimiento
{
private:
    unsigned short int  ancho , alto ;
    short int nivelVida;
    bala *shoot;

public:
    bala* crearDisparo();
    void actualizar();
    personaje(signed short int posX, signed short int  posY, signed short angle, unsigned short velInit, unsigned short int ancho, unsigned short int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

};

#endif // PERSONAJE_H
