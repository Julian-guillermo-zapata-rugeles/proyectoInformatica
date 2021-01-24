#ifndef ENEMIGOGIGANTE_H
#define ENEMIGOGIGANTE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <proyectil.h>
#include <random>
#include <bonus_municion.h>
#include <QMediaPlayer>
#include <movimientos.h>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>

class enemigoGigante : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
private:
    QTimer *timer = new QTimer();
    QMediaPlayer *sonido = new QMediaPlayer();
    qreal last_position , alto , ancho , columnas ;
    short int disparosSoportados;
    bool direction , saltando ;
    QPixmap *pixmap_zombie;

    void cambiarAnimacion(); // encargado el movimiento del sprite // refresco
    void asignarCaracteristicas(); // asignar aleatoriamente pixmap y posicion.
public:
    enemigoGigante(qreal lastPosition );
    ~enemigoGigante();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

private slots:
    void moverEnemigo();
};

#endif // ENEMIGO_H
