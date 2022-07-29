QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    runpython.cpp

HEADERS += \
    mainwindow.h \
    mybutton.h \
    runpython.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -LC:/Users/zxf-pingban/AppData/Local/Programs/Python/Python310/libs/ -lpython310

INCLUDEPATH += C:/Users/zxf-pingban/AppData/Local/Programs/Python/Python310/include
DEPENDPATH += C:/Users/zxf-pingban/AppData/Local/Programs/Python/Python310/include

win32:!win32-g++: PRE_TARGETDEPS += C:/Users/zxf-pingban/AppData/Local/Programs/Python/Python310/libs/python310.lib
#else:win32-g++: PRE_TARGETDEPS += C:/Users/zxf-pingban/AppData/Local/Programs/Python/Python310/libs/libpython310.a

#INCLUDEPATH += -I  C:\Users\zxf-pingban\AppData\Local\Programs\Python\Python310\include
#LIBS += -LC:\Users\zxf-pingban\AppData\Local\Programs\Python\Python310\libs/ -lpython310




