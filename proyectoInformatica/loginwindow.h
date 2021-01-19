#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    bool userNameTest();
    bool passwordTest();

private slots:
    void on_ok_clicked();
    void on_cancel_clicked();
    void on_mostrar_clicked(bool checked);

private:
    Ui::LoginWindow *ui;
    QRegularExpression *userReg;
    QRegularExpressionMatch *userMatch;
    QRegularExpression *passReg;
    QRegularExpressionMatch *passMatch;
};

#endif // LOGINWINDOW_H
