#-------------------------------------------------
#
# Project created by QtCreator 2020-07-08T15:28:22
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrEchoSimuCtrl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# 解决UTF-8BOM格式中文显示乱码问题
win32:{
    QMAKE_CXXFLAGS += /utf-8
}

CONFIG(debug, debug|release){
    DESTDIR =$$PWD/../x64/Debug
}else{
    DESTDIR =$$PWD/../x64/Release
}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
#LIBPATH = C:/Users/tz/Desktop/newfile/Library
LIBPATH = $$DESTDIR/Library

include ( $$LIBPATH/AsioLib/AsioLib.prf )
include ( $$LIBPATH/RadarBase/RadarBase.prf )
include ( $$LIBPATH/RadarMap/RadarMap.prf )

SOURCES += \
        commandexec.cpp \
        ctrldlg.cpp \
        datahandler.cpp \
        gconfig.cpp \
        historyradarmodel.cpp \
        historyradarwidget.cpp \
        main.cpp \
        mainwindow.cpp \
        network.cpp \
        protocolop.cpp \
        radardisplay.cpp \
        radarstatusmodel.cpp \
        radarwidget.cpp \
        sqlitedatabase.cpp \
        useroperate.cpp

HEADERS += \
        commandexec.h \
        ctrldlg.h \
        datadef.h \
        gconfig.h \
        historyradarmodel.h \
        historyradarwidget.h \
        mainwindow.h \
        network.h \
        protocol_33.h \
        protocolop.h \
        radardisplay.h \
        radarstatusmodel.h \
        radarwidget.h \
        sqlitedatabase.h \
        structdef.h \
        useroperate.h

FORMS += \
        ctrldlg.ui \
        historyradarwidget.ui \
        mainwindow.ui \
        radarwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
