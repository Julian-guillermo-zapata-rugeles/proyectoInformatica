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
    switch(evento->key())
    {
    case Qt::Key_Left:
        break;

    case Qt::Key_Right:
        break;

    case Qt::Key_Down:
        break;

    case Qt::Key_W:
        juan->setStatus_saltando(true);
        break;

    case Qt::Key_Space:
        disparo = juan->crearDisparo();
        escena->addItem(disparo);
        disparos.push_back(disparo);
        break;

    default:
        break;
    }
}

void MainWindow::crearEscena()
{
    escena = new QGraphicsScene(0,0,2000,700);
    ui->visorGrafico->resize(escena->width(),escena->height());
    ui->visorGrafico->setScene(escena);
    //disparo = new bala(50,300,180,50,20,20);
    juan = new personaje(50,100,90,8,20,20);
    juan->setTransformOriginPoint(juan->boundingRect().center());
    escena->addItem(juan);
    //escena->addItem(disparo);
    tiempo = new QTimer();
    tiempo->start(30);
    connect(tiempo,SIGNAL(timeout()),this,SLOT(actualizar()));
}

void MainWindow::actualizar()
{
    /*
    disparo = juan->crearDisparo();
    escena->addItem(disparo);
    disparos.push_back(disparo);
    */


    for(auto &it : disparos){
        it->moverRectilineamente();
    }
    escena->advance();
    escena->update();
    juan->actualizar();
}

