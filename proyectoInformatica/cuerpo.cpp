#include "cuerpo.h"


cuerpo::cuerpo(short posx, short posy, short ancho, short alto)
{
    this->coordenadaX=posx;
    this->coordenadaY=posy;
    this->ancho = ancho ;
    this->alto = alto ;
    this->status_saltando=false;
    this->posicionInicial=coordenadaY;
    this->tiempo = 0.1;
}


short cuerpo::getCoordenadaX() const
{
    return coordenadaX;
}

short cuerpo::getCoordenadaY() const
{
    return coordenadaY;
}

void cuerpo::salto()
{
    if(status_saltando == true && coordenadaY<posicionInicial+1){
        velocidadY = 10 * sin((90*3.1416)/180);
        coordenadaY = coordenadaY + (velocidadY*tiempo+(0.5*(-9.8*tiempo*tiempo)))*-1;
        tiempo=tiempo+0.05;
    }
    else {
        status_saltando=false;
        coordenadaY=posicionInicial;
        tiempo=0.01;
    }
}

void cuerpo::moverDerecha()
{
    coordenadaX=coordenadaX+6;
}

void cuerpo::moverIzquierda()
{
    coordenadaX=coordenadaX-6;
}

void cuerpo::caidaLibre()
{
    coordenadaY=coordenadaY+5;
}
