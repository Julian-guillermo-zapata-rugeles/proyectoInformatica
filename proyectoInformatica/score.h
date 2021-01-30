#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFontDatabase>
#include <QFont>

class Score: public QGraphicsTextItem
{

public:
    Score(QGraphicsItem * parent=0);
    int getScore();
    void increase();

    void setScore(int value);

private:
    int score;
};

#endif // SCORE_H
