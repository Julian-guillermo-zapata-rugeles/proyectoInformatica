#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

//Funcion que se encarga de validar que lo que el usuario ingresa es efectivamente un email
bool LoginWindow::userNameTest()
{
    bool emailAdress = false;
    userReg = new QRegularExpression("^([a-z0-9_\\.-]+)@([\\da-z\\.-]+)\\.([a-z\\.]{2,6})$");
    userMatch = new QRegularExpressionMatch(userReg->match(ui->USERNAME->text()));
    emailAdress = userMatch->hasMatch();

    if(emailAdress){
        return true;
    }
    else
        return false;
}

bool LoginWindow::passwordTest()
{
    bool correctPass = false;
    passReg = new QRegularExpression("^[a-zA-Z0-9_-]{7,20}$");
    passMatch = new QRegularExpressionMatch(passReg->match(ui->PASSWORD->text()));
    correctPass = passMatch->hasMatch();

    if(correctPass){
        return true;
    }
    else
        return false;
}


void LoginWindow::on_ok_clicked()
{
    //Verifica si la linea de usuario quedo en blanco y el usuario no ingreso nada.
    if(ui->USERNAME->text().isEmpty()){
        QMessageBox::warning(this, "Advertencia", "Debe ingresar un nombre de usuario para registrarse");
        return;
    }
    //verifica si el usuario ingresado no coincide con el existente en la base de datos
    if(userNameTest() == false){
        QMessageBox::warning(this, "Advertencia", "Esa no es una dirección de correo electrónico válida");
        return;
    }
    //verifica si la linea de contraseña esta en blanco
    if(ui->PASSWORD->text().isEmpty()){
        QMessageBox::warning(this, "Advertencia", "Debe ingresar una contraseña para registrarse");
        return;
    }
    //verifica si la contraseña ingresada coincide con la existente en la base de datos
    if(passwordTest()== false){
        QMessageBox::warning(this, "Advertencia", "La contraseña puede contener mayúsculas o minúsculas de la A a la Z, 0-9, _ y -. La longitud máxima es 20. La longitud mínima es 7. Vuelva a intentarlo.");
        return;
    }
}

void LoginWindow::on_cancel_clicked()
{
    LoginWindow::reject();
}

void LoginWindow::on_mostrar_clicked(bool checked)
{
    if(checked){
        ui->PASSWORD->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->PASSWORD->setEchoMode(QLineEdit::Password);
    }
}
