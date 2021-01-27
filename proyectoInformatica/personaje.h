#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <proyectil.h>
#include <bonus_municion.h>
#include <movimientos.h>
#include <QPixmap>
#include <string>


class personaje : public QGraphicsRectItem , public movimientos
{
private:
    QMediaPlayer *sonido = new QMediaPlayer();
    bool dir;
    short int disparos_disponibles;
    qreal ancho, alto, fila, columna, limite=1550;
    QPixmap *pixPersonaje;


public:
    personaje();
    void keyPressEvent(QKeyEvent *event);
    qreal getLastPosition();
    void eventHandler();

    bool ifcollide();
    short getDisparos_disponibles() const;

    void setState(std::string estado);
    void actualizarEstado();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PERSONAJE_H
