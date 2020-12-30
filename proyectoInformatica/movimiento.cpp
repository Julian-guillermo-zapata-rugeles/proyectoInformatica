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

void Movimiento::setStatus_saltando(bool value)
{
    status_saltando = value;
}

bool Movimiento::getStatus_saltando() const
{
    return status_saltando;
}

void Movimiento::moverParabolicamente()
{
    posX = posX + 1;
    //posX = posX;
    //posY=posY+1;
    posY = posY + (velY*timeElapse+(0.5*(-9.8*timeElapse*timeElapse)))*-1;
    timeElapse=timeElapse+0.05;
    std::cout <<" x : " << this-> posX << " / y :" << this-> posY << std::endl;
}

Movimiento::Movimiento(signed short int posX,signed short int posY,signed short int angle, unsigned short int velInit)
{
    this->posX=posX;
    this->posY=posY;
    this->velInit=velInit;
    this->angle=angle;
    this->timeElapse=0.1;
    this->status_saltando=false;
    this->limiteInferior=101;

    velX = velInit * cos((angle*3.1416)/180);
    velY = velInit * sin((angle*3.1416)/180);

}

void Movimiento::moverRectilineamente()
{
    timeElapse += 0.05;
    posX = velInit*timeElapse;
}

void Movimiento::saltar()
{
    if(status_saltando == true && posY<limiteInferior){
        velY = velInit * sin((90*3.1416)/180);
        posY = posY + (velY*timeElapse+(0.5*(-9.8*timeElapse*timeElapse)))*-1;
        timeElapse=timeElapse+0.05;
    }
    else {
        status_saltando=false;
        posY=100;
        timeElapse=0.01;
    }
}
