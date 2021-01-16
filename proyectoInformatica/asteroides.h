#ifndef ASTEROIDES_H
#define ASTEROIDES_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <random>
#include <QMediaPlayer>
#include <QVector>
#include <QTimer>

class asteroides :public QObject , public QGraphicsRectItem
{
    Q_OBJECT

private:
    QMediaPlayer *sonido = new QMediaPlayer();
    QTimer *timer;
public:
    asteroides();

private slots:
    void moverAsteroide();
};

#endif // ASTEROIDES_H
