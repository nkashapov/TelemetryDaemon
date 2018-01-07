#ifndef PROCESS_INFORMATION_H
#define PROCESS_INFORMATION_H

#include <QList>
#include <QScopedPointer>

struct ProcessAttributes
{
    QString name;
    double cpuUsage;
    double memoryUsage;
};

class ProcessInformation
{
public:
    ProcessInformation();
    ~ProcessInformation();

    QList<ProcessAttributes> allProcessAttributes() const;

private:
    struct Impl;
    const QScopedPointer<Impl> d;
};

#endif // PROCESS_INFORMATION_H
