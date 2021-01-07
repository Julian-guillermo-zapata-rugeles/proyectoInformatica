#include "personaje.h"

personaje::personaje(short x, short y, short w, short h):cuerpo(x,y,w,h)
{
    // inicialización de variables, pero si el constructor de cuerpo.
    direccion=true;
}

QRectF personaje::boundingRect() const
{
    return  QRectF(coordenadaX,coordenadaY,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

void personaje::saltar(){
    // esta función modifica el estado saltando , por ende cuando el timeout() llame al advance()
    // el estado de salto estará true y por tanto el personaje saltará hasta que status_saltando
    // sea restablecido
    this->status_saltando=true;
}

void personaje::adelante()
{
    // llamar al método heredado para moverse hacia la derecha
    direccion=true;
    this->moverDerecha();
}

void personaje::atras()
{
    // llamar al método heredado para moverse hacia la izquierda
    direccion=false;
    this->moverIzquierda();
}

bala * personaje::disparar()
{
    tmp_disparo = new bala(coordenadaX,coordenadaY,10,10,direccion);
    return  tmp_disparo;

}

void personaje::advance(int phase)
{
    // salto requiere que exista un boleano en true para ejecutarlo. para ello
    // el método salto que está presente en (cuerpo.h) corrobora si el estado del personaje es
    // status_saltando = true

    salto();
}
