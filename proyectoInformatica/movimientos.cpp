 #include "movimientos.h"

movimientos::movimientos(float limiteInferior_ )
{
    this->limite_inferior=limiteInferior_;
    this->velocidadY= 5 * sin((90*3.1416)/180);
    this->tiempo=0;
}

void movimientos::saltar()
{
    if(status_saltando==true){
        posY=float(0+velocidadY*tiempo+(0.5*(-9.8*tiempo*tiempo)));
        tiempo=tiempo+0.05;
        if(posY>limite_inferior){
            status_saltando=false;
            tiempo=0;
        }
    }
}
