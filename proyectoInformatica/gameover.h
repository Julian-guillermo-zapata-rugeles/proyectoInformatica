#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "cliente.h"
#include <QWidget>

namespace Ui {
class GameOver;
}

class GameOver : public QWidget
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();

private slots:
    void on_continuar_clicked();
    void on_salir_clicked();


private:
    cliente *clienteNuevo;
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
