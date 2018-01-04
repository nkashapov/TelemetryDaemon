#include "tmess.h"
#include <QDebug>
#include <QTime>
#include <QDBusMetaType>
#include <QDBusConnection>
#include <QDBusMessage>

TMessAdapter::TMessAdapter(TMess *parent) :
    QDBusAbstractAdaptor(parent)
{
    m_parentTMess = parent;
    qRegisterMetaType<TestStructure>("TestStructure");
    qDBusRegisterMetaType<TestStructure>();

}

QString TMessAdapter::imageDataSharedId()
{
    return m_parentTMess->imageDataSharedId();
}

TestStructure TMessAdapter::structureField()
{
    return m_parentTMess->structureField();
}

void TMessAdapter::sendTel(QString args)
{
    return m_parentTMess->sendTel(args);
}

void TMessAdapter::sendTel(QString proc, QString args)
{
    return m_parentTMess->sendTel(proc, args);
}

QString TMess::imageDataSharedId()
{
    return m_imageDataSharedId;
}

TestStructure &TMess::structureField()
{
    qDebug()<<"Me calld"<<QDBusConnection::sessionBus().baseService()<<message().service();
    emit callingMe(QString("Panic"), QString("Super panic"));
    test.str = QString("ku");
    test.id =2;
    return test;
}

void TMess::sendTel(QString args){
    // вся работа программы тут!!!!
    // редис, отправка по HTTPS и т.п. сюда и в следующую функцию.
    qDebug()<< message().service();
    qDebug()<< message().signature();
    qDebug()<< QDBusConnection::sessionBus().baseService()<<message().service();
    qDebug()<< QTime::currentTime();
    qDebug()<<"INCOMING MESSAGE!!!  "<<args;
}

void TMess::sendTel(QString proc, QString args){
    qDebug()<< message().service();
    qDebug()<< message().signature();
    qDebug()<< QDBusConnection::sessionBus().baseService()<<message().service();
    qDebug()<< QTime::currentTime();
    qDebug()<<"INCOMING MESSAGE!!!  "<<args;
}
