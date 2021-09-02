/* Swift Assistant is a simple, user-friendly assistant based on an extension system.

   Copyright (C) <2021>  <SwiftApp>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include "plugininterface.h"

class ControlSettings : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "fr.swiftapp.linux.plugin.ControlSettings" FILE "res/controlsettings.json")
    Q_INTERFACES(PluginInterface)

public:
    QString getDataXml() override;
    QString pluginIid() override;
    void execAction(QList<QString> cmd) override;
    QList<QString> getCommande() override;
    QObject* getObject() { return this; }

signals:
    void sendMessage(QString reply, bool isFin, QString typeMessage, QList<QString> url, QList<QString> textUrl);
    void sendMessageToQml(QString message, QString pluginIid);
    void showQml(QString qml, QString iid);

public slots:
    void messageReceived(QString message, QString pluginIid) override;
};

#endif
