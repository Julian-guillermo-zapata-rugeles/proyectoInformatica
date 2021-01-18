#include "lunacreciente.h"

lunaCreciente::lunaCreciente()
{
    this->setPixmap(QPixmap(":/multimedia/pixmap_asteroide.png"));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverAsteroide()));
    timer->start(5);
}
