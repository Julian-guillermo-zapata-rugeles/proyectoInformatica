#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <personaje.h> // propia
#include <QKeyEvent>
#include <QDebug>
#include <mundoterrestre.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MenuInicio *inicio = new MenuInicio();
    //inicio->show();
    mundoTerrestre * primerNivel = new mundoTerrestre();
    primerNivel->iniciarMundo();

    return a.exec();
}
