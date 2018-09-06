#include "enemy.h"

extern int player_health;
extern int skill;
enemy::enemy()
{

}

void enemy::down()
{

    QList<QGraphicsItem *> collide = collidingItems();// change type to QGraphicsItem *
    // collidingItems(): Items that enemy collide
    for(int i=0, n=collide.size();i<n;i++){

        if(typeid(*(collide[i])) == typeid(QGraphicsPixmapItem)){
            player_health = player_health-5;
           // scene()->removeItem(collide[i]);
            scene()->removeItem(this);
           // delete collide[i];
            delete this;
            return;
        }

    }
    setPos(x(), y() + 1);
    if(y() > 600) {
        setPos(x(),0);
        //this->scene()->removeItem(this);
        //delete this;
    }
}

void enemy::right_down()
{
    QList<QGraphicsItem *> collide = collidingItems();// change type to QGraphicsItem *
    // collidingItems(): Items that enemy collide
    for(int i=0, n=collide.size();i<n;i++){

        if(typeid(*(collide[i])) == typeid(QGraphicsPixmapItem)){
            player_health = player_health-5;
           // scene()->removeItem(collide[i]);
            scene()->removeItem(this);
           // delete collide[i];
            delete this;
            return;
        }

    }
    setPos(x()+1, y() + 1);
    if(y() > 600 || x()>400) {

        this->scene()->removeItem(this);
        delete this;
    }
}

void enemy::right()
{
    QList<QGraphicsItem *> collide = collidingItems();// change type to QGraphicsItem *
    // collidingItems(): Items that enemy collide
    for(int i=0, n=collide.size();i<n;i++){

        if(typeid(*(collide[i])) == typeid(QGraphicsPixmapItem)){
            player_health = player_health-5;
           // scene()->removeItem(collide[i]);
            scene()->removeItem(this);
           // delete collide[i];
            delete this;
            return;
        }

    }
    setPos(x()+1, y());
    if(x() > 400) {
        setPos(0,y());
        //this->scene()->removeItem(this);
        //delete this;
    }
}

