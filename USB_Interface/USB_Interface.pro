#-------------------------------------------------
#
# Project created by QtCreator 2013-10-12T11:37:14
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = USB_Interface
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += libusb-1.0

SOURCES += armedgetest.cpp
