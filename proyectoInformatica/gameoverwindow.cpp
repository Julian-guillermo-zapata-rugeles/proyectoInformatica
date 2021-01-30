#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"

GameOverWindow::GameOverWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);
}

GameOverWindow::~GameOverWindow()
{
    delete ui;
}

void GameOverWindow::on_yes_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void GameOverWindow::on_No_clicked()
{
    qApp->quit();
}
