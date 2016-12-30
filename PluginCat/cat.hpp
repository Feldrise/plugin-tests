#pragma once

#include <QObject>
#include <QtPlugin>

#include "plugininterface.hpp"

class CatPlugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.feldrise.AnimalNoise.PluginInterface" FILE "plugincat.json")
    Q_INTERFACES(PluginInterface)

public:
    CatPlugin();
    virtual ~CatPlugin();

    virtual QString getName() const;

    virtual QString brawl();
};
