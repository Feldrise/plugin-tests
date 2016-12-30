QT += widgets

INCLUDEPATH += "../AnimalNoise"

TEMPLATE = lib
CONFIG += plugin
TARGET = $$qtLibraryTarget(CatPlugin)
DESTDIR = "../AnimalNoise/plugins"

HEADERS += \
    cat.hpp

SOURCES += \
    cat.cpp
