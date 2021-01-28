#include "cliente.h"
#include "ui_cliente.h"
#include <mundoterrestre.h>

cliente::cliente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cliente)
{
    ui->setupUi(this);
}

cliente::~cliente()
{
    delete ui;
}

void cliente::on_pushButton_clicked()
{
    //
    mundoTerrestre *world;
    world = new mundoTerrestre();
    this->close();
    world->iniciarMundo();
}
