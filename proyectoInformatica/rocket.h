#ifndef ROCKET_H
#define ROCKET_H

#include <movimientos.h>
#include <QTimer>
#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <random>
#include <QGraphicsRectItem>
#include "animaciones.h"

class Rocket: public QObject, public movimientos, public QGraphicsItem
{
    Q_OBJECT
public:
    Rocket(qreal x, qreal y);
    ~Rocket();

private:
    short int lifeTime;
    QTimer *timeRocket;
    QPixmap *pixRocket;
    qreal x,y;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private slots:
    void actualizarR();

};

#endif // ROCKET_H
