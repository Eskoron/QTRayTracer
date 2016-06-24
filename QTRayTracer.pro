#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T14:38:32
#
#-------------------------------------------------

QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTRayTracer
TEMPLATE = app


SOURCES += main.cpp\
    GUIOutput/glwidget.cpp \
    GUIOutput/window.cpp

HEADERS  += \
    GUIOutput/glwidget.h \
    GUIOutput/window.h \
    Math/vector3.h \
    Math/rmath.h \
    Camera/camera.h \
    Math/rotator.h \
    defines.h \
    Math/quaternion.h \
    Geometry/geometry.h \
    Geometry/sphere.h \
    Camera/perspectivecamera.h \
    Renderer/ray.h \
    Renderer/raycaster.h \
    Math/matrix44.h \
    Math/color.h \
    Renderer/intersectinfo.h \
    Math/rotationmatrix.h \
    Math/translationmatrix.h \
    Math/scalematrix.h \
    Math/translationrotationmatrix.h

FORMS    +=
