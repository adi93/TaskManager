#-------------------------------------------------
#
# Project created by QtCreator 2018-01-28T15:01:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_manager_desktop
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


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    BoardListWidget.cpp \
    BoardWidget.cpp

HEADERS += \
        MainWindow.h \
    BoardListWidget.h \
    BoardWidget.h

FORMS += \
        MainWindow.ui \
    tasklist.ui \
    BoardListWidget.ui \
    BoardWidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../task_manager_core/release/ -ltask_manager_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../task_manager_core/debug/ -ltask_manager_core
else:unix: LIBS += -L$$OUT_PWD/../task_manager_core/ -ltask_manager_core

INCLUDEPATH += $$PWD/../task_manager_core
DEPENDPATH += $$PWD/../task_manager_core
