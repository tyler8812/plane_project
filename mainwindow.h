#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QLine>
#include <QKeyEvent>
#include <QProgressBar>

#include "bullet.h"
#include "enemy.h"
#include "boss.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //friend class bullet;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    //int scores;
    boss *bosss;
    //QProgressBar *enemy_progressbar;

public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);
    virtual void appear1_enemy();
    virtual void appear2_enemy();
    virtual void appear3_enemy();


    virtual void boss_bullet();

    virtual void playerhealth();
    virtual void bosshealth();

    virtual void increase();
    virtual void skill();
   // virtual void move();
    //virtual void mousePressEvent(QMouseEvent *e);

private slots:
    void on_skill_button_clicked();
    void up();
    void down();
    void right();
    void left();


private:
    //int score;

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *player;

    QTimer *timer;
    QTimer *timer_for_boss;
    QTimer *timer_move;
    QTimer *enemy1_timer;
    QTimer *enemy2_timer;
    QTimer *enemy3_timer;


    //int rand_x, rand_y;
};

#endif // MAINWINDOW_H














