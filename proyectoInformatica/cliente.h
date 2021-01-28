#ifndef CLIENTE_H
#define CLIENTE_H

#include <QWidget>

namespace Ui {
class cliente;
}

class cliente : public QWidget
{
    Q_OBJECT

public:
    explicit cliente(QWidget *parent = nullptr);
    ~cliente();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cliente *ui;
};

#endif // CLIENTE_H
