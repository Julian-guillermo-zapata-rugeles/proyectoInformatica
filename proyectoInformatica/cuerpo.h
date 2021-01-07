#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>

class cuerpo
{

protected:
    // todos los objetos graficos poseen al menos una coordenada en pantalla
    // un ancho y un alto que serán usados por QgraphicsItem
    // esto serán heredados.

    short int coordenadaX , coordenadaY , angulo , velocidadInicial;
    short int ancho , alto;
    float tiempo , velocidadX , velocidadY;

    // estados del cuerpo

    short int posicionInicial;
    bool status_saltando;

    // movimientos asociados a los cuerpos //
    void salto();
    void moverDerecha();
    void moverIzquierda();
    void caidaLibre();

public:
    // constructor para cuerpos
    cuerpo(short int pos_x , short int pos_y , short int ancho_ , short int alto_ );
    cuerpo(short int pos_x, short int  pos_Y , short int ancho_ , short int alto_ , short int angle, short int velInit); // tiros parabolicos

    short getCoordenadaX() const;
    short getCoordenadaY() const;
};

#endif // CUERPO_H
