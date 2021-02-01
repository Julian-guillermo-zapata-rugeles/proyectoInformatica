#ifndef CLIENTE_H
#define CLIENTE_H

#include <QWidget>
#include "gamesave.h"

namespace Ui {
class cliente;
}

class cliente : public QWidget , public GameSave
{
    Q_OBJECT

public:
    explicit cliente(QWidget *parent = nullptr);
    ~cliente();

private:
    void hide_elements(bool option);

    std::string  mode_cliente;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_info_send_clicked();

    void on_multiplayer_clicked();

private:
    Ui::cliente *ui;
};

#endif // CLIENTE_H
