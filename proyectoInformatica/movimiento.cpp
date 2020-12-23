#include "movimiento.h"


signed short Movimiento::getAngle() const
{
    return angle;
}

void Movimiento::setAngle(signed short value)
{
    angle = value;
}

unsigned short Movimiento::getVelInit() const
{
    return velInit;
}

void Movimiento::setVelInit(unsigned short value)
{
    velInit = value;
}

void Movimiento::moverParabolicamente()
{
    posX = velInit*timeElapse;
    posY = (velY*timeElapse+(0.5*(-9.8*timeElapse*timeElapse)))*-1;
    timeElapse=timeElapse+0.05;
    std::cout << this-> posX << std::endl;
    std::cout << this-> posY << std::endl;
}

Movimiento::Movimiento(signed short int posX,signed short int posY,signed short int angle, unsigned short int velInit)
{
    this->posX=posX;
    this->posY=posY;
    this->velInit=velInit;
    this->angle=angle;
    this->timeElapse=0.1;
    std::cout << this->posX << std::endl;
    std::cout << this->posY << std::endl;
    std::cout << this->velInit << std::endl;
    std::cout << this->angle << std::endl;
    velX = velInit * cos((angle*3.1416)/180);
    velY = velInit * sin((angle*3.1416)/180);
}

void Movimiento::moverRectilineamente()
{
    timeElapse += 0.05;
    posX = velInit*timeElapse;
}
