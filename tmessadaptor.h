#ifndef TMESSADAPTOR_H
#define TMESSADAPTOR_H

#include <QDBusAbstractAdaptor>
#include "servicenameandproperty.h"

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

#endif // TMESSADAPTOR_H
