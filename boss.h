#ifndef BOSS_H
#define BOSS_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include "bullet.h"
#include "enemy.h"



class boss : public QObject, public QGraphicsPixmapItem
{
       Q_OBJECT
public:

    boss();

public slots:
    void i_can_fly();
    void attack();




};

#endif // BOSS_H
