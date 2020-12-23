#ifndef Movimiento_H
#define Movimiento_H
#include <iostream>
#include <math.h>
using namespace std;

class Movimiento
{

protected:
    signed short int posX;
    signed short int posY;
    signed short int velX;
    signed short int velY;
    signed short int angle;
    unsigned short int velInit;
    signed short int aceleration;
    float timeElapse;

public:
    void moverParabolicamente();
    void moverRectilineamente();
    Movimiento(signed short int posX,signed short int posY,signed short int angle, unsigned short int velInit);

    signed short getAngle() const;
    void setAngle(signed short value);
    unsigned short getVelInit() const;
    void setVelInit(unsigned short value);

};

#endif // Movimiento_H
