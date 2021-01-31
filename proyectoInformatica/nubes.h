#ifndef NUBES_H
#define NUBES_H
//#define DEBUG_NUBES

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
    QTimer *timer;
    void generarAspecto();

private slots:
    void moverNubes();
};

#endif // NUBES_H
