#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    scene = new Scene ;
    setBackground();
    ui->graphicsView->setScene(scene);
    //rect of scene???
    scene->setSceneRect(0,0,800, 450);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setBackground(){
    QImage bg;
    bg.load(":/pics/blog_140619_00.jpg");
    bg = bg.scaled(bg.width()*2,bg.height()*2);
    cout <<bg.width() <<"  "<<bg.height()*2<<"  "<<endl;
    scene->setBackgroundBrush(bg);
}
