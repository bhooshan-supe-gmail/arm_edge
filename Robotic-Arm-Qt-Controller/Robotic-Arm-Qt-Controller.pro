#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T11:53:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robotic-Arm-Qt-Controller
TEMPLATE = app

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
    ./../InterProcessSignalPropagatorLibrary/ \
    ./../ArmEdgeInterProcessSignalPropagator/ \

##BAS_TBR   	-L./../lib -lInterProcessSignalPropagator \
##BAS_TBR   	-L./../lib -lArmEdgeInterProcessSignalPropagator \

LIBS += \

# Input
HEADERS += ./../InterProcessSignalPropagatorLibrary/qinterprocesssignalpropagator.h

SOURCES += ./../InterProcessSignalPropagatorLibrary/qinterprocesssignalpropagator.cpp

HEADERS += ./../ArmEdgeInterProcessSignalPropagator/ArmEdgeInterProcessSignalPropagator.h \
	   ./../ArmEdgeInterProcessSignalPropagator/robotarmstate.h

SOURCES += ./../ArmEdgeInterProcessSignalPropagator/ArmEdgeInterProcessSignalPropagator.cpp \
	   ./../ArmEdgeInterProcessSignalPropagator/robotarmstate.cpp
