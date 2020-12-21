#ifndef MOVIMIENTOPARABOLICO_H
#define MOVIMIENTOPARABOLICO_H
#include <iostream>
#include <math.h>
using namespace std;

class MovimientoParabolico
{

protected:
    signed short int posX;
    signed short int posY;
    signed short int velX;
    signed short int velY;
    signed short int angle;
    unsigned short int velInit;
    signed short int aceleration;
    unsigned short int timeElapse;

public:
    void mover();
    MovimientoParabolico(signed short int posX,signed short int posY,signed short int angle, unsigned short int velInit);
    signed short getAngle() const;
    void setAngle(signed short value);
    unsigned short getVelInit() const;
    void setVelInit(unsigned short value);
};

#endif // MOVIMIENTOPARABOLICO_H
