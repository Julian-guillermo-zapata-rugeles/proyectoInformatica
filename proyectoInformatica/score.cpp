#include "score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;

    //dibujar texto
    int id = QFontDatabase::addApplicationFont(":/multimedia/Cosmic Blaster.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Cosmic Blaster",20));
}

void Score::increase()
{
    score ++;
    setPlainText(QString("Puntaje: ") + QString::number(score));
}

void Score::setScore(int value)
{
    score = value;
    increase();
}

int Score::getScore()
{
    return score;
}
