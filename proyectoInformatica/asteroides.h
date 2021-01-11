#ifndef ASTEROIDES_H
#define ASTEROIDES_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <random>
#include <QMediaPlayer>
#include <QVector>

class asteroides :public QObject , public QGraphicsRectItem
{
    Q_OBJECT

private:
    QMediaPlayer *sonido = new QMediaPlayer();
public:
    asteroides();
    bool moverAsteroide();
};

#endif // ASTEROIDES_H
