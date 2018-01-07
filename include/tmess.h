#ifndef TMESS_H
#define TMESS_H

#include <QObject>
#include <QDBusContext>

class TMess : public QObject, public QDBusContext
{
    Q_OBJECT

public:
    TMess();
    ~TMess();

public slots:
    void sendTelemetry(const QString &argument);
    void sendTelemetry(const QString &procedure,
                       const QString &argument);

private:
    struct Impl;
    const QScopedPointer<Impl> d;
};

#endif // TMESS_H
