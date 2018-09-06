#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
int up1 = 0;
int down1 = 0;
int left1 = 0;
int right1 = 0;

int scores;
int boss_health;
int player_health;
int skills;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 601, 601)),
    timer(new QTimer),
    timer_for_boss(new QTimer),

    timer_move(new QTimer),
    enemy1_timer(new QTimer),
    enemy2_timer(new QTimer),
    enemy3_timer(new QTimer)

{

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    //scene->setBackgroundBrush(QImage(":/res/background.jpeg"));
    player = new QGraphicsPixmapItem(QPixmap(":/res/jet.svg"));
    scene->addItem(player);
    player->setPos(120, 500);
    player->setScale(1.2);
    timer->start(10);
    timer_for_boss->start(100);
    scores = 0;
    player_health=100;
    boss_health=100;
    skills = 3;
    ui->label->setText(QString("Score: ")+ QString::number(scores));
    ui->label->setStyleSheet("color:blue");
    ui->label->setFont(QFont("times",16));


    timer_move->start(30);


    bosss = new boss;
    bosss->setPixmap(QPixmap(":/res/devil.svg").scaled(130, 130));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(bosss));
   // bosss->setPos(80,150);


    bosss->connect(timer, SIGNAL(timeout()), bosss, SLOT(i_can_fly()));


    //enemy_progressbar = new QProgressBar(this);
   // enemy_progressbar->setGeometry();


    enemy1_timer->start(1500);//interval for enemies1.
    connect(enemy1_timer, SIGNAL(timeout()), this, SLOT(appear1_enemy()));
    enemy2_timer->start(2000);//interval for enemies2.
    connect(enemy2_timer, SIGNAL(timeout()), this, SLOT(appear2_enemy()));
    enemy3_timer->start(1000);//interval for enemies3.
    connect(enemy3_timer, SIGNAL(timeout()), this, SLOT(appear3_enemy()));
   // connect(timer_move,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer_for_boss,SIGNAL(timeout()),this,SLOT(boss_bullet()));
    connect(timer,SIGNAL(timeout()),this,SLOT(increase()));
    connect(timer,SIGNAL(timeout()),this,SLOT(playerhealth()));
    connect(timer,SIGNAL(timeout()),this,SLOT(bosshealth()));
    connect(timer,SIGNAL(timeout()),this,SLOT(skill()));
    connect(timer_move,SIGNAL(timeout()),this,SLOT(up()));

    connect(timer_move,SIGNAL(timeout()),this,SLOT(down()));

    connect(timer_move,SIGNAL(timeout()),this,SLOT(left()));

    connect(timer_move,SIGNAL(timeout()),this,SLOT(right()));








}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

    switch(e->key()) {
    case Qt::Key_Up:
    //case Qt::Key_W:
    //    up = 1;
        if(player->y()>0 )
        up1 = 1;
        //player->setPos(player->x(), player->y() - 10);

        break;
    case Qt::Key_Down:
    //case Qt::Key_S:
    //    down = 1;
        if(player->y()<550)
        //player->setPos(player->x(), player->y() + 10);
            down1 =1;
        break;
    case Qt::Key_Left:
    //case Qt::Key_A:
       // left1 = 1;
        if(player->x()>-50)
       // player->setPos(player->x() - 10, player->y());
            left1 =1;
        break;
    case Qt::Key_Right:
    //case Qt::Key_D:
       // right1 = 1;
        if(player->x()<400)
       // player->setPos(player->x() + 10, player->y());
            right1 = 1;
        break;

    case Qt::Key_Space:
        bullet *a = new bullet; //three different bullets
        bullet *b = new bullet;
        bullet *c = new bullet;
        if(qrand() % 2 == 0) {
            a->setPixmap(QPixmap(":/res/bullet_left.png").scaled(50, 50));
            b->setPixmap(QPixmap(":/res/bullet_front.svg").scaled(50, 50));
            c->setPixmap(QPixmap(":/res/bullet_right.svg").scaled(50, 50));

        }
        else {
            b->setPixmap(QPixmap(":/res/bullet_front.svg").scaled(50, 50));
        }
        b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2+17, player->y() - b->pixmap().height()+28);
        a->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2+19, player->y() - b->pixmap().height()+28);
        c->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2+15,  player->y() - b->pixmap().height()+28);
        a->setScale(0.5);
        b->setScale(0.5);
        c->setScale(0.5);
        b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
        a->connect(timer, SIGNAL(timeout()), a, SLOT(left_fly()));
        c->connect(timer, SIGNAL(timeout()), c, SLOT(right_fly()));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(a));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(c));

    }


}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Up){up1 = 0; };
    if(e->key() == Qt::Key_Down){down1 = 0; };
    if(e->key() == Qt::Key_Left){left1 = 0; };
    if(e->key() == Qt::Key_Right){right1 = 0; };

}


