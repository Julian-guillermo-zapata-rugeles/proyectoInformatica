#ifndef BONUS_MUNICION_H
#define BONUS_MUNICION_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QGraphicsPixmapItem>

class bonus_municion : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bonus_municion();
private:

private slots:
    // contador para la munición //
    // se establecerá cuanto tiempo permanecerá la munición en pantalla antes de autoeliminarse.
    QTimer *timer = new QTimer();
};

#endif // BONUS_MUNICION_H
