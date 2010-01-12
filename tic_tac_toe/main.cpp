/**
    @file main.cpp
    @author Hanna Dutkiewicz
*/

#include <QtGui/QApplication>
#include <QTextCodec>

#include <boost/shared_ptr.hpp>
#include "gamewindow.hpp"
#include "optionsdialog.hpp"
#include "TicTacToeGameController.hpp"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//	QTextCodec::setCodecForCStrings( QTextCodec::codecForName("ISO8859-2") );
//    QTextCodec::setCodecForCStrings( QTextCodec::codecForName("UTF-8") );

	Q_INIT_RESOURCE(res);

	GameWindow window;

	OptionsDialog dialog(&window);

	TicTacToeGameController controller(window);
	controller.initialize();

	window.show();
    dialog.exec();

    return a.exec();
}
