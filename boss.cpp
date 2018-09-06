#include "boss.h"

extern int player_health;
extern int boss_health;
extern int scores;


boss::boss()
{

}

void boss::i_can_fly()
{
    setPos(x()+qrand()% 5-2.3, y() + qrand()% 5-2.3);
    if(y() > 600 || x()>400 || y()<0 || x()<0) {

     setPos(qrand()%300 ,qrand()%300);

    }
//    if(boss_health == 0){
//        scores = scores + 2000;
//      //  scene()->removeItem(this);

//    }
 }

//    QList<QGraphicsItem *> collide = collidingItems();
//    for(int i=0, n=collide.size();i<n;i++){

//        if(typeid(*(collide[i])) == typeid(QGraphicsPixmapItem)){

//            player_health = player_health-10;

//            return;
//        }
//    }




void boss::attack()
{
     // collide enemy
    QList<QGraphicsItem *> collide = collidingItems();// change type to QGraphicsItem *
    // collidingItems(): Items that bullet collide
    for(int i=0, n=collide.size();i<n;i++){

        if(typeid(*(collide[i])) == typeid(QGraphicsPixmapItem)){

            player_health = player_health-5;
            scene()->removeItem(this);

            delete this;
            return;
        }
        if(typeid(*(collide[i])) ==  typeid(bullet)){
//            if(boss_health == 0){
//              scene()->removeItem(this);
//              delete this;
//              return;
//            }

            scene()->removeItem(this);

            delete this;
            return;
        }

}

    setPos(x(), y() + 2.5);
    if(y() > 610) {
        this->scene()->removeItem(this);
        delete this;
    }
}

