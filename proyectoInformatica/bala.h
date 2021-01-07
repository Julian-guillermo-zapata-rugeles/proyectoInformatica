#ifndef BALA_H
#define BALA_H
#include <QGraphicsTextItem>
#include <QPainter>
#include "cuerpo.h"
#include <QPixmap>

class bala : public QGraphicsItem , public cuerpo
{

private:
    bool direccion; // false para izquierda // true para derecha
public:
    bala(short int posX, short int  posY, short int ancho, short int  alto , bool dir );
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

    //  movimientos del proyectil basicos
    void adelante();
    void atras();

    // actualización del objeto
    void advance(int phase);
};

#endif // BALA_H

