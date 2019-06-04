TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    factory.cpp \
    container.cpp \
    sorter.cpp \
    menu.cpp

HEADERS += \
    container.h \
    sorter.h \
    menu.h \
    object.h \
    plant.h
