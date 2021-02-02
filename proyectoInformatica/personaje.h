#ifndef PERSONAJE_H
#define PERSONAJE_H
#define DEBUG_PERSONAJE

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
#include <rocket.h>
#include <bonusrocket.h>
#include "bonuslife.h"

class personaje : public QGraphicsRectItem, public movimientos
{
private:
    QMediaPlayer *sonido = new QMediaPlayer();
    bool dir;
    short int disparos_disponibles;
    short int vida_disponible;
    qreal ancho, alto, fila, columna, limite;
    QPixmap *pixPersonaje;
    bool pressKey;
    bool stateShoot;
    bool stateSlide;
    bool stateKatana;
    bool flying;
    short int impulsos;
    short int puntos, *GlobalPuntos;

public:
    personaje();

    void teclas(QKeyEvent *event);
    void teclas2(QKeyEvent *event);
    qreal getLastPosition();
    void eventHandler();
    short getDisparos_disponibles() const;

    void setState(std::string estado);
    void actualizarEstado();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool getPressKey() const;
    void setPressKey(bool value);
    bool getStateShoot() const;
    short getVida_disponible() const;
    short getImpulsos() const;
    short getPuntos() const;
    void setPuntos(short value);
    void setDisparos_disponibles(short value);
    void setVida_disponible(short value);
};

#endif // PERSONAJE_H
