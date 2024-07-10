#-------------------------------------------------
#
# Project created by QtCreator 2020-05-29T00:12:03
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyTowerDefence
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    bullet.cpp \
    enemy.cpp \
    enemyhp.cpp \
    objectinteract.cpp \
    player.cpp \
    playerstatus.cpp \
    point.cpp \
    stage.cpp \
    tool.cpp \
    tower.cpp \
    towersign.cpp \
    towerrangecircle.cpp \
    towerintroduction.cpp

HEADERS += \
        mainwindow.h \
    bullet.h \
    config.h \
    enemy.h \
    enemyhp.h \
    objectinteract.h \
    player.h \
    playerstatus.h \
    point.h \
    stage.h \
    tool.h \
    tower.h \
    towersign.h \
    towerrangecircle.h \
    towerintroduction.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
