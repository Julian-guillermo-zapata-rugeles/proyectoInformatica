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
    escena = new QGraphicsScene(0,0,1000,500);
    ui->visorGrafico->setScene(escena);
    //disparo = new bala(50,300,180,50,20,20);
    juan = new personaje(10,100,90,8,20,20);
    //juan->setTransformOriginPoint(juan->boundingRect().center());
    escena->addItem(juan);
    //escena->addItem(disparo);
    tiempo = new QTimer();
    tiempo->start(30);
    connect(tiempo,SIGNAL(timeout()),this,SLOT(actualizar()));

    //creacion de plataformas
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

