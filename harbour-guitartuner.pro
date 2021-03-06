# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = harbour-guitartuner

CONFIG += c++11 sailfishapp

PKGCONFIG += libpulse-simple audioresource

SOURCES += src/harbour-guitartuner.cpp \
    src/recorder.cpp \
    src/recordfacade.cpp \
    src/vendor/LinearFilter.cpp \
    src/vendor/ZeroCross.cpp \
    src/vendor/Scale.cpp \
    src/strings/standardguitar.cpp \
    src/recordresultcomputation.cpp \
    src/notes.cpp \
    src/strings/tenorukulele.cpp \
    src/wrapper.cpp

OTHER_FILES += qml/harbour-guitartuner.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/harbour-guitartuner.changes.in \
    rpm/harbour-guitartuner.spec \
    rpm/harbour-guitartuner.yaml \
    translations/*.ts \
    harbour-guitartuner.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/harbour-guitartuner-de.ts

DISTFILES += \
    qml/pages/ClassicGuitar.qml \
    qml/Views/Tuner.qml \
    qml/pages/Stroi.qml

RESOURCES +=

HEADERS += \
    src/recorder.h \
    src/recordfacade.h \
    src/vendor/LinearFilter.hpp \
    src/vendor/ZeroCross.hpp \
    src/vendor/Scale.hpp \
    src/strings/basestrings.h \
    src/strings/standardguitar.h \
    src/recordresultcomputation.h \
    src/notes.h \
    src/strings/tenorukulele.h \
    src/wrapper.h

QT += multimedia




