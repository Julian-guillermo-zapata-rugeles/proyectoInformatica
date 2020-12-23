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

void MainWindow::crearEscena()
{
    escena = new QGraphicsScene(0,0,2000,1280);
    ui->visorGrafico->setScene(escena);
    disparo = new bala(50,300,180,50,20,20);
    escena->addItem(disparo);
    tiempo = new QTimer();
    tiempo->start(30);
    connect(tiempo,SIGNAL(timeout()),this,SLOT(actualizar()));
}

void MainWindow::actualizar()
{
    disparo->moverParabolicamente();
    escena->advance();
    escena->update();
    disparo->setFocus();
}

