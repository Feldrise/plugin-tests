QT += widgets

INCLUDEPATH += "../AnimalNoise"

TEMPLATE = lib
CONFIG += plugin
TARGET = $$qtLibraryTarget(DogPlugin)
DESTDIR = "../AnimalNoise/plugins"

HEADERS += \
    dog.hpp

SOURCES += \
    dog.cpp
