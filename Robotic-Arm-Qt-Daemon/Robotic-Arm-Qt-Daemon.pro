#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T11:53:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robotic-Arm-Qt-Daemon
TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += libusb-1.0

SOURCES += \
    ./main.cpp \
    ./widget.cpp \
    ./clabel.cpp \
    robotarm/crobotarm.cpp

HEADERS += \
    ./widget.h \
    ./clabel.h \
    robotarm/crobotarm.h

INCLUDEPATH += \
    ./. \
    ./robotarm/ \
    ./../ArmEdgeInterProcessSignalPropagator/ \


LIBS += \
	-L./../lib -lInterProcessSignalPropagator \
	-L./../lib -lArmEdgeInterProcessSignalPropagator \
