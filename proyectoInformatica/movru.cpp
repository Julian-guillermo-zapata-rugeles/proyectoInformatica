#include "movru.h"

MovRU::MovRU(signed short int posX, signed short int posY, signed short int angle, signed short int velInit)
{
    this->posX=posX;
    this->posX=posY;
    this->angle=angle;
    this->velInit=velInit;
}

signed short MovRU::getPosY() const
{
    return posY;
}

void MovRU::setPosY(signed short value)
{
    posY = value;
}

void MovRU::moverRU()
{

}

signed short MovRU::getPosX() const
{
    return posX;
}

void MovRU::setPosX(signed short value)
{
    posX = value;
}
