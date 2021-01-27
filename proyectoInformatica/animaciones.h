#ifndef ANIMACIONES_H
#define ANIMACIONES_H

/*
El objetivo de esta clase es dotar de animaciones útiles para los objetos
con un tiempo de vida de 1 sprite.
Estas animaciones serán usadas por los objetos a destruir en sus destructores
llamando así a una animación (que vivirá durante un segundo y se autodestruirá)
eliminandose de memoria y  de la escena

la sintaxis para su uso es :

--> new Animacion(posicionX , posicionY , tipoAnimacion , sobrecarga )
        -qreal  posicionX y posicionY será respectivamente la ubicación del objeto que se está eliminando
            para presentar la animación de destrucción o muerte en esa coordenada

        - short int tipo será la animación a presentar disponible (están enumeradas)
        - bool se usará por defecto.

*/


#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsScene>
#include <QDebug>

class Animaciones : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

     Animaciones(qreal posx, qreal posy , short int tipo, bool v=false);
    ~Animaciones();

private:
    // tiempo de vida será un periodo de animación.
    QTimer *tiempoVida = new QTimer;
    QPixmap *deadpix;

    // se usará un ancho , alto y frame para renderizar el pixmap
    float ancho, alto, frame, limite;
    bool complete;

    // Interfaz para el uso de QgraphicsItem
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void animar(); // función que refrescará los cuadros de cada sprite

public slots:
    // único slot que dará la frecuencia de actualización del sprite / cambio cuadros
    void actualizar();
};

#endif // ANIMACIONES_H
