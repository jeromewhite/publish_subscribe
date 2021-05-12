QT += core
QT += network
QT -= gui

TARGET = server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    event_registry.cpp \
    publish_subscribe.cpp \
    publish_subscribe_document.cpp


HEADERS += \
    event_registry.h \
    publish_subscribe.h \
    Listener.h \
    publish_subscribe_document.h


