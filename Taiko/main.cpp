#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

#include "scene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Scene S;

    S.setBackgroundBrush(Qt::black);

    QDesktopWidget wid;
    //Set window size
    int screenW = 835;
    int screenH = 523;
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH );
//  start in the middle of the window

    w.setWindowTitle("TaikoTest");
    w.setFixedSize(screenW , screenH);
    w.show();
    return a.exec();

}
