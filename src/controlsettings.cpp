/* ControlSettings is an extention for Swifty Assistant.

   Copyright (C) <2021>  <SwiftyApp>

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

#include "controlsettings.h"

#include <QFile>
#include <QLocale>

/**
 * Return the keywords with the answers that match in xml format
 *
 * @return the keywords in xml format
 */
QString ControlSettings::getDataXml()
{
    QString locale = QLocale::system().name().section('_', 0, 0);
    QFile file(":/XML/ControlSettingsData_"+locale+".xml");
    if (!file.exists()) {
        file.setFileName(":/XML/ControlSettingsData_en.xml");
    }
    file.open(QIODevice::ReadOnly);

    return file.readAll();
}

/**
 * Returns the unique identifier of the plugin
 *
 * @return the id
 */
QString ControlSettings::pluginId()
{
    return "fr.swifty.controlsettings";
}

/**
 * Returns a list of proposals related to the plugin
 *
 * @return the list of proposals
 */
QList<QString> ControlSettings::getCommande()
{
    QList<QString> list;
    QString locale = QLocale::system().name().section('_', 0, 0);

    if (locale == "fr") list << "Ouvre les paramètres" << "Affiche la configuration";
    else list << "Opens the settings" << "Show configuration";

    return list;
}

/**
 * Called when a special action is defined in the xml
 */
void ControlSettings::execAction(QList<QString>) {}

/**
 * Called when a custom interface is displayed and sends a message
 */
void ControlSettings::messageReceived(QString, QString) {}
