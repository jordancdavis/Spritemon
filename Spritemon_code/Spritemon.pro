#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T10:55:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spritemon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    spritemon.cpp \
    imagelabel.cpp

HEADERS  += mainwindow.h \
    spritemon.h \
    imagelabel.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
unix:!macx{

win32:CONFIG(release, debug|release): LIBS += -L/usr/lib64/release/ -lMagick++
else:win32:CONFIG(debug, debug|release): LIBS += -L/usr/lib64/debug/ -lMagick++
else:linux: LIBS += -L/usr/lib64/ -lMagick++ -lMagickCore

INCLUDEPATH += /usr/include/ImageMagick
DEPENDPATH += /usr/include/ImageMagick
}
