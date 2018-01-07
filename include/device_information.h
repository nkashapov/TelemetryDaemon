#ifndef DEVICE_INFORMATION_H
#define DEVICE_INFORMATION_H

#include <QMap>
#include <QScopedPointer>

class DeviceInformation
{
public:
    DeviceInformation();
    ~DeviceInformation();

    QMap<QString, QString> allInformation() const;

    QString buddyInfo() const;
    QString buildProperties() const;
    QString characterAndBlockDevices() const;
    QString cpuInformation() const;
    QString defaultProperties() const;
    QString executionDomains() const;
    QString fileSystems() const;
    QString frameBufferDevices() const;
    QString gpsConfig() const;
    QString hardwareRelease() const;
    QString hosts() const;
    QString interrupts() const;
    QString inputDevices() const;
    QString ioPorts() const;
    QString kernelVersion() const;
    QString loadAverage() const;
    QString lockedFiles() const;
    QString memoryInformation() const;
    QString miscDrivers() const;
    QString osRelease() const;
    QString partitions() const;
    QString sailfishRelease() const;
    QString statistics() const;
    QString swapSpaces() const;
    QString systemRelease() const;
    QString voldFstab() const;

private:
    struct Impl;
    const QScopedPointer<Impl> d;
};

#endif // DEVICE_INFORMATION_H
