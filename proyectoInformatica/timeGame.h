#ifndef TIME_H
#define TIME_H

#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include <QFontDatabase>

class timeGame: public QGraphicsTextItem
{
public:
    timeGame(QGraphicsItem *parent=0);

    void decrease();
    int getTime();

    void setTimeCount(short value);
    void setVidaRestante(short value);
    void setLevelworld(short value);
    void setDisparos(short value);

    short getLevelworld() const;
    short getTimeCount() const;
    short getVidaRestante() const;

    /* Agregé este nuevo método setter
        para poner la información del usuario en pantalla y sepa sobre su partida
        tambien se piensa usar para sacar la información y exportarla a un archivo que  almacenará la información.
        para su posterior uso
    */
    void setUser_name(const QString &value);
    void setImpulsos(short value);

private:
    short int timeCount;
    short int levelworld;
    short int disparos;
    short int vidaRestante;
    QString user_name;
    short int impulsos;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // TIME_H
