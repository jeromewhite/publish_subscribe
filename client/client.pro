#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T13:36:11
#
#-------------------------------------------------

QT       -= gui

TARGET = client
TEMPLATE = lib
CONFIG += staticlib

SOURCES += client.cpp

HEADERS += client.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
