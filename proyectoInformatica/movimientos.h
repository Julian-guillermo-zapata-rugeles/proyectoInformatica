#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include <math.h>

/*
objetivo :
    dotar de movimiento al personaje
    movimiento parabolico para el salto del personaje

*/
class movimientos
{
private:
    float velocidadY;
    bool status_saltando;
    float limite_inferior;
public:
    movimientos();
};

#endif // MOVIMIENTOS_H
