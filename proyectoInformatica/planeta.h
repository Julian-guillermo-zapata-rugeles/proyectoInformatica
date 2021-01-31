#ifndef PLANETA_H
#define PLANETA_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "ship.h"
#include <QDebug>
#include <fstream>
#include <animaciones.h>
#include <rocket.h>

#define h_lim 1300
#define v_lim 600

class Planeta: public QGraphicsPixmapItem
{

public:
    Planeta(float posX=0,
            float posY=0,
            float masa=0,
            float radio = 0,
            float velX=0,
            float velY=0,
            float AcX=0,
            float AcY=0);

    ~Planeta();

    void asignarEscala(float s);
    void actualizar(float dt);
    Ship *obtenerCuerpo();

    //QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    //void paint(QPainter *pintar, const QStyleOptionGraphicsItem *opcion, QWidget *widget); //define como se pintara el objeto

    bool getVerificar() const;

private:
    Ship *planeta;
    QPixmap *planet;
    float escala;

    void eleccionPixmap(short int opcion);
};

#endif // PLANETA_H
