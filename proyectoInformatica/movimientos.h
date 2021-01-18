#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include <math.h>
#include <QDebug>

/*
objetivo :
    dotar de movimiento al personaje
    movimiento parabolico para el salto del personaje

*/
class movimientos
{
 protected:
    float velocidadY;
    float limite_inferior;
    float posY;
    float tiempo;
    bool status_saltando;

    void saltar();
public:
    movimientos(float limiteInferior);
    bool getStatus_saltando() const;
    void setStatus_saltando(bool value);
};

#endif // MOVIMIENTOS_H
