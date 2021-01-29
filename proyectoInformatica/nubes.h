#ifndef NUBES_H
#define NUBES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <random>
#include <QDebug>

class nubes : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    nubes();
    ~nubes();
private:
    bool dir;
    void generarAspecto();
    void generarAleatoriedad();


    // QGraphicsItem interface
public:
    void advance(int phase);
};

#endif // NUBES_H
