#ifndef ANIMACIONES_H
#define ANIMACIONES_H

#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsScene>
#include <QDebug>

class Animaciones : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
     Animaciones(qreal posx, qreal posy , short int tipo);
    ~Animaciones();

signals:

private:
    QTimer *tiempoVida = new QTimer;
    QPixmap *deadpix;

    float ancho, alto, frame;
    bool complete;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void animar();

public slots:
    void actualizar();
};

#endif // ANIMACIONES_H
