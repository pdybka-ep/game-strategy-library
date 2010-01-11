# -------------------------------------------------
# Project created by QtCreator 2010-01-10T13:00:31
# -------------------------------------------------
QT += xml \
    xmlpatterns
TARGET = tic_tac_toe
TEMPLATE = app
SOURCES += main.cpp \
    gamewindow.cpp \
    field.cpp \
    gameboard.cpp \
    optionsdialog.cpp \
    SignDialog.cpp
HEADERS += gamewindow.hpp \
    optionsdialog.hpp \
    gameboard.hpp \
    field.hpp \
    SignDialog.hpp
FORMS += gamewindow.ui \
    optionsdialog.ui \
    signdialog.ui
RESOURCES += res.qrc
