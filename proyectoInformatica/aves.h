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
#include "animaciones.h"

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
    //--------------- Atributos privados de la clase -----------------------------//
    QTimer *temporizadorAves;
    QPixmap *pixmapAves;
    qreal columnas, alto, ancho, tmp_sumador;
    short int velocidad , amplitud, limite , temporal;
    bool direction, dir , identity;

    // ------------    métodos privados de la clase     ---------------------------//
    void generarDireccion();
    void cambiarAnimacion();

private slots:
    void moverAves();
    void moverAvesParabolicas();
};

#endif // AVES_H
