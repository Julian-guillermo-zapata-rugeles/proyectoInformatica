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
    eventos->start(15000);
    connect(ticks,SIGNAL(timeout()),this,SLOT(actualizar()));
    connect(eventos,SIGNAL(timeout()),this,SLOT(generarAsteroides()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar(){
    for(auto &ast : v_asteroides){
        if(ast->destruir()){
            mundo->removeItem(ast);
            mundo->update();
            v_asteroides.erase(std::remove(v_asteroides.begin(),v_asteroides.end(),ast),v_asteroides.end());
            sonido->stop();
            sonido->setMedia(QUrl("qrc:/multimedia/explosion1.mp3"));
            sonido->play();
            //std::cout << "eliminado" <<std::endl;
        }
    }

    //std::cout << "tamaño : " <<v_asteroides.size() << std::endl;
    mundo->advance();
    mundo->update();
}

void MainWindow::generarAsteroides()
{
    srand(time(NULL));
    int aleatorio=1+rand()%1000;
    int a_w = 30+rand()%200;
    v_asteroides.push_back(new asteroides(aleatorio,-1000,a_w,a_w,600));
    mundo->addItem(v_asteroides.last());
    std::cout << "Asteroide generado en X : "<< aleatorio << std::endl;
    /*
    if(eventos->interval()>1000){
        eventos->setInterval(eventos->interval()-100);
    }
    */
    sonido->stop();
    sonido->setMedia(QUrl("qrc:/multimedia/suspenso1.mp3"));
    sonido->play();
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
        proyectiles.push_back(personajePrincipal->disparar());
        mundo->addItem(proyectiles.last());
    }
}

