 #include "movimientos.h"

movimientos::movimientos(float limiteInferior_ )
{
    this->limite_inferior=limiteInferior_;
    this->velocidadY= 60 * sin((90*3.1416)/180);
    this->tiempo=0;
    status_saltando=false;
}

bool movimientos::getStatus_saltando() const
{
    return status_saltando;
}

void movimientos::setStatus_saltando(bool value)
{
    status_saltando = value;
}

void movimientos::saltar()
{
    if(status_saltando==true){
        posY=limite_inferior - float(0+velocidadY*tiempo+(0.5*(-9.8*tiempo*tiempo)));
        tiempo=tiempo+0.3;
        qDebug() << "y : "<<posY;
        if(posY>limite_inferior){
            status_saltando=false;
            posY=limite_inferior;
            qDebug() << "status saltando = False ";
            tiempo=0;
        }
    }
}
