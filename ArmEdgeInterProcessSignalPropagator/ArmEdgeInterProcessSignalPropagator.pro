QT += network

CONFIG += staticlib

win32:CONFIG += console

TEMPLATE = lib

TARGET = ArmEdgeInterProcessSignalPropagator
DESTDIR = ./../lib
DEPENDPATH += .
INCLUDEPATH += . \
                ./../InterProcessSignalPropagatorLibrary

# Input
HEADERS += ArmEdgeInterProcessSignalPropagator.h \
	    robotarmstate.h

SOURCES += ArmEdgeInterProcessSignalPropagator.cpp \
	    robotarmstate.cpp

