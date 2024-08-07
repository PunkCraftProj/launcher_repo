QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    registration.cpp \
    settings.cpp

HEADERS += \
    connection.h \
    mainwindow.h \
    registration.h \
    settings.h

FORMS += \
    mainwindow.ui \
    registration.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../Program Files/PostgreSQL/14/release/' -liconv
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../Program Files/PostgreSQL/14/debug/' -liconv
else:unix: LIBS += -L$$PWD/'../../../Program Files/PostgreSQL/14/' -liconv

INCLUDEPATH += $$PWD/'../../../Program Files/PostgreSQL/14/lib'
DEPENDPATH += $$PWD/'../../../Program Files/PostgreSQL/14/lib'
