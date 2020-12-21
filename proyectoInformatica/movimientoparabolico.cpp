#include "movimientoparabolico.h"


signed short MovimientoParabolico::getAngle() const
{
    return angle;
}

void MovimientoParabolico::setAngle(signed short value)
{
    angle = value;
}

unsigned short MovimientoParabolico::getVelInit() const
{
    return velInit;
}

void MovimientoParabolico::setVelInit(unsigned short value)
{
    velInit = value;
}

void MovimientoParabolico::mover()
{
    posX = velX*timeElapse;
    posY = 0+velY*timeElapse+(0.5*(-9.8*timeElapse*timeElapse));
}

MovimientoParabolico::MovimientoParabolico(signed short int posX,signed short int posY,signed short int angle, unsigned short int velInit)
{
    this->posX=posX;
    this->posY=posY;
    this->velInit=velInit;
    this->angle=angle;
    velX = velInit * cos((angle*3.1416)/180);
    velY = velInit * sin((angle*3.1416)/180);
}
