#   Swift Assistant is a simple, user-friendly assistant based on an extension system.
#	
#   Copyright (C) <2021>  <SwiftApp>
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.

#! [0]
TEMPLATE        = lib
CONFIG         += plugin
QT             += core
TARGET          = $$qtLibraryTarget(controlsettings)
#! [0]

EXAMPLE_FILES = src/res/controlesettings.json

INSTALLS += target

CONFIG += install_ok  # Do not cargo-cult this!

HEADERS += \
    src/controlsettings.h \
    src/plugininterface.h

SOURCES += \
    src/controlsettings.cpp

RESOURCES += \
    src/res/res.qrc
