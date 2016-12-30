#include "cat.hpp"

#include <QMessageBox>

CatPlugin::CatPlugin()
{
    m_name = "Chat";
}

CatPlugin::~CatPlugin()
{
    // Empty
}


QString CatPlugin::getName() const
{
    return m_name;
}

QString CatPlugin::brawl()
{
    return "MIAOU";
}
