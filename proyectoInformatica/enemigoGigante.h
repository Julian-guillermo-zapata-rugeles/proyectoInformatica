#ifndef ENEMIGOGIGANTE_H
#define ENEMIGOGIGANTE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <proyectil.h>
#include <random>

class enemigoGigante : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
private:
    QTimer *timer = new QTimer();
    qreal last_position;
    short int disparosSoportados;
public:
    enemigoGigante(qreal lastPosition);

private slots:
    void moverEnemigo();
};

#endif // ENEMIGO_H
