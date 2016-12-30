#include "dog.hpp"

#include <QMessageBox>

DogPlugin::DogPlugin()
{
    m_name = "Chien";
}

DogPlugin::~DogPlugin()
{
    // Empty
}


QString DogPlugin::getName() const
{
    return m_name;
}

QString DogPlugin::brawl()
{
    return "OUAF";
}
