#ifndef BONUS_MUNICION_H
#define BONUS_MUNICION_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class bonus_municion : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bonus_municion(qreal x, qreal y);
    // se puede sobre cargar para tener varios bunus.
private:
    // contador para la munición //
    // se establecerá cuanto tiempo permanecerá la munición en pantalla antes de autoeliminarse.
     QTimer *timer = new QTimer();
private slots:
     void destruirCaja();

};

#endif // BONUS_MUNICION_H
