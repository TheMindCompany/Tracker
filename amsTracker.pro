#-------------------------------------------------
#
# Project created by QtCreator 2012-08-08T11:28:10
#
#-------------------------------------------------

QT       += core gui sql

TARGET = amsTracker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cardui.cpp \
    listui.cpp \
    trackersql.cpp \
    card.cpp \
    list.cpp

HEADERS  += mainwindow.h \
    cardui.h \
    listui.h \
    trackersql.h \
    card.h \
    list.h

OTHER_FILES += \
    assets/defaultStyle.qss \
    assets/cardDesktopStyle.qss \
    images/favicon114.ico \
    resource.rc \
    images/cardHeader.png \
    images/aitpLogo.png

RC_FILE = resource.rc
