#ifndef LUNACRECIENTE_H
#define LUNACRECIENTE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

class lunaCreciente : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    lunaCreciente();
private:
    QTimer *timer = new QTimer();
};

#endif // LUNACRECIENTE_H
