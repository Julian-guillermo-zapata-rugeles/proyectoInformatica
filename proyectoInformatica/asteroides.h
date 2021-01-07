#ifndef ASTEROIDES_H
#define ASTEROIDES_H
#include <QGraphicsItem>
#include <QPainter>
#include "cuerpo.h"


class asteroides : public cuerpo , public QGraphicsItem
{
public:
    asteroides(short int posX, short int  posY, short int ancho, short int  alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
    void advance(int phase);
};

#endif // ASTEROIDES_H
