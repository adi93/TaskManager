#-------------------------------------------------
#
# Project created by QtCreator 2018-01-20T19:03:30
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = task_manager_core
TEMPLATE = lib

DEFINES += TASK_MANAGER_CORE_LIBRARY

CONFIG += c++14

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
        task_manager_core.cpp \
    dao/BoardDao.cpp \
    dao/TaskDao.cpp \
    entity/Board.cpp \
    entity/Task.cpp \
    dao/DatabaseManager.cpp \
    model/BoardModel.cpp

HEADERS += \
        task_manager_core.h \
        task_manager_core_global.h \
    dao/BoardDao.h \
    dao/TaskDao.h \
    entity/Board.h \
    entity/Task.h \
    dao/DatabaseManager.h \
    model/BoardModel.h
