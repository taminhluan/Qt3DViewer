# add opengl and libs
QT       += core gui opengl
LIBS += -lopengl32 -glu32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    3d/tmp/CubeExample.cpp \
    3d/tmp/PointsExample.cpp \
    3d/tmp/TriangleExample.cpp \
    Listener.cpp \
    OpenGLWidget.cpp \
    PerspectiveCamera.cpp \
    Speaker.cpp \
    listenerimpl.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    3d/core/Object3D.h \
    3d/tmp/CubeExample.h \
    3d/tmp/PointsExample.h \
    3d/tmp/TriangleExample.h \
    Listener.h \
    OpenGLWidget.h \
    PerspectiveCamera.h \
    Speacker.h \
    listenerimpl.h \
    mainwindow.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

INCLUDEPATH = external/glm
