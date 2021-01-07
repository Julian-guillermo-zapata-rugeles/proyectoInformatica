#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mundo = new QGraphicsScene(0,0,1000,600);
    ui->visorGrafico->setScene(mundo);
    personajePrincipal = new personaje(10,580,10,10);
    mundo->addItem(personajePrincipal);
    ticks = new QTimer();
    ticks->start(40);
    eventos = new QTimer();
    eventos->start(10000);
    connect(ticks,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(eventos,SIGNAL(timeout()),this,SLOT(generarAsteroides()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar(){
    mundo->advance();
    mundo->update();
}

void MainWindow::generarAsteroides()
{
    srand(time(NULL));
    int aleatorio=1+rand()%1000;
    int aleatorios_asteroide = 10+rand()%40;
    tmp_asteroide = new asteroides(personajePrincipal->getCoordenadaX(),-10,aleatorios_asteroide,aleatorios_asteroide);
    mundo->addItem(tmp_asteroide);
    v_asteroides.push_back(tmp_asteroide);
    std::cout << "Asteroide generado en X : "<< aleatorio << std::endl;
    /*
    if(eventos->interval()>1000){
        eventos->setInterval(eventos->interval()-100);
    }
    */
}


void MainWindow::keyPressEvent(QKeyEvent *evento){
    if(evento->key()==Qt::Key_W){
        personajePrincipal->saltar();
    }
    if(evento->key()==Qt::Key_A){
        personajePrincipal->atras();
    }
    if(evento->key()==Qt::Key_D){
        personajePrincipal->adelante();
    }
    if(evento->key()==Qt::Key_Space){
        tmp_proyectil = personajePrincipal->disparar();
        mundo->addItem(tmp_proyectil);
        proyectiles.push_back(tmp_proyectil);
    }
}

