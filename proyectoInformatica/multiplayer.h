#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QDebug>
#include <QObject>
#include <QGraphicsRectItem>
#include <personaje.h>

class MultiPlayer : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit MultiPlayer(QObject *parent = nullptr);

    // QGraphicsItem interface
    personaje *getPlayer1() const;
    void setPlayer1(personaje *value);

    personaje *getPlayer2() const;
    void setPlayer2(personaje *value);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    personaje *player1;
    personaje *player2;

};

#endif // MULTIPLAYER_H
