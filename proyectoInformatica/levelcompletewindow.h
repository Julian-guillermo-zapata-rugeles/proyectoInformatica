#ifndef LEVELCOMPLETEWINDOW_H
#define LEVELCOMPLETEWINDOW_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class LevelCompleteWindow;
}

class LevelCompleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LevelCompleteWindow(QWidget *parent = 0);
    ~LevelCompleteWindow();

private slots:
    void on_yes_clicked();
    void on_No_clicked();

private:
    Ui::LevelCompleteWindow *ui;
};

#endif // LEVELCOMPLETEWINDOW_H
