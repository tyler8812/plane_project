#include "bullet.h"
#include <QList>


extern int scores;
extern int boss_health;
bullet::bullet()
{

}

void bullet::fly()
{
    // collide enemy
    QList<QGraphicsItem *> collide = collidingItems();// change type to QGraphicsItem *
    // collidingItems(): Items that bullet collide
    for(int i=0, n=collide.size();i<n;i++){

        if(typeid(*(collide[i])) == typeid(enemy)){
            scores ++; //increase score 1
            scene()->removeItem(collide[i]);
            scene()->removeItem(this);
            delete collide[i];
            delete this;
            return;
        }

        if(typeid(*(collide[i])) == typeid(boss)){
           // mainwindow->s->increase();
           // scene()->removeItem(collide[i]);
          scores = scores+2;
          boss_health = boss_health-5;
//          if(boss_health == 0){
//            scores = scores + 5000;
//            //scene()->removeItem(collide[i]);
//          }
            scene()->removeItem(this);

            delete this;
            return;
        }
    }

    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::right_fly()
{
    // collide enemy
    QList<QGraphicsItem *> collide = collidingItems();
//    setPos(x() + collide[qrand()%5]->x()/3, y() - collide[qrand()%5]->y()/3);
//    if(y() < 0 || x()> 400) {
//        this->scene()->removeItem(this);
//        delete this;
//    }


    for(int i=0, n=collide.size();i<n;i++){

        if(typeid(*(collide[i])) == typeid(enemy)){

            scores = scores +2; //increase score 2
            scene()->removeItem(collide[i]);
            scene()->removeItem(this);
            delete collide[i];
            delete this;
            return;
        }
        if(typeid(*(collide[i])) == typeid(boss)){
            scores = scores+2;
            boss_health = boss_health-5;
            scene()->removeItem(this);
          //  delete collide[i];
            delete this;
            return;
        }

    }
    setPos(x() + 3, y() - 3);
    if(y() < 0 || x()> 400) {
        this->scene()->removeItem(this);
        delete this;
    }

}

void bullet::left_fly()
{
    // collide enemy
    QList<QGraphicsItem *> collide = collidingItems();
    for(int i=0, n=collide.size();i<n;i++){

        if(typeid(*(collide[i])) == typeid(enemy)){
            scores = scores +2; //increase score 2
            scene()->removeItem(collide[i]);
            scene()->removeItem(this);
            delete collide[i];
            delete this;
            return;
        }
        if(typeid(*(collide[i])) == typeid(boss)){
            scores = scores+2;
            boss_health = boss_health-5;
            scene()->removeItem(this);
          //  delete collide[i];
            delete this;
            return;
        }
    }
    setPos(x() - 3, y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }

}

void bullet::wave_fly()
{
    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
    QList<QGraphicsItem *> collide = collidingItems();
    for(int i=0, n=collide.size();i<n;i++){

        if(typeid(*(collide[i])) == typeid(enemy)){
            scene()->removeItem(collide[i]);
            delete collide[i];
        }

    }
}

