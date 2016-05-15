#include"scene.h"
#include <iostream>
using namespace std;
Scene::Scene(){
    gameMode = 0;
    initStartingPage();
}
//https://sites.google.com/site/tree1235123/home/-ji-ben-cao-zuo-fang-fa/yin-fu-zhong-lei
void Scene::initStartingPage(){
    gameMode = 0;
    btn_start = new Btn;
    QPixmap start;
    start.load(":/pics/Start.png");
    start = start.scaled(start.width()*1/8,start.height()*1/8,Qt::KeepAspectRatio);
    btn_w = (start.width())/8 ;
    btn_h = (start.height())/8 ;
    btn_start->setPixmap(start);
    btn_start->setPos(300,340);
    addItem(btn_start);

}

// check if the pos of event in the range?
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(gameMode == 0)
    {
        // Beginning page
        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x() + 160)
        {
            // Now x is in range , judge y
            if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+ 200)
            {
                gameMode = 1;
                bgChange();
            }
        }
    }
    cout << "btn start x: " << btn_start->pos().x()<< " btn start y: " << btn_start->pos().y() << endl;
    cout << "Now event x: " << event->scenePos().x()<< " event y: " << event->scenePos().y() << endl;
}

//need to set pos
void Scene::bgChange(){
    //from start to gameMode
    QImage bg;
    bg.load(":/pics/bg.png");
    bg = bg.scaled(800 ,450 );
    this->setBackgroundBrush(bg);
    this->removeItem(btn_start);

    drumer = new drum;
    QPixmap buff;
    buff.load(":/pics/鼓 red.gif");
    buff = buff.scaled(buff.width(),buff.height(),Qt::KeepAspectRatio);
    drumer->setPixmap(buff);
    drumer->setPos(-2,110);
    this->addItem(drumer);

    init_game();
}

void Scene::init_game(){
    score = 0;
    gene_speed = 500;
    //gene period
    gene_timer = new QTimer(this);
    connect(gene_timer, SIGNAL(timeout()), this, SLOT(geneBeats()));
    gene_timer->start(500);

    //move speed
    move_speed = 10;
    move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(moveBeat()));
    move_timer->start(10);

    //count down
    counting = new QTimer;
    connect(counting, SIGNAL(timeout()), this, SLOT(decreaseTime()));
    counting->start(1000);

}

void Scene::bgRecover(){
    //set bg
    QImage bg;
    bg.load(":/pics/blog_140619_00.jpg");
    bg = bg.scaled(500,500);
    this->setBackgroundBrush(bg);
    //delete drum and timer
    removeItem(drumer);
    delete drumer;
    delete move_timer;
    delete gene_timer;
    delete counting;
    //delete beat
    foreach (beat *i, list) {
        this->removeItem(i);
        list.removeOne(i);
    }
    foreach (gbeat *i, glist) {
        this->removeItem(i);
        glist.removeOne(i);
    }

    initStartingPage();
}

// need to set pos_x
void Scene::geneBeats(){
    qsrand( qrand() );
    beat_x = 800;
    int rand = qrand();
    if (rand%3 == 0){
        beater = new beat;
        QPixmap buff;
        buff.load(":/pics/警察叔叔.jpg");
        buff = buff.scaled(buff.width()/5,buff.height()/5,Qt::KeepAspectRatio);
        beater->setPixmap(buff);
        beater->setPos(beat_x,113);
        this->addItem(beater);
        list.push_front(beater);
    }

    else if (rand%3 ==1){
        gbeater = new gbeat;
        QPixmap gbuff;
        gbuff.load(":/pics/C:/Users/johnson_Dall/Desktop/鼓 blue.png");
        gbuff = gbuff.scaled(gbuff.width(),gbuff.height(),Qt::KeepAspectRatio);
        gbeater->setPixmap(gbuff);
        gbeater->setPos(beat_x,113);
        this->addItem(gbeater);
        glist.push_front(gbeater);
    }
    cout << rand <<endl;
}
//:/pics/bg.png
void Scene::moveBeat(){
    foreach(beat *i ,list ){
        i->move();
    }
    foreach(gbeat *i ,glist ){
        i->move();
    }
    foreach(shoot *i ,shootlist){
        i->move();
    }


/*    QList<QGraphicsItem *> destroy = this-> collidingItems( shooter );
    if ( !destroy.empty() ){
        beat *des = dynamic_cast<beat *>(destroy[0]);
        this->removeItem(des);
        list.removeOne(des);
        delete des;
        ++score;
       }
    if ( !destroy.empty() ){
        gbeat *gdes = dynamic_cast<gbeat *>(destroy[0]);
        this->removeItem(gdes);
        glist.removeOne(gdes);
        delete gdes;
        ++score;
       }*/
}

void Scene::keyPressEvent(QKeyEvent *event){
    if (gameMode == 1){
        QList<QGraphicsItem *> remove_list = this-> collidingItems( drumer );
        if ( !remove_list.empty() ){
            beat *test = dynamic_cast<beat *>(remove_list[0]);
            if(event->key() == Qt::Key_S ){
            this->removeItem(test);
            list.removeOne(test);
            delete test;
            ++score;
            }
        }
        QList<QGraphicsItem *> remove_glist = this-> collidingItems( drumer );
        if ( !remove_glist.empty() ){
            gbeat *gtest = dynamic_cast<gbeat *>(remove_glist[0]);
            if(event->key() == Qt::Key_F ){
            this->removeItem(gtest);
            glist.removeOne(gtest);
            delete gtest;
            ++score;
            }
        }
        // speed up gene_speed
        if( event->key() == Qt::Key_F1 ){
            if (gene_speed > 40){
            gene_speed = gene_speed - 40;
            gene_timer->start( gene_speed );
            }
        }
        // speed down gene_speed
        if( event->key() == Qt::Key_F2 ){
            gene_speed = gene_speed + 80;
            gene_timer->start( gene_speed );
        }
        //speed up moving
        if( event->key() == Qt::Key_F3 ){
            if( move_speed > 0.4 ){
            move_speed = move_speed - 0.4;
            move_timer->start( move_speed );
            }
//            cout << "F3 " <<"move_speed = " <<move_speed<<endl;            
        }
        if( event->key() == Qt::Key_F4 ){
            move_speed = move_speed + 0.8;
            move_timer->start( move_speed );
//            cout << "F4 " <<"move_speed = " <<move_speed<<endl;
        }

        //shoot  pig
        if( event->key() == Qt::Key_G ){
            shooter = new shoot;
            QPixmap buff;
            buff.load(":/pics/野豬騎士.png");
            buff = buff.scaled(buff.width()/5,buff.height()/5,Qt::KeepAspectRatio);
            shooter->setPixmap(buff);
            shooter->setPos(0,0);
            this->addItem(shooter);
            shootlist.push_front(shooter);
            sound_shoot = new QSound(":/music/C:/Users/johnson_Dall/Desktop/野豬騎士我要當鈴聲用的哈哈.mp3");
            sound_shoot->play();
        }


    }
}



void Scene::decreaseTime(){
    start_t = start_t - 1;
    cout<<"start_t = "<<start_t<<endl;
    if (start_t == 0){
        disconnect(move_timer, SIGNAL(timeout()), this, SLOT(moveBeat()));
        disconnect(gene_timer, SIGNAL(timeout()), this, SLOT(geneBeats()));
        disconnect(counting, SIGNAL(timeout()), this, SLOT(decreaseTime()));
        bgRecover();

    }
//    cout<<score<<endl;
}

