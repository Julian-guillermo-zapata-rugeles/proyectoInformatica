#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <personaje.h> // propia
#include <QKeyEvent>
#include <QDebug>
#include <mundoterrestre.h>
#include <cliente.h>
#include <QTime>
#include <QIcon>

bool playing = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/multimedia/icon.png"));

    cliente cliente_juego;
    cliente_juego.show();
    //mundoTerrestre * primerNivel = new mundoTerrestre();
    //primerNivel->iniciarMundo();

    return a.exec();
}
