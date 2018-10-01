TARGET = SlideShow
TEMPLATE = app
SOURCES += main.cpp \
    mygesture.cpp \
    slideshowdialog.cpp \
    mygesturerecognizer.cpp \
    mypixmapitem.cpp
HEADERS += mygesture.h \
    slideshowdialog.h \
    mygesturerecognizer.h \
    mypixmapitem.h
FORMS += slideshowdialog.ui
OTHER_FILES += 
RESOURCES += slideshow.qrc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
