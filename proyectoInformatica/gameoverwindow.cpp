#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"

GameOverWindow::GameOverWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);
}

GameOverWindow::~GameOverWindow()
{
    delete ui;
}
