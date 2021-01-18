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

class enemigoGigante : public QObject , public QGraphicsRectItem , public movimientos
{
    Q_OBJECT
private:
    QTimer *timer = new QTimer();
    qreal last_position;
    short int disparosSoportados;
    QMediaPlayer *sonido = new QMediaPlayer();
    bool dir;
    bool saltando;
public:
    enemigoGigante(qreal lastPosition , bool saltando = false);
    ~enemigoGigante();

private slots:
    void moverEnemigo();
};

#endif // ENEMIGO_H
