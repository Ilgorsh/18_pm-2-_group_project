TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    container.cpp \
    main.cpp \
    menu.cpp \
    object.cpp \
    plant.cpp \
    sorter.cpp \
    menu_realiz.cpp

FORMS +=

HEADERS += \
    container.h \
    menu.h \
    object.h \
    plant.h \
    sorter.h

DISTFILES +=

RESOURCES += \
    files.qrc
