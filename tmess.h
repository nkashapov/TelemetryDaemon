#ifndef TMESS_H
#define TMESS_H
#include <QDBusAbstractAdaptor>
#include <QDBusVariant>
#include <QDBusArgument>
#include <QDBusContext>

#include "servicenameandproperty.h"
class  TMess;

class  TMessAdapter : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", BUFFER_NAME)
    Q_PROPERTY(QString IMAGE_DATA_SHARED_ID READ imageDataSharedId)
public:
    explicit TMessAdapter(TMess *parent);
    QString imageDataSharedId();
    //void sendTel(QString);
public slots:
    TestStructure structureField();
    void sendTel(QString);
    void sendTel(QString, QString);
signals:
    void callingMe(QString, QString);

private:
    TMess * m_parentTMess;

};

class TMess : public QObject, public QDBusContext
{
    Q_OBJECT
public:
    TMess()
    {
        m_TMessAdapter = new TMessAdapter(this);
        QObject::connect(this, SIGNAL(callingMe(QString,QString)), m_TMessAdapter, SIGNAL(callingMe(QString, QString)));
        m_imageDataSharedId = "testImageBufferId";

    }
public:
    QString imageDataSharedId();
    TestStructure& structureField();
    void sendTel(QString);
    void sendTel(QString, QString);
signals:
    void callingMe(QString, QString);

private:
    TMessAdapter *m_TMessAdapter;
    QString m_imageDataSharedId;
    TestStructure test;

};


#endif // TMESS_H
