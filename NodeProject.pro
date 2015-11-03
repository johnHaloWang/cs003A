TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    node.cpp \
    nodelistfunctions.cpp \
    list.cpp \
    iterator.cpp

HEADERS += \
    node.h \
    nodelistfunctions.h \
    list.h \
    iterator.h

