#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>

class personaje : public QGraphicsRectItem , public QObject
{

private:
    QMediaPlayer *sonido = new QMediaPlayer();
    bool dir;
    short int disparos_disponibles;
public:
    personaje();
    void keyPressEvent(QKeyEvent *event);
    qreal getLastPosition();
};

#endif // PERSONAJE_H
