#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "movimientoparabolico.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class personaje : public MovimientoParabolico , public QGraphicsItem
{
protected:
    unsigned short int ancho , alto ;
    signed short int nivelVida;
public:
    personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
};

#endif // PERSONAJE_H
