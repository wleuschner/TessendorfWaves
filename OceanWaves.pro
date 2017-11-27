#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T17:03:59
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OceanWaves
TEMPLATE = app

DEFINES += GLM_FORCE_RADIANS


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp \
    oceanwaves.cpp \
    vertex.cpp \
    compasswidget.cpp \
    spectrumwidget.cpp \
    heightmapwidget.cpp \
    light.cpp\
    material.cpp\
    camera.cpp\

HEADERS  += mainwindow.h \
    canvas.h \
    oceanwaves.h \
    vertex.h \
    compasswidget.h \
    spectrumwidget.h \
    heightmapwidget.h \
    light.h\
    material.h\
    camera.h\

FORMS    += mainwindow.ui

CONFIG   += c++11

LIBS     += -lfftw3

DISTFILES += \
    shaders/effect.fs \
    shaders/effect.vs
