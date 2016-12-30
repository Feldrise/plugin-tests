#pragma once

#include <QObject>
#include <QtPlugin>

#include "plugininterface.hpp"

class DogPlugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.feldrise.AnimalNoise.PluginInterface" FILE "plugindog.json")
    Q_INTERFACES(PluginInterface)

public:
    DogPlugin();
    virtual ~DogPlugin();

    virtual QString getName() const;

    virtual QString brawl();
};
