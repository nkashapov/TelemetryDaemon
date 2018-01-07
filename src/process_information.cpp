#include "process_information.h"

#include <QProcess>
#include <QTextStream>

namespace
{
    const QString psProcessName = "ps";
    const QStringList psProcessParameters = {"axo", "%cpu,%mem,comm"};
    const int waitForStartedInterval = 2000;
    const int waitForFinishedInterval = 3000;
}

struct ProcessInformation::Impl
{
    QList<ProcessAttributes> parsePsData(QTextStream& stream)
    {
        QList<ProcessAttributes> attributes;
        QString line;

        while (stream.readLineInto(&line))
        {
            auto splittedLine = line.split(" ", QString::SkipEmptyParts);
            if (splittedLine.size() < 3) continue;

            // see attributes order in psProcessParameters
            attributes.append({splittedLine.at(2),
                               splittedLine.at(0).toDouble(),
                               splittedLine.at(1).toDouble()});
        }

        return attributes;
    }
};

ProcessInformation::ProcessInformation() :
    d(new Impl)
{
}

ProcessInformation::~ProcessInformation()
{
}

QList<ProcessAttributes> ProcessInformation::allProcessAttributes() const
{
    QProcess psProcess;
    psProcess.start(::psProcessName, ::psProcessParameters);

    if (!psProcess.waitForStarted(::waitForStartedInterval))
        return {};

    if (!psProcess.waitForFinished(::waitForFinishedInterval))
        return {};

    QTextStream in(&psProcess);
    // skip header line
    in.readLine();

    return d->parsePsData(in);
}
