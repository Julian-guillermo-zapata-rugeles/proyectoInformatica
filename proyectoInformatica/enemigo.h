#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <proyectil.h>
#include <random>
#include <QTimer>
#include <movimientos.h>
#include <QMediaPlayer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>

class enemigo : public QObject , public QGraphicsRectItem , public movimientos
{
    Q_OBJECT
private:
    bool direction; // true Derecha // false izquierda
    qreal alto , ancho , columnas , last_position;
    QTimer *timer;
    QPixmap *pixmap_zombie;
    QMediaPlayer *sonido = new QMediaPlayer();

    float velocidad;
    short int amplitud;

    // metodos privados

    void cambiarAnimacion(); // encargado el movimiento del sprite // refresco
    void asignarCaracteristicas(); // asignar aleatoriamente pixmap y posicion.
    void birdAppearance();

public:
    enemigo(qreal lastPosition);
    enemigo(bool flat);

    ~enemigo();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );


private slots:
    void moverEnemigo();
    void moverAves();

};

#endif // ENEMIGO_H
