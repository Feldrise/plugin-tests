#pragma once

#include <QString>
#include <QObject>
#include <QMessageBox>

class PluginInterface
{
public:
    virtual ~PluginInterface() {}

    virtual QString getName() const = 0;

    virtual QString brawl() = 0;

protected:
    QString m_name;
};

QT_BEGIN_NAMESPACE
#define PluginInterface_iid "com.feldrise.AnimalNoise.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

QT_END_NAMESPACE

class Crieur : public QObject
{
    Q_OBJECT

public:
    Crieur(QString &cri) : m_bruit(cri) {}
    ~Crieur() {}

    void crier()
    {
        QMessageBox::information(nullptr, "Cri", m_bruit);
    }

private:
    QString m_bruit;
};
