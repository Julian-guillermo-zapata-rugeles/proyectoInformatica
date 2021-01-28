#include "cliente.h"
#include "ui_cliente.h"
#include <mundoterrestre.h>

cliente::cliente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cliente)
{
    ui->setupUi(this);
    hide_elements(true);
}

cliente::~cliente()
{
    delete ui;
}

void cliente::hide_elements(bool option)
{
    if(option==true){
        ui->info_name->hide();
        ui->info_send->hide();
        ui->info_text->hide();
    }
    else{
        ui->info_name->show();
        ui->info_send->show();
        ui->info_text->show();
    }

}

void cliente::on_pushButton_clicked()
{
    //
    mundoTerrestre *world;
    world = new mundoTerrestre();
    this->close();
    world->iniciarMundo();
}

void cliente::on_pushButton_2_clicked()
{
    hide_elements(false);
}
