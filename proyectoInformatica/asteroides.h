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
#include <enemigo.h>
#include <enemigoGigante.h>
#include <chrono>
#include <animaciones.h>

/*
Objetivos :
    Generar asteroides basado en multiples condiciones
    -deben ser aleatorio en posición y pixmap (los pixmas actuales son temporales y deben ser modificados)
        por otros que tengan más paleta de color con la escena.
    -debe estar sobrecargado para el evento final (cuando el personaje se debe morir si o sí)
        NOTA : fase experimental del final del juego , 1 nivel.
            BUGS : se debe corregir la visualización y el punto de choque.
                   Dimensiones , y aceleración o tiempo de caida además del pixmap.


*/

class asteroides :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QMediaPlayer *sonido = new QMediaPlayer();
    signed short int rotationAngle , velocidad_caida;
    bool fire=false;

    void generarAspecto();
    void generarAleatoriedad();
    void generarSonidos();

public:
    asteroides(bool sound=true);
    asteroides(qreal x, qreal y);
    ~asteroides();

    // QGraphicsItem interface
public:
    void advance(int phase);
};

#endif // ASTEROIDES_H
