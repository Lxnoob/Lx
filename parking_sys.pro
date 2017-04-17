#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T17:10:40
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = parking_sys
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    parking.cpp \
    checkwig.cpp \
    carport.cpp

HEADERS  += login.h \
    parking.h \
    checkwig.h \
    carport.h

FORMS    += login.ui \
    parking.ui \
    checkwig.ui \
    carport.ui
