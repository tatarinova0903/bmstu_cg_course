QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MathObjects/brownianmotion.cpp \
    MathObjects/matrix.cpp \
    MathObjects/transformmatrix.cpp \
    MathObjects/vector3.cpp \
    SceneObjects/basemodel.cpp \
    SceneObjects/camera.cpp \
    SceneObjects/lightsourcepoint.cpp \
    SceneObjects/model.cpp \
    SceneObjects/virus.cpp \
    drawer.cpp \
    main.cpp \
    mainwindow.cpp \
    scene.cpp \
    zbuffer.cpp

HEADERS += \
    MathObjects/brownianmotion.h \
    MathObjects/matrix.h \
    MathObjects/transformmatrix.h \
    MathObjects/vector3.h \
    MathObjects/vector3.hpp \
    SceneObjects/AddModelParameters.h \
    SceneObjects/Material.h \
    SceneObjects/basemodel.h \
    SceneObjects/camera.h \
    SceneObjects/lightsourcepoint.h \
    SceneObjects/model.h \
    SceneObjects/virus.h \
    drawer.h \
    mainwindow.h \
    scene.h \
    zbuffer.h

FORMS += \
    UiForms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
