#ifndef AVES_H
#define AVES_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <math.h>

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
    QTimer *timerAves;
    QTimer *timerAvesParabolicas;
    QPixmap *AvePix;

    qreal columnas, alto, ancho, tmp_sumador;
    long int velocidad;
    short int amplitud, limite;
    bool direction;

    void birdAppearance();
    void cambiarAnimacion();

public slots:
    void moverAves();
    void moverAvesParabolicas();

};

#endif // AVES_H
