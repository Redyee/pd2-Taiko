#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T11:51:45
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    btn.cpp \
    drum.cpp \
    beat.cpp \
    gbeat.cpp \
    shoot.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    scene.h \
    btn.h \
    drum.h \
    beat.h \
    gbeat.h \
    shoot.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    pics.qrc
