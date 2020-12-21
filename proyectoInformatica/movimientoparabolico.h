#ifndef MOVIMIENTOPARABOLICO_H
#define MOVIMIENTOPARABOLICO_H


class MovimientoParabolico
{
protected:
    signed short int posX;
    signed short int posY;
    signed short int angle;
    unsigned short int velInit;
    unsigned short int timeElapse;
    signed short int aceleration;

public:
    MovimientoParabolico();
};

#endif // MOVIMIENTOPARABOLICO_H
