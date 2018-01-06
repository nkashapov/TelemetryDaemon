#include "tmessadaptor.h"
#include "tmess.h"

struct TMessAdaptor::Impl
{
    TMess* tmess = nullptr;
};

TMessAdaptor::TMessAdaptor(TMess *parent) :
    QDBusAbstractAdaptor(parent),
    d(new Impl)
{
    d->tmess = parent;
}

TMessAdaptor::~TMessAdaptor()
{
}

void TMessAdaptor::sendTelemetry(const QString &argument)
{
    d->tmess->sendTelemetry(argument);
}

void TMessAdaptor::sendTelemetry(const QString &procedure,
                                 const QString &argument)
{
    d->tmess->sendTelemetry(procedure, argument);
}
