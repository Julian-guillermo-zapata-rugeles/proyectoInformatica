#include "bonuslife.h"

BonusLife::BonusLife(qreal x, qreal y): BonusRocket(x,y)
{
    this->setPixmap(QPixmap(":/multimedia/ExtraLife.png"));
    setScale(1);
}
