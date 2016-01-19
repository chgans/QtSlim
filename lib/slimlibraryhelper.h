#ifndef SLIMLIBRARYHELPER_H
#define SLIMLIBRARYHELPER_H

#include <QObject>
#include <QStack>

class SlimExecutionContext;

class SlimLibraryHelper : public QObject
{
    Q_OBJECT
public:
    explicit SlimLibraryHelper(QObject *parent = 0);

    void setExecutionContext(SlimExecutionContext *context);

public slots:
    QObject *getFixture();
    void pushFixture();
    void popFixture();
    QObject *cloneSymbol(QObject *symbol);

private:
    SlimExecutionContext *m_context;
    QStack<QObject *> m_fixtureStack;
};

#endif // SLIMLIBRARYHELPER_H
