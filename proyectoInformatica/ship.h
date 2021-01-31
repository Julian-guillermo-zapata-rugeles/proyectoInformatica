#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <cmath>
#include <vector>

#define G 1

class Ship
{
public:
    Ship(float x=0,
         float y=0,
         float Masa=0,
         float Radio=0,
         float vx=0,
         float vy=0,
         float ax=0,
         float ay=0,
         bool centro=false);

    /*
    void asignarCuerpo(float x=0,
                       float y=0,
                       float Masa=0,
                       float radio=0,
                       float vx=0,
                       float vy=0,
                       float ax=0,
                       float ay=0,
                       bool centro=false);
                       */

    float getX() const;
    float getY() const;
    float getMasa() const;
    float getRadio() const;
    float getVx() const;
    float getVy() const;
    float getAx() const;
    float getAy() const;

    void setX(float value);
    void setY(float value);

    float calcularDistancia(const Ship p);
    float calcularAngulo(const Ship p);
    float calcularAcX(const Ship p);
    float calcularAcY(const Ship p);
    void calcularPosicion(float dt);
    void sumarAceleracion(float Ax, float Ay);
    void asignarAceleracion(float Ax=0, float Ay=0);
    void asignarPosicion(float px, float py);

    void asignarMov();
    bool getCentro() const;

private:
    float x, y, masa, radio, vx, vy, ax, ay;
    bool centro;
};

#endif // SHIP_H
