#ifndef BALA_H
#define BALA_H
#include <QGraphicsTextItem>
#include <QPainter>
#include "movimientoparabolico.h"

class bala : public QGraphicsItem , public MovimientoParabolico
{
private:
    signed short int ancho;
    signed short int alto;

public:
    bala(signed short int posX,signed short int posY,signed short int angle, unsigned short int velInit,
         signed short int ancho,signed short int alto);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
};

#endif // BALA_H
