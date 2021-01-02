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



void Movimiento::moverRectilineamente()
{

    //timeElapse += 0.05;
    posX = posX + 5;
}

void Movimiento::moverDerecha()
{
    posX=posX+2;
}

void Movimiento::moverIzquierda()
{
    posX=posX-2;
}

void Movimiento::saltar()
{
    if(status_saltando == true && posY<limiteInferior+1){
        velY = velInit * sin((90*3.1416)/180);
        posY = posY + (velY*timeElapse+(0.5*(-9.8*timeElapse*timeElapse)))*-1;
        timeElapse=timeElapse+0.05;
    }
    else {
        status_saltando=false;
        posY=limiteInferior;
        timeElapse=0.01;
    }
}

Movimiento::Movimiento(signed short posX, signed short posY, signed short angle, unsigned short velInit)
{
    this->posX=posX;
    this->posY=posY;
    this->velInit=velInit;
    this->angle=angle;
    this->timeElapse=0.1;
    this->status_saltando=false;
    this->limiteInferior=posY;

    velX = velInit * cos((angle*3.1416)/180);
    velY = velInit * sin((angle*3.1416)/180);
}
