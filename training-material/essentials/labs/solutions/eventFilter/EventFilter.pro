TARGET = EventFilter
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp
HEADERS += mainwindow.h
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
