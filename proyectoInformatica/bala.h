#ifndef BALA_H
#define BALA_H
#include <QGraphicsTextItem>
#include <QPainter>
#include "movimientoparabolico.h"
#include "movru.h"

class bala : public QGraphicsItem , public MovimientoParabolico , public MovRU
{
private:
    signed short int ancho;
    signed short int alto;
    bool moving= false ;

public:
    void moverRectilineamente();
    void moverParabolicamente();
    bala(signed short int posX,signed short int posY,signed short int angle, unsigned short int velInit,
         signed short int ancho,signed short int alto);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
};

#endif // BALA_H
