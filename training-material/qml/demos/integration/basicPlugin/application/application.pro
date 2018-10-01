QT       += quick qml
RESOURCES = application.qrc
SOURCES   = main.cpp

TARGET    = basicpluginapp

OTHER_FILES += \
    files/ellipse9.qml

target.path = .
!isEmpty(target.path): INSTALLS += target
