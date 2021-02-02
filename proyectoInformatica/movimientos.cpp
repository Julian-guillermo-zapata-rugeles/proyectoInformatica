 #include "movimientos.h"

movimientos::movimientos(float limiteInferior_ )
{
    this->limite_inferior=limiteInferior_-15;
    this->velocidadY= 70 * sin((90*3.1416)/180);
    this->tiempo=0;
    this->tmp_sumador=0;
    this->intervaloSuma=0.5;
    status_saltando=true;
    status_gravitatorio=false;
}

bool movimientos::getStatus_saltando() const
{
    return status_saltando;
}

void movimientos::setStatus_saltando(bool value)
{
    status_saltando = value;
}


bool movimientos::getStatus_gravitatorio() const
{
    return status_gravitatorio;
}

void movimientos::setStatus_gravitatorio(bool value)
{
    status_gravitatorio = value;
}

float movimientos::getIntervaloSuma() const
{
    return intervaloSuma;
}

void movimientos::setIntervaloSuma(float value)
{
    intervaloSuma = value;
}


void movimientos::saltar()
{
    if(status_saltando==true){
        posY=limite_inferior - float(0+velocidadY*tiempo+(0.5*(-9.8*tiempo*tiempo)));
        tiempo=tiempo+intervaloSuma;

#ifdef DEBUG_MOVIMIENTOS
        qDebug() << "y : "<<posY;
#endif

        if(posY>limite_inferior){
            status_saltando=false;
            posY=limite_inferior;

#ifdef DEBUG_MOVIMIENTOS
        qDebug() << "status saltando = False ";
#endif
            tiempo=0;
        }
    }
}

void movimientos::gravitar()
{
    if(status_gravitatorio==true){
        posY = limite_inferior-20 + tmp_sumador;
        tmp_sumador = tmp_sumador - 1 ;
    }

    if(status_gravitatorio==false){
        if(posY<limite_inferior-10){

#ifdef DEBUG_MOVIMIENTOS
        qDebug()<<"pos y gravedad :"<< posY << "limite inferior << " << limite_inferior;
#endif
            posY=posY+5;
            tmp_sumador=0;
        }
        else {
            posY=limite_inferior;
        }
    }
}