void MainWindow::appear1_enemy()
{

    enemy *e = new enemy;// 1 enemy position

    e->setPixmap(QPixmap(":/res/dragon.svg").scaled(50, 50));
    e->setScale(0.5);
    int rand_x = qrand() % 400 -50;
    int rand_y = qrand() % 100;

    e->setPos(rand_x,rand_y);
    e->connect(timer, SIGNAL(timeout()), e, SLOT(down()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(e));

}
void MainWindow::appear2_enemy()
{

    enemy *e2 = new enemy;
// 2 enemy position
    e2->setPixmap(QPixmap(":/res/fish.svg").scaled(50, 50));
    e2->setScale(0.5);
    int rand_x = qrand() % 200 -50;
    int rand_y = qrand() % 500+300;

    e2->setPos(rand_x,rand_y);
    e2->connect(timer, SIGNAL(timeout()), e2, SLOT(right()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(e2));

}
void MainWindow::appear3_enemy()
{

    enemy *e3 = new enemy;// 3 enemy position

    e3->setPixmap(QPixmap(":/res/monster.svg").scaled(50, 50));
    e3->setScale(0.5);
    int rand_x = qrand() % 500 -50;
    int rand_y = qrand() % 600;

    e3->setPos(rand_x,rand_y);
    e3->connect(timer, SIGNAL(timeout()), e3, SLOT(right_down()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(e3));

}



void MainWindow::boss_bullet()
{
    if(boss_health > 0){
    boss * bbullet = new boss; //boss's bullet
    bbullet->setPixmap(QPixmap(":/res/fire.svg").scaled(50, 50));
    bbullet->setPos(bosss->x() + bosss->pixmap().width() / 2 - bbullet->pixmap().width() / 2 +12,bosss->y() - bbullet->pixmap().height()+140);
    bbullet->setScale(0.5);
    bbullet->connect(timer, SIGNAL(timeout()), bbullet, SLOT(attack()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(bbullet));
    }
}

void MainWindow::playerhealth()
{
    ui->player_bar->setValue(player_health);



    if(player_health == 0){
        disconnect(timer,SIGNAL(timeout()),this,SLOT(playerhealth()));
        scene->removeItem(player);
        ui->finish->setText("You lose~~ QQ");
        ui->finish->setStyleSheet("color:red");
    }
}

void MainWindow::bosshealth()
{
    if(boss_health >= 60 && boss_health < 100){
    ui->boss_progressbar->setValue(boss_health);
    ui->boss_progressbar->setStyleSheet("QProgressBar{border:2px solid grey; border-radius:5px; text-align:center;}"
                                        "QProgressBar::chunk{background-color:green; width:20px;}");
    ui->boss_progressbar->setGeometry(bosss->x()+30,bosss->y()+10,300,10);
    }
    if(boss_health >= 20 && boss_health < 60){
    ui->boss_progressbar->setValue(boss_health);
    ui->boss_progressbar->setStyleSheet("QProgressBar{border:2px solid grey; border-radius:5px; text-align:center;}"
                                        "QProgressBar::chunk{background-color:orange; width:20px;}");
    ui->boss_progressbar->setGeometry(bosss->x()+30,bosss->y()+10,300,10);
    }
    if(boss_health > 0 && boss_health < 20){
    ui->boss_progressbar->setValue(boss_health);
    ui->boss_progressbar->setStyleSheet("QProgressBar{border:2px solid grey; border-radius:5px; text-align:center;}"
                                        "QProgressBar::chunk{background-color:red; width:20px;}");
    ui->boss_progressbar->setGeometry(bosss->x()+30,bosss->y()+10,300,10);
    }

    if(boss_health <= 0){

      scores = scores + 1000;
      disconnect(timer,SIGNAL(timeout()),this,SLOT(bosshealth()));
      scene->removeItem(bosss);
      ui->finish->setText("You win!!!");
      ui->finish->setStyleSheet("color:red");
      ui->boss_progressbar->hide();

    }

}

void MainWindow::increase()
{
    if(boss_health != 0){

        ui->label->setText(QString("Score: ")+ QString::number(scores));
    }
    if(boss_health == 0){

        ui->label->setText(QString("Score: XXX"));
    }


}

void MainWindow::skill()
{
    ui->skill_label->setText(QString("Times: ")+QString::number(skills));

}

void MainWindow::on_skill_button_clicked()
{

    if(skills>0){
    bullet *w1 = new bullet;
    bullet *w2 = new bullet;
    bullet *w3= new bullet;
    bullet *w4 = new bullet;
    bullet *w5 = new bullet;
    bullet *w6 = new bullet;
    bullet *w7 = new bullet;
    bullet *w8 = new bullet;
    bullet *w9 = new bullet;
    bullet *w10 = new bullet;

    w1->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w1->setPos(-50,580);
    w1->connect(timer, SIGNAL(timeout()), w1, SLOT(wave_fly()));
    w2->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w2->setPos(0,580);
    w2->connect(timer, SIGNAL(timeout()), w2, SLOT(wave_fly()));
    w3->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w3->setPos(50,580);
    w3->connect(timer, SIGNAL(timeout()), w3, SLOT(wave_fly()));
    w4->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w4->setPos(100,580);
    w4->connect(timer, SIGNAL(timeout()), w4, SLOT(wave_fly()));
    w5->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w5->setPos(150,580);
    w5->connect(timer, SIGNAL(timeout()), w5, SLOT(wave_fly()));
    w6->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w6->setPos(200,580);
    w6->connect(timer, SIGNAL(timeout()), w6, SLOT(wave_fly()));
    w7->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w7->setPos(250,580);
    w7->connect(timer, SIGNAL(timeout()), w7, SLOT(wave_fly()));
    w8->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w8->setPos(300,580);
    w8->connect(timer, SIGNAL(timeout()), w8, SLOT(wave_fly()));
    w9->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w9->setPos(350,580);
    w9->connect(timer, SIGNAL(timeout()), w9, SLOT(wave_fly()));
    w10->setPixmap(QPixmap(":/res/wave.svg").scaled(50, 50));
    w10->setPos(400,580);
    w10->connect(timer, SIGNAL(timeout()), w10, SLOT(wave_fly()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w1));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w2));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w3));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w4));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w5));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w6));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w7));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w8));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w9));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(w10));



    skills--;
    }
}

