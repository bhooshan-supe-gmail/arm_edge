#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T11:53:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robotic-Arm-Qt-Controller
TEMPLATE = app

SOURCES += \
    ./main.cpp \
    ./widget.cpp \
    ./clabel.cpp \
    ./robotarm/robotarmstate.cpp \
    robotarm/crobotarm.cpp

HEADERS += \
    ./widget.h \
    ./clabel.h \
    ./robotarm/robotarmstate.h \
    robotarm/crobotarm.h

INCLUDEPATH += \
    ./. \
    ./robotarm/
