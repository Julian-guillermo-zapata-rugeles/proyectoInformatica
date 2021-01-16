#include "score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    life = 20;
    balas = 5;

    //dibujar texto
    int id = QFontDatabase::addApplicationFont(":/multimedia/Cosmic Blaster.ttf");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Puntaje",25));
}

void Score::increase()
{
    score ++;
    setPlainText(QString("") + QString::number(score*2));
}

int Score::getScore()
{
    return score;
}
