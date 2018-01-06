#include "tmess.h"
#include "tmessadaptor.h"

#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusMetaType>
#include <QTime>
#include <QDebug>

struct TMess::Impl
{
    QScopedPointer<TMessAdaptor> adaptor;
};

TMess::TMess() :
    QObject(nullptr),
    QDBusContext(),
    d(new Impl)
{
    d->adaptor.reset(new TMessAdaptor(this));
}

TMess::~TMess()
{
}

void TMess::sendTelemetry(const QString &argument)
{
    // вся работа программы тут!!!!
    // редис, отправка по HTTPS и т.п. сюда и в следующую функцию.
    qDebug() << message().service();
    qDebug() << message().signature();
    qDebug() << QDBusConnection::sessionBus().baseService()
             << message().service();
    qDebug() << QTime::currentTime();
    qDebug() << "INCOMING MESSAGE!!!\t" << argument;
}

void TMess::sendTelemetry(const QString &procedure,
                          const QString &argument)
{
    qDebug() << message().service();
    qDebug() << message().signature();
    qDebug() << QDBusConnection::sessionBus().baseService()
             << message().service();
    qDebug() << QTime::currentTime();
    qDebug() << "INCOMING MESSAGE!!!\t" << procedure << argument;
}
