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
    optionsdialog.cpp
HEADERS += gamewindow.hpp \
    optionsdialog.hpp \
    gameboard.hpp \
    field.hpp
FORMS += gamewindow.ui \
    optionsdialog.ui
RESOURCES += res.qrc
