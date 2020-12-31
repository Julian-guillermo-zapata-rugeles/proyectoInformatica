#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsTextItem>
#include <QPainter>

class Obstaculo: public QGraphicsItem
{
public:
    Obstaculo(signed short int posx, signed short int posy, signed short int ancho, signed short int alto);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

private:
    signed short int posX;
    signed short int posY;
    signed short int ancho;
    signed short int alto;
};

#endif // OBSTACULO_H
