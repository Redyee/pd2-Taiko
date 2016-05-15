#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include "btn.h"
#include <QTimer>
#include "drum.h"
#include "beat.h"
#include "gbeat.h"
#include "shoot.h"
#include <QSound>


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    //from start ->game
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //starting page
    void initStartingPage();
    Btn *btn_start;
    void bgChange(); // from start to game
    void init_game();
    drum *drumer;
    void bgRecover();
    QTimer *move_timer;
    beat *beater;
    gbeat *gbeater;
    QTimer *gene_timer;
    int score;
    int btn_w; //width
    int btn_h;
    int beat_x;
    void count();
    QTimer *counting;
    QList<beat * > list;
    QList<gbeat * > glist;
    QList<shoot * > shootlist;
    void keyPressEvent(QKeyEvent *event);
    shoot *shooter;
    float move_speed;
    float gene_speed;
    QSound *sound_shoot;

public slots:
    void geneBeats();
    void moveBeat();
private:
    int gameMode ;
    int start_t = 30;
private slots:
    //for count time
    void decreaseTime();
};

#endif // SCENE_H
