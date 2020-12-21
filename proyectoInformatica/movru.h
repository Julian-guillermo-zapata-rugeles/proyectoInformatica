#ifndef MOVRU_H
#define MOVRU_H
#include <math.h>

class MovRU
{
protected:
    signed short int posX;
    signed short int posY;
    signed short int velInit;
    signed short int angle;
    float time;


public:
    MovRU(signed short int posX, signed short int posY, signed short int angle, signed short int velInit);
    void moverRU();

    signed short getPosX() const;
    void setPosX(signed short value);
    signed short getPosY() const;
    void setPosY(signed short value);
};

#endif // MOVRU_H
