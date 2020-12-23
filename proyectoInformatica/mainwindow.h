#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "bala.h"
#include <QTimer>
#include <personaje.h>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    bala *disparo;
    QTimer *tiempo;
    personaje *juan;
    QVector <bala *> disparos;

    void crearEscena();

private slots:
    void actualizar();
};
#endif // MAINWINDOW_H
