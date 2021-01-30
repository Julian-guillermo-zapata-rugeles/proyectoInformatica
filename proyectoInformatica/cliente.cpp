#include "cliente.h"
#include "ui_cliente.h"
#include <mundoterrestre.h>
#include <QSplashScreen>
#include <QTime>

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
    hide_elements(false); // muestra la barra
    mode_cliente="wait_for_game";
    ui->info_send->setText("Jugar");
}

void cliente::on_pushButton_2_clicked()
{
    hide_elements(false);
    mode_cliente="wait_for_load";
    ui->info_send->setText("Buscar");
}



void cliente::on_info_send_clicked()
{
    if(mode_cliente=="wait_for_game"){

        QSplashScreen *splash = new QSplashScreen;
        splash->setPixmap(QPixmap(":/multimedia/splash.png"));
        QTimer::singleShot(3000,splash,SLOT(close()));
        this->close();
        splash->show();

        QTime dieTime= QTime::currentTime().addSecs(3);
        while (QTime::currentTime() < dieTime){
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }

        // capturaremos el nombre y haremos comprobaciones
        QString userRead = ui->info_text->toPlainText();
        ui->info_text->clear();
        mundoTerrestre  *mundo;
        mundo = new mundoTerrestre(userRead);
        mundo->iniciarMundo();
    }
}
