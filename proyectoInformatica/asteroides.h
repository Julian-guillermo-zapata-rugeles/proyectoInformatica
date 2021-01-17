#ifndef ASTEROIDES_H
#define ASTEROIDES_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <random>
#include <QMediaPlayer>
#include <QVector>
#include <QTimer>
#include <enemigo.h>
#include <enemigoGigante.h>

class asteroides :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QMediaPlayer *sonido = new QMediaPlayer();
    QTimer *timer;
    signed short int rotationAngle;
    void generarAspecto();
public:
    asteroides();

private slots:
    void moverAsteroide();
};

#endif // ASTEROIDES_H
