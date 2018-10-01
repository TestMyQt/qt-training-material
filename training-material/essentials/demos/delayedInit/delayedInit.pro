TEMPLATE=app
SOURCES = main.cpp \ 
    sender.cpp \
    receiver.cpp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    sender.h \
    receiver.h

