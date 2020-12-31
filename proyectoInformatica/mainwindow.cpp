#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    crearEscena();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearPlataformas()
{
    srand(time(0));
    short int x = 0, y = 0, a = 20, h=30;
    x = 200;
    y = 650;
    for(short int i=0 ; i<5 ; i++){
        plataformas.push_back(new Obstaculo(x,y,a,h));
        x = x+50;
        y = y-15;
    }

    for(auto &item: plataformas){
        escena->addItem(item);
    }
}



void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if(evento->key()==Qt::Key_W){
        juan->setStatus_saltando(true);
            }
    if(evento->key()==Qt::Key_A){
        juan->moverIzquierda();
            }
    if(evento->key()==Qt::Key_D){
        juan->moverDerecha();
            }
    if(evento->key()==Qt::Key_Space){
        disparo = juan->crearDisparo();
        escena->addItem(disparo);
        disparos.push_back(disparo);
           }

}

void MainWindow::crearEscena()
{
    escena = new QGraphicsScene(0,0,1000,800);
    //ui->visorGrafico->resize(escena->width(),escena->height());
    ui->visorGrafico->setScene(escena);
    //disparo = new bala(50,300,180,50,20,20);
    juan = new personaje(0,500,90,8,20,20);
    juan->setTransformOriginPoint(juan->boundingRect().center());
    escena->addItem(juan);
    //escena->addItem(disparo);
    tiempo = new QTimer();
    tiempo->start(30);
    connect(tiempo,SIGNAL(timeout()),this,SLOT(actualizar()));

    //creacion de plataformas
    crearPlataformas();
}



void MainWindow::actualizar()
{
    for(auto &proyectiles : disparos){
        proyectiles->moverRectilineamente();
    }
    escena->advance();
    escena->update();
    juan->actualizar();
}

