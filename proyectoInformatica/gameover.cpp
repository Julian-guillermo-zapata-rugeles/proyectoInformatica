#include "gameover.h"
#include "ui_gameover.h"
#include "cliente.h"


GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_continuar_clicked()
{
    clienteNuevo = new cliente;
    clienteNuevo->show();
    this->close();
}

void GameOver::on_salir_clicked()
{
    qApp->quit();
}
