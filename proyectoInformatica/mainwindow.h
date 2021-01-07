#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QGraphicsScene>
#include <QTimer>
#include "personaje.h"
#include <QKeyEvent>
#include <QVector>
#include "bala.h"
#include "asteroides.h"
#include <random>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *mundo;
    personaje *personajePrincipal;
    QTimer *ticks;
    QTimer *eventos;
    void keyPressEvent(QKeyEvent *evento) override;

    // vectores de objetos
    QVector <bala *> proyectiles;
    QVector <asteroides *> v_asteroides;
    bala *tmp_proyectil;
    asteroides *tmp_asteroide;

private:
    Ui::MainWindow *ui;

public slots:
    void actualizar();
    void generarAsteroides();
};
#endif // MAINWINDOW_H
