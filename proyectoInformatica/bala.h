#ifndef BALA_H
#define BALA_H
#include <QGraphicsTextItem>
#include <QPainter>
#include "movimiento.h"
#include <QPixmap>

class bala : public QGraphicsItem , public Movimiento
{
private:
    signed short int ancho;
    signed short int alto;
    QPixmap *pixmap; //creamos un Qpixmap
    bool status_add;

public:
    bala(float posX,float posY,signed short int angle, unsigned short int velInit,
         float ancho,float alto);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
};

#endif // BALA_H
