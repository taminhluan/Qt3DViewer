# add opengl and libs
QT       += core gui opengl
LIBS += -lopengl32 -glu32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    3d/geometry/SphereGeometry.cpp \
    3d/io/BinReader.cpp \
    3d/io/BinWriter.cpp \
    3d/io/LasReader.cpp \
    3d/io/PCLTextReader.cpp \
    3d/material/BasicMaterial.cpp \
    3d/renderer/PCLRenderer.cpp \
    3d/renderer/opengl/OpenGLBindingState.cpp \
    3d/renderer/opengl/OpenGLBufferRenderer.cpp \
    3d/tmp/CubeExample.cpp \
    3d/tmp/PointsExample.cpp \
    3d/tmp/TriangleExample.cpp \
    3d/tool/Converter.cpp \
    Listener.cpp \
    OpenGLWidget.cpp \
    PerspectiveCamera.cpp \
    Speaker.cpp \
    app/OpenFileUsecase.cpp \
    converterdialog.cpp \
    listenerimpl.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    3d/core/MeshNode.h \
    3d/core/Object3D.h \
    3d/core/PCLNode.h \
    3d/geometry/PCLGeometry.h \
    3d/geometry/SphereGeometry.h \
    3d/io/BinReader.h \
    3d/io/BinWriter.h \
    3d/io/LasReader.h \
    3d/io/PCLTextReader.h \
    3d/material/BasicMaterial.h \
    3d/renderer/PCLRenderer.h \
    3d/renderer/Renderer.h \
    3d/renderer/opengl/OpenGLBindingState.h \
    3d/renderer/opengl/OpenGLBufferRenderer.h \
    3d/tmp/CubeExample.h \
    3d/tmp/Drawable.h \
    3d/tmp/PointsExample.h \
    3d/tmp/TriangleExample.h \
    3d/tool/Converter.h \
    3d/util/PathUtil.h \
    Listener.h \
    OpenGLWidget.h \
    PerspectiveCamera.h \
    Speacker.h \
    app/OpenFileUsecase.h \
    converterdialog.h \
    listenerimpl.h \
    mainwindow.h \

FORMS += \
    converterdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

INCLUDEPATH = external/glm
