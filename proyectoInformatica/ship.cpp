#include "ship.h"

Ship::Ship(float x,
           float y,
           float masa,
           float radio,
           float vx,
           float vy,
           float ax,
           float ay,
           bool centro)
    : x(x),
      y(y),
      masa(masa),
      radio(radio),
      vx(vx),
      vy(vy),
      ax(ax),
      ay(ay),
      centro(centro)
{

}

/*
void Ship::asignarCuerpo(float x, float y, float Masa, float radio, float vx, float vy, float ax, float ay, bool centro)
{
    this->x = x;
    this->y = y;
    this->masa = Masa;
    this->radio = radio;
    this->vx = vx;
    this->vy = vy;
    this->ax = ax;
    this->ay = ay;
    this->centro = centro;
}
*/

float Ship::getX() const
{
    return x;
}

float Ship::getY() const
{
    return y;
}

float Ship::getMasa() const
{
    return masa;
}

float Ship::getRadio() const
{
    return radio;
}

float Ship::getVx() const
{
    return vx;
}

float Ship::getVy() const
{
    return vy;
}

float Ship::getAx() const
{
    return ax;
}

float Ship::getAy() const
{
    return ay;
}

float Ship::calcularDistancia(const Ship p)
{
    float distancia = 0;
    distancia = pow( x - p.getX(),2 ) + pow( y - p.getY(), 2 );      //  (x1-x2) + (y1-y2)
    distancia = sqrt(distancia);                                     // raiz de lo anterior
    return distancia;
}

float Ship::calcularAngulo(const Ship p)
{
    float angulo = 0;
    angulo = ( p.getY()- y ) / ( p.getX() - x);                     //  (y2-y1)/(y2-y1)
    angulo = atan(angulo);                                          //   tangente inversa de lo anterior
    return angulo;
}

float Ship::calcularAcX(const Ship p)
{
    float aceleracion = G * p.getMasa() * cos( calcularAngulo(p) ) / pow( calcularDistancia(p),2);     //gravitacion universal
    if( x > p.getX()){
        aceleracion = -aceleracion;  //Signo correcto de la aceleracion
    }
    return aceleracion;
}

float Ship::calcularAcY(const Ship p)
{
    float aceleracion = G * p.getMasa() * sin( calcularAngulo(p) ) / pow( calcularDistancia(p),2);
    if(x > p.getX()){
        aceleracion = -aceleracion;
    }
    return aceleracion;
}

void Ship::calcularPosicion(float dt)
{
    this->x += vx*dt + ax*dt*dt/2;
    this->y += vy*dt + ay*dt*dt/2;
    this->vx += ax*dt;
    this->vy += ay*dt;
}

void Ship::sumarAceleracion(float Ax, float Ay)
{
    this->ax += Ax;
    this->ay += Ay;
}

void Ship::asignarAceleracion(float Ax, float Ay)
{
    this->ax=Ax;
    this->ay=Ay;
}

void Ship::asignarPosicion(float px, float py)
{
    x += px;
    y += py;
}

void Ship::asignarMov()
{
    x += 0.2;
    y += 0.2;
}

bool Ship::getCentro() const
{
    return centro;
}

void Ship::setX(float value)
{
    x = value;
}

void Ship::setY(float value)
{
    y = value;
}
