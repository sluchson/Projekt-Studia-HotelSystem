QT += core gui sql widgets  # Moduły Qt (SQL dla bazy danych, Widgets dla UI)
TARGET = HotelSystem        # Nazwa pliku wykonywalnego
CONFIG += c++17            # Wersja C++ (opcjonalne, ale zalecane)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Pliki źródłowe
SOURCES += \
    addclient.cpp \
    client.cpp \
    clientwindow.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    rental.cpp \
    rentalwindow.cpp \
    room.cpp \
    roomwindow.cpp

# Pliki nagłówkowe
HEADERS += \
    addclient.h \
    client.h \
    clientwindow.h \
    database.h \
    mainwindow.h \
    rental.h \
    rentalwindow.h \
    room.h \
    roomwindow.h

# Pliki interfejsu (UI)
FORMS += \
    addclient.ui \
    clientwindow.ui \
    mainwindow.ui \
    rentalwindow.ui \
    roomwindow.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
