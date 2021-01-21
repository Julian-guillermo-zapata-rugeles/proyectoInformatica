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
     QTimer *timer;
     qreal last_position;
     QMediaPlayer *sonido = new QMediaPlayer();
     QPixmap *pixmap_zombie;
     short int alto , ancho , columnas;
     void cambiarAnimacion();
public:
    enemigo(qreal lastPosition);
    ~enemigo();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
private slots:
    void moverEnemigo();


};

#endif // ENEMIGO_H
