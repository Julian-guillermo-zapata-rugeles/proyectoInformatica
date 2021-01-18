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
    float intervaloSuma ;
    float tmp_sumador;
    bool status_saltando;
    bool status_gravitatorio;

    void saltar();
    void gravitar();
public:
    movimientos(float limiteInferior);
    bool getStatus_saltando() const;
    void setStatus_saltando(bool value);
    bool getStatus_gravitatorio() const;
    void setStatus_gravitatorio(bool value);
    float getIntervaloSuma() const;
    void setIntervaloSuma(float value);
};

#endif // MOVIMIENTOS_H
