#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "enemy.h"
#include "boss.h"





class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    bullet();


public slots:
    virtual void fly();
    void right_fly();
    void left_fly();
    void wave_fly();

};

#endif // BULLET_H
