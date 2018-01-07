#include "device_information.h"

#include <QFile>
#include <QDebug>

namespace
{
    const QString buddyInfoFile                = "/proc/buddyinfo";
    const QString buildPropertiesFile          = "/system/build.prop";
    const QString characterAndBlockDevicesFile = "/proc/devices";
    const QString cpuInformationFile           = "/proc/cpuinfo";
    const QString defaultPropertiesFile        = "/default.prop";
    const QString executionDomainsFile         = "/proc/execdomains";
    const QString fileSystemsFile              = "/proc/filesystems";
    const QString frameBufferDevicesFile       = "/proc/fb";
    const QString gpsConfigFile                = "/system/etc/gps.conf";
    const QString hardwareReleaseFile          = "/etc/hw-release";
    const QString hostsFile                    = "/system/etc/hosts";
    const QString interruptsFile               = "/proc/interrupts";
    const QString inputDevicesFile             = "/proc/bus/input/devices";
    const QString ioPortsFile                  = "/proc/ioports";
    const QString kernelVersionFile            = "/proc/version";
    const QString loadAverageFile              = "/proc/loadavg";
    const QString lockedFilesFile              = "/proc/locks";
    const QString memoryInformationFile        = "/proc/meminfo";
    const QString miscDriversFile              = "/proc/misc";
    const QString osReleaseFile                = "/etc/os-release";
    const QString partitionsFile               = "/proc/partitions";
    const QString sailfishReleaseFile          = "/etc/sailfish-release";
    const QString statisticsFile               = "/proc/stat";
    const QString swapSpacesFile               = "/proc/swap";
    const QString systemReleaseFile            = "/etc/system-release";
    const QString voldFstabFile                = "/system/etc/vold.fstab";
}

struct DeviceInformation::Impl
{
    QString readDataFromFile(const QString& fileName)
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Can't open" << fileName << "file!";
            return {};
        }

        QTextStream in(&file);
        return in.readAll();
    }
};

DeviceInformation::DeviceInformation() :
    d(new Impl)
{
}

DeviceInformation::~DeviceInformation()
{
}

QMap<QString, QString> DeviceInformation::allInformation() const
{
    return {
        {"Buddy Info",                this->buddyInfo()},
        {"Build Properties",          this->buildProperties()},
        {"Character & Block Devices", this->characterAndBlockDevices()},
        {"CPU Information",           this->cpuInformation()},
        {"Default Properties",        this->defaultProperties()},
        {"Execution Domains",         this->executionDomains()},
        {"File Systems",              this->fileSystems()},
        {"Frame Buffer Devices",      this->frameBufferDevices()},
        {"GPS Config",                this->gpsConfig()},
        {"Hardware Release",          this->hardwareRelease()},
        {"Hosts",                     this->hosts()},
        {"Interrupts",                this->interrupts()},
        {"Input Devices",             this->inputDevices()},
        {"I/O Ports",                 this->ioPorts()},
        {"Kernel Version",            this->kernelVersion()},
        {"Load Average",              this->loadAverage()},
        {"Locked Files",              this->lockedFiles()},
        {"Memory Information",        this->memoryInformation()},
        {"Misc Drivers",              this->miscDrivers()},
        {"OS Release",                this->osRelease()},
        {"Partitions",                this->partitions()},
        {"Sailfish Release",          this->sailfishRelease()},
        {"Statistics",                this->statistics()},
        {"Swap Spaces",               this->swapSpaces()},
        {"System Release",            this->systemRelease()},
        {"Vold Fstab",                this->voldFstab()},
    };
}

QString DeviceInformation::buddyInfo() const
{
    return d->readDataFromFile(::buddyInfoFile);
}

QString DeviceInformation::buildProperties() const
{
    return d->readDataFromFile(::buildPropertiesFile);
}

QString DeviceInformation::characterAndBlockDevices() const
{
    return d->readDataFromFile(::characterAndBlockDevicesFile);
}

QString DeviceInformation::cpuInformation() const
{
    return d->readDataFromFile(::cpuInformationFile);
}

QString DeviceInformation::defaultProperties() const
{
    return d->readDataFromFile(::defaultPropertiesFile);
}

QString DeviceInformation::executionDomains() const
{
    return d->readDataFromFile(::executionDomainsFile);
}

QString DeviceInformation::fileSystems() const
{
    return d->readDataFromFile(::fileSystemsFile);
}

QString DeviceInformation::frameBufferDevices() const
{
    return d->readDataFromFile(::frameBufferDevicesFile);
}

QString DeviceInformation::gpsConfig() const
{
    return d->readDataFromFile(::gpsConfigFile);
}

QString DeviceInformation::hardwareRelease() const
{
    return d->readDataFromFile(::hardwareReleaseFile);
}

QString DeviceInformation::hosts() const
{
    return d->readDataFromFile(::hostsFile);
}

QString DeviceInformation::interrupts() const
{
    return d->readDataFromFile(::interruptsFile);
}

QString DeviceInformation::inputDevices() const
{
    return d->readDataFromFile(::inputDevicesFile);
}

QString DeviceInformation::ioPorts() const
{
    return d->readDataFromFile(::ioPortsFile);
}

QString DeviceInformation::kernelVersion() const
{
    return d->readDataFromFile(::kernelVersionFile);
}

QString DeviceInformation::loadAverage() const
{
    return d->readDataFromFile(::loadAverageFile);
}

QString DeviceInformation::lockedFiles() const
{
    return d->readDataFromFile(::lockedFilesFile);
}

QString DeviceInformation::memoryInformation() const
{
    return d->readDataFromFile(::memoryInformationFile);
}

QString DeviceInformation::miscDrivers() const
{
    return d->readDataFromFile(::miscDriversFile);
}

QString DeviceInformation::osRelease() const
{
    return d->readDataFromFile(::osReleaseFile);
}

QString DeviceInformation::partitions() const
{
    return d->readDataFromFile(::partitionsFile);
}

QString DeviceInformation::sailfishRelease() const
{
    return d->readDataFromFile(::sailfishReleaseFile);
}

QString DeviceInformation::statistics() const
{
    return d->readDataFromFile(::statisticsFile);
}

QString DeviceInformation::swapSpaces() const
{
    return d->readDataFromFile(::swapSpacesFile);
}

QString DeviceInformation::systemRelease() const
{
    return d->readDataFromFile(::systemReleaseFile);
}

QString DeviceInformation::voldFstab() const
{
    return d->readDataFromFile(::voldFstabFile);
}
