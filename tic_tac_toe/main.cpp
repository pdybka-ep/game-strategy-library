/**
    @file main.cpp
    @author Hanna Dutkiewicz
*/

#include <QtGui/QApplication>
#include "gamewindow.hpp"
#include "optionsdialog.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;

    OptionsDialog dialog(&w);

    w.show();
    dialog.exec();
    return a.exec();
}
