#ifndef LUNACRECIENTE_H
#define LUNACRECIENTE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class lunaCreciente : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    lunaCreciente();
private:
    qreal escalaLunar ;
    QTimer *timer = new QTimer();

private slots:
    void crecer();
};

#endif // LUNACRECIENTE_H
