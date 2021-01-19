#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QWidget>

namespace Ui {
class GameOverWindow;
}

class GameOverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent = nullptr);
    ~GameOverWindow();

private:
    Ui::GameOverWindow *ui;
};

#endif // GAMEOVERWINDOW_H
