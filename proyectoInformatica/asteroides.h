#ifndef ASTEROIDES_H
#define ASTEROIDES_H
#include <QGraphicsItem>
#include <QPainter>
#include "cuerpo.h"


class asteroides : public cuerpo , public QGraphicsItem
{
private:
    signed short int valor_destruccion;
public:
    asteroides(short int posX, short int  posY, short int ancho, short int  alto , short int vdestruccion);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
    void advance(int phase);
    bool destruir();
};

#endif // ASTEROIDES_H
