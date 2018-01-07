#ifndef TMESS_ADAPTOR_H
#define TMESS_ADAPTOR_H

#include <QDBusAbstractAdaptor>
#include "dbus_traits.h"

class TMess;

class TMessAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", BUFFER_NAME)

public:
    explicit TMessAdaptor(TMess *parent);
    ~TMessAdaptor();

public slots:
    void sendTelemetry(const QString &argument);
    void sendTelemetry(const QString &procedure,
                       const QString &argument);

private:
    struct Impl;
    const QScopedPointer<Impl> d;
};

#endif // TMESS_ADAPTOR_H
