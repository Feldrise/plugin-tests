#pragma once

#include <QMainWindow>
#include <QWidget>

#include <QMenu>

#include "plugininterface.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    bool loadPlugin();

    PluginInterface *m_pluginInterface{ nullptr };
    QMenu *m_criMenu{ nullptr };
};
