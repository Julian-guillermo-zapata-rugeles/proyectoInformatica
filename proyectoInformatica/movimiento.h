#ifndef Movimiento_H
#define Movimiento_H
#include <iostream>
#include <math.h>
using namespace std;

class Movimiento
{

protected:
    float posX;
    float posY;
    float velX;
    float velY;
    signed short int angle;
    signed short int limiteInferior;
    bool status_saltando;
    unsigned short int velInit;
    signed short int aceleration;
    float timeElapse;

public:
    void moverParabolicamente();
    void moverRectilineamente();
    void moverDerecha();
    void moverIzquierda();
    void saltar();
    Movimiento(float posX,float posY,signed short int angle, unsigned short int velInit);

    signed short getAngle() const;
    void setAngle(signed short value);
    unsigned short getVelInit() const;
    void setVelInit(unsigned short value);
    void setStatus_saltando(bool value);
    bool getStatus_saltando() const;
};

#endif // Movimiento_H
