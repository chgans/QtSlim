#ifndef FIXTURELOADER_H
#define FIXTURELOADER_H

#include "ifixtureprovider.h"

class QPluginLoader;

class FixtureLoader
{
public:
    FixtureLoader();

    IFixtureProvider *load(const QString filename);
    bool hasError() const;
    QString errorString() const;

private:
    void setErrorString(const QString &message);
    QString m_errorString;
};

#endif // FIXTURELOADER_H
