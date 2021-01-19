#include "levelcompletewindow.h"
#include "ui_levelcompletewindow.h"

LevelCompleteWindow::LevelCompleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelCompleteWindow)
{
    ui->setupUi(this);
}

LevelCompleteWindow::~LevelCompleteWindow()
{
    delete ui;
}

void LevelCompleteWindow::on_yes_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void LevelCompleteWindow::on_No_clicked()
{
    qApp->quit();
}
