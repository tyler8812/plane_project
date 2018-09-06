#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemy();

public slots:
   void down();
   void right_down();
   void right();

};

#endif // ENEMY_H
