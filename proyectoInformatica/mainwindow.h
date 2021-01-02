#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "bala.h"
#include <QTimer>
#include <personaje.h>
#include <QVector>
#include <QKeyEvent>
#include "obstaculo.h"
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


private:
    Ui::MainWindow *ui;
    QTimer *tiempo;
    personaje *juan;
    QGraphicsScene *escena;
    QVector <bala *>disparos;
    bala *disparo;
    void keyPressEvent(QKeyEvent *evento) override;
    void crearEscena();
    QSet<Qt::Key> keysPressed;
    QVector<Obstaculo *> plataformas;

private slots:
    void actualizar();
};
#endif // MAINWINDOW_H
