#ifndef AVES_H
#define AVES_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <math.h>
#include "proyectil.h"

class Aves: public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Aves();
    Aves(short int op);
    ~Aves();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

private:

    QPixmap *AvePix;
    qreal columnas, alto, ancho, tmp_sumador;
    long int velocidad;
    short int amplitud, limite;
    bool direction,  dir , senoidal ;
    unsigned short int temporal=0;
    bool identity=false;

    void birdAppearance();
    void cambiarAnimacion();

public:
    void advance(int phase);
};

#endif // AVES_H
