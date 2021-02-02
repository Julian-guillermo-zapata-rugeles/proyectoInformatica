#ifndef ASTEROIDES_H
#define ASTEROIDES_H
//#define DEBUG_ASTEROIDE

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

class asteroides :public QObject , public QGraphicsRectItem
{
    Q_OBJECT

private:
    QMediaPlayer *sonido;
    QTimer *timer;
    signed short int rotationAngle;
    void generarAspecto();
    bool fire;

    //Animacion de los Meteoros
    qreal ancho, alto, frame, limite;
    bool rotar, animado;
    short int caida;
    QPixmap *meteoros;

public:
    asteroides(bool sound=true);
    asteroides(short int n);
    asteroides(qreal x, qreal y);
    ~asteroides();

    //Animacion de los meteoros
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void animarMeteoro();

private slots:
    void moverAsteroide();

};

#endif // ASTEROIDES_H
