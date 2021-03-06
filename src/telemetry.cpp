/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <sailfishapp.h>
#include "tmess.h"
#include "dbus_traits.h"
#include "device_information.h"
#include "process_information.h"

#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto connection = QDBusConnection::sessionBus();
    TMess tmess;

    if (!connection.registerObject(dbus_traits::path, &tmess))
    {
        fprintf(stderr, "%s\n", qPrintable("Can't register object"));
        exit(1);
    }

    qDebug() << "Telemetry connected to D-bus";

    if (!connection.registerService(dbus_traits::serviceName))
    {
        auto message = QDBusConnection::sessionBus().lastError().message();
        fprintf(stderr, "%s\n", qPrintable(message));
        exit(1);
    }

    auto allInfo = DeviceInformation().allInformation();

    for (const auto& key: allInfo.keys())
        qDebug() << key << ":" << allInfo.value(key);

    auto allProcessAttr = ProcessInformation().allProcessAttributes();

    for (const auto& singleProcAttr: allProcessAttr)
        qDebug() << singleProcAttr.name << "-"
                 << singleProcAttr.cpuUsage << "-"
                 << singleProcAttr.memoryUsage;

    qDebug() << "Test service start";
    return a.exec();
}
