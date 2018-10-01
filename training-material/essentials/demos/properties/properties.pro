TEMPLATE = app
TARGET = properties
DEPENDPATH += .
INCLUDEPATH += .

# Input
SOURCES += objtostring.cpp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
