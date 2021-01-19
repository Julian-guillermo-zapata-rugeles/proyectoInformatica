#include "menuinicio.h"
#include "ui_menuinicio.h"

MenuInicio::MenuInicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuInicio)
{
    ui->setupUi(this);
    creacionVentana();
}

bool MenuInicio::regUserText()
{
    bool correct = false;
    usernameReg = new QRegularExpression("^([a-z0-9_\\.-]+)@([\\da-z\\.-]+)\\.([a-z\\.]{2,6})$");
    usernamenameMatch = new QRegularExpressionMatch(usernameReg->match(userLine->text()));
    correct = usernamenameMatch->hasMatch();

    if(correct){
        return true;
    }
    else
        return false;
}

MenuInicio::~MenuInicio()
{
    delete ui;
}

void MenuInicio::login()
{
    if(userLine->text().isEmpty()){
         QMessageBox msgBox;
         msgBox.setText("Debes ingresar un nombre de usuario. ");
         msgBox.setWindowTitle("Advertencia");
         msgBox.exec();
         return;
     }
    if(regUserText()== false){
        QMessageBox msgBoxFail;
        msgBoxFail.setText("Esa no es una dirección de correo electrónico válida.   ");
        msgBoxFail.setWindowTitle("Advertencia");
        msgBoxFail.exec();
        return;
    }
     if(passLine->text().isEmpty()){
         QMessageBox msgBox2;
         msgBox2.setText("Debes ingresar una contraseña. ");
         msgBox2.setWindowTitle("Advertencia");
         msgBox2.exec();
         return;
      }

     //Falta agregar la validacion de usuario registrado

     firstWorld = new mundoTerrestre();
     firstWorld->iniciarMundo();
}

void MenuInicio::newUser()
{
    registro = new LoginWindow();
    registro->exec();
}

void MenuInicio::guestLogin()
{
    loginButton->close();
    newUserButton->close();
    passLine->close();
    userLine->close();
    nameUser->close();
    password->close();
    radioButton->close();
    radioText->close();
    guestButton->close();
    quitButton->close();

    firstWorld = new mundoTerrestre();
    firstWorld->iniciarMundo();
}

void MenuInicio::on_radioButton_toggled(bool checked)
{
    if(checked){
        passLine->setEchoMode(QLineEdit::Normal);
    }
    else{
        passLine->setEchoMode(QLineEdit::Password);
    }
}

void MenuInicio::quitProgram()
{
    qApp->quit();
}

void MenuInicio::creacionVentana()
{
    //Creacion y configuracion del boton de inicio de Sesion
    loginButton = new QPushButton();
    loginButton->setText("Iniciar Sesion");
    loginButton->setObjectName(QString("Boton para iniciar sesion"));
    loginButton->setToolTip("haga clic si quieres iniciar");
    loginButton->setGeometry(QRect(540, 500, 100, 32));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(login()));

    //Creacion y configuracion del boton de Inicio se Sesion como invitado
    guestButton = new QPushButton();
    guestButton->setText("Invitado");
    guestButton->setObjectName(QString("Sesion como invitado"));
    guestButton->setToolTip("click para iniciar sin registro");
    guestButton->setGeometry(QRect(540, 535, 100, 32));
    connect(guestButton, SIGNAL(clicked()), this, SLOT(guestLogin()));

    //Creacion y configuracion del boton de Salir del programa
    quitButton = new QPushButton();
    quitButton->setText("Salir");
    quitButton->setObjectName(QString("Boton de Cerrar"));
    quitButton->setToolTip("click para salir");
    quitButton->setGeometry(QRect(642, 535, 100, 32));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitProgram()));

    //Creacion y configuracion del boton de Registro para nuevo usuario
    newUserButton = new QPushButton();
    newUserButton->setText("Nuevo Usuario");
    newUserButton->setObjectName(QString("Boton de registro nuevo"));
    newUserButton->setToolTip("Click para crear nuevo registro");
    newUserButton->setGeometry(QRect(642, 500, 100, 32));
    connect(newUserButton, SIGNAL(clicked()), this, SLOT(newUser()));

    //Linea para ingresar el usuario(Correo electronico)
    userLine = new QLineEdit();
    userLine->setToolTip("Ingresa el correo electronico");
    userLine->setGeometry(QRect(540, 420, 200, 25));

    //Etiqueta del titulo nombre de usuario
    QFont font("Cosmic Blaster", 9, QFont::Bold);
    nameUser = new QLabel();
    nameUser->setFont(font);
    nameUser->setText("USUARIO");
    nameUser->setObjectName(QString("Nombre usuario"));
    nameUser->setGeometry(QRect(430, 420, 100, 25));

    //Linea para ingresar la contraseña
    passLine = new QLineEdit();
    passLine->setEchoMode(QLineEdit::Password);
    passLine->setObjectName(QString("Contraseña"));
    passLine->setToolTip("Ingresa contraseña");
    passLine->setGeometry(QRect(540, 450, 200, 25));

    //Etiqueta del titulo de contraseña
    password = new QLabel();
    password->setFont(font);
    password->setText("CONTRASEÑA");
    password->setObjectName(QString("contraseña"));
    password->setGeometry(QRect(430, 450, 100, 25));

    //Boton para encriptar la contraseña
    radioButton = new QRadioButton();
    radioButton->setObjectName(QString("radioButton"));
    radioButton->setToolTip("Click to show password text");
    radioButton->setGeometry(QRect(760, 450, 100, 25));
    connect(radioButton, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled(bool)));

    //Etiqueta del Boton mostrar contraseña
    radioText = new QLabel();
    radioText->setText("Mostrar contraseña");
    radioText->setToolTip("click para mostrar la contraseña");
    radioText->setGeometry(QRect(780, 450, 100, 25));
}
