#include "mainwindow.hpp"

#include <QApplication>

#include <QMessageBox>
#include <QMenuBar>
#include <QDir>

#include <QPluginLoader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_criMenu = menuBar()->addMenu("Cris");
    if(!loadPlugin())
        QMessageBox::critical(this, "Erreur", "Impossible de lire de plugin...");
}

MainWindow::~MainWindow()
{
    // Empty
}

bool MainWindow::loadPlugin()
{
    QDir pluginDir{ qApp->applicationDirPath() };

    pluginDir.cd("plugins");

    QMessageBox::information(this, "First", pluginDir.absolutePath());

    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        QMessageBox::information(this, "DEBUG", "Load a plugin: " + fileName);
        QPluginLoader pluginLoader(pluginDir.absoluteFilePath(fileName));
        QMessageBox::critical(this, "DEBUG", pluginLoader.fileName());
        QObject *plugin = pluginLoader.instance();
        QMessageBox::information(this, "DEBUG", pluginDir.absoluteFilePath(fileName));
        QMessageBox::critical(this, "DEBUG", QString::number(pluginLoader.isLoaded()));


        if(plugin != nullptr) {
            PluginInterface *interface{ qobject_cast<PluginInterface*>(plugin) };
            QString bruit{ interface->brawl() };
            Crieur *crieur{ new Crieur(bruit) };
            QMessageBox::information(this, "DEBUG", "The plugin is valide");
            QAction *action{ new QAction(interface->getName()) };
            m_criMenu->addAction(action);
            connect(action, &QAction::triggered, crieur, &Crieur::crier);
        }
        else {
            return false;
        }
    }

    return true;
}
