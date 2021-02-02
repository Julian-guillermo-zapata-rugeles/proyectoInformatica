#ifndef BONUSROCKET_H
#define BONUSROCKET_H

#include <movimientos.h>
#include <QTimer>
#include <QPixmap>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <random>
#include <QGraphicsRectItem>

class BonusRocket: public QObject, public movimientos, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BonusRocket(qreal x, qreal y);
    ~BonusRocket();

protected:
    short int lifeTime;
    QTimer *timeLife;
    QPixmap *pixBonus;
    qreal x,y,opacidad;

protected slots:
    void actualizar();

};

#endif // BONUSROCKET_H
