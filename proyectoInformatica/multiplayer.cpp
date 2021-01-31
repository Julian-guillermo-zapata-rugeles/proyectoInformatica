#include "multiplayer.h"

MultiPlayer::MultiPlayer(QObject *parent) : QObject(parent)
{
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void MultiPlayer::keyPressEvent(QKeyEvent *event)
{
    if(player1 != NULL){
        player1->teclas(event);
    }
    if(player2 != NULL){
        player2->teclas2(event);
    }
}

void MultiPlayer::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
}

personaje *MultiPlayer::getPlayer2() const
{
    return player2;
}

void MultiPlayer::setPlayer2(personaje *value)
{
    player2 = value;
}

personaje *MultiPlayer::getPlayer1() const
{
    return player1;
}

void MultiPlayer::setPlayer1(personaje *value)
{
    player1 = value;
}
