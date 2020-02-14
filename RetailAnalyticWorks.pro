#-------------------------------------------------
#
# Project created by QtCreator 2020-02-14T13:19:11
#
#-------------------------------------------------

QT       += core gui printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RetailAnalyticWorks
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include (grpc/grpc.pri)
include (pmedia.pri)
SOURCES += \
        main.cpp \
        mainwindow.cpp \
        templatewidget.cpp \
    jsontoprotobuf.cpp \
    customershappines.cpp \
    demographic/demographic.cpp
HEADERS += \
        mainwindow.h \
        templatewidget.h \
    jsontoprotobuf.h \
    customershappines.h \
    helper.h \
    demographic/demographic.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc
