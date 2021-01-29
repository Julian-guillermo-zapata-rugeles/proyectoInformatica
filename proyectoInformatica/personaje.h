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
#include <aves.h>
#include <planeta.h>


class personaje : public QGraphicsRectItem, public movimientos
{
private:
    QMediaPlayer *sonido = new QMediaPlayer();
    bool dir;
    short int disparos_disponibles;
    short int vida_disponible;
    qreal ancho, alto, fila, columna, limite=1550;
    QPixmap *pixPersonaje;
    bool pressKey=false;
    bool stateShoot=false;
    bool stateSlide=false;
    bool stateKatana = false;
    bool pointer_pause;


public:
    personaje();
    void keyPressEvent(QKeyEvent *event);
    qreal getLastPosition();
    void eventHandler();
    short getDisparos_disponibles() const;
    void setState(std::string estado);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool getPressKey() const;
    void setPressKey(bool value);
    bool getStateShoot() const;
    short getVida_disponible() const;
    bool getPointer_pause() const;

    // QGraphicsItem interface
public:
    void advance(int phase);
};

#endif // PERSONAJE_H
