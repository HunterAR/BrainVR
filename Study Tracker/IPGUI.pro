#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T16:27:47
#
#-------------------------------------------------

QT += core gui
QT += svg

CONFIG += console
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IPGUI
TEMPLATE = app
SOURCES += main.cpp\
        mainwindow.cpp \
    pugixml-1.7/src/pugixml.cpp \
    KRRPredictor.cpp \
    RegressionPredictor.cpp \
    SVRPredictor.cpp

HEADERS  += mainwindow.h \
    pugixml-1.7/src/pugixml.hpp \
    KRRPredictor.h \
    MachineLearning.h \
    RegressionPredictor.h \
    SVRPredictor.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/../dlib-18.17
DEPENDPATH += $$PWD/../dlib-18.17
