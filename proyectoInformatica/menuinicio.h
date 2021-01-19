#ifndef MENUINICIO_H
#define MENUINICIO_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QGraphicsScene>
#include <QLabel>
#include "mundoterrestre.h"
#include "loginwindow.h"

class mundoTerrestre;
class LoginWindow;

namespace Ui {
class MenuInicio;
}

class MenuInicio : public QWidget
{
    Q_OBJECT

public:

    explicit MenuInicio(QWidget *parent = nullptr);
    bool regUserText();

    ~MenuInicio();

private slots:

    void login();
    void newUser();
    void guestLogin();
    void on_radioButton_toggled(bool checked);
    void quitProgram();

private:

    Ui::MenuInicio *ui;
    
    mundoTerrestre *firstWorld;
    LoginWindow *registro;

    short int selection = 0;
    const short int width = 1280;
    const short int height = 720;

    QGraphicsTextItem *start;
    QGraphicsTextItem *quit;

    QPushButton *loginButton;
    QPushButton *newUserButton;
    QPushButton *guestButton;
    QPushButton *quitButton;

    QLineEdit *userLine;
    QLineEdit *passLine;
    QLabel *nameUser;
    QLabel *radioText;
    QLabel *password;
    QRadioButton *radioButton;

    QRegularExpression *usernameReg;
    QRegularExpressionMatch *usernamenameMatch;
    QRegularExpression *passwordReg;
    QRegularExpressionMatch *passwordMatch;

    void creacionVentana();
};

#endif // MENUINICIO_H