void MainWindow::up()
{
    if(up1==1 && player->y()>0){

        player->setPos(player->x(), player->y() - 5);
    }
}
void MainWindow::down()
{
    if(down1==1 && player->y()<550){

        player->setPos(player->x(), player->y() + 5);
    }
}
void MainWindow::right()
{
    if(right1==1 && player->x()<400){

        player->setPos(player->x()+5, player->y() );
    }


}
void MainWindow::left()
{
    if(left1==1 && player->x()>-50){

        player->setPos(player->x()-5, player->y() );
    }
}



//void MainWindow::score1()  //score appear
//{
//    score = 0;
//    ui->label->setText(QString("Score: ")+ QString::number(score));
//    ui->label->setStyleSheet("color:blue");
//    ui->label->setFont(QFont("times",16));


//}




/*
void MainWindow::move()
{
    if (up == 1){
        if(left == 1)
            if(player->)
            player->setPos(player->x(), player->y() - 10);

        else{
            if(player->y()>0)
                player->setPos(player->x(), player->y() - 10);
      }
    }
    if (down == 1){
        if(player->y()<700)
            player->setPos(player->x(), player->y() + 10);

    }
    if (right1 == 1){
        if(player->x()<1050)
            player->setPos(player->x()+10, player->y() );

    }
    if (left1 == 1){
        if(player->x()>0)
            player->setPos(player->x()-10, player->y());

    }
    up = 0;
    down =0;
    right1 =0;
    left1 =0;
}



*/
















/*void MainWindow::mousePressEvent(QMouseEvent *e)
{
    bullet *b = new bullet;

    if(qrand() % 2 == 0) {
       b->setPixmap(QPixmap(":/res/black_bullet.png").scaled(50, 50));
    }
    else {
       b->setPixmap(QPixmap(":/res/red_bullet.png").scaled(50, 50));
    }
    b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2, player->y() - b->pixmap().height());
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
}
*/





































