/**
    @file   gamewindow.cpp
    @author Hanna Dutkiewicz
*/

#include <QImage>
#include <QBrush>
#include <QGraphicsScene>
#include <boost/shared_ptr.hpp>

#include "gamewindow.hpp"
#include "ui_gamewindow.h"


/* A constructor of GameWindow - the main window of a game. */
GameWindow::GameWindow(QWidget *parent): QMainWindow(parent), ui_(new Ui::GameWindow){

    ui_->setupUi(this);

	QGraphicsScene * scenePtr = new QGraphicsScene(this);
	boost::shared_ptr<QGraphicsScene> graphScene(scenePtr);

	//board_ = new GameBoard(scenePtr, (QObject *)this );
	board_ = boost::shared_ptr<GameBoard>(new GameBoard(graphScene) );

	ui_->graphicsView->setScene(scenePtr);
}

/* A destructor. */
GameWindow::~GameWindow(){
	//delete board_;
}


/* Sets all the parametres before game is started. */
void GameWindow::okClicked(){
    int x, y, w, h;
    ui_->graphicsView->rect().getRect(&x, &y, &w, &h);
    board_->scene_->setSceneRect(QRect(x, y, w-2, h-2));
    board_->startNewGame();
}


/*************** MENU items reactions ****************/
/* Starts a new game. */
void GameWindow::on_actionNewGame_triggered(){
    board_->startNewGame();
}

/* Starts a new game with different oponent: a beginner. */
void GameWindow::on_actionBeginner_triggered(){
}

/* Starts a new game with different oponent: an intermediate player. */
void GameWindow::on_actionIntermediate_triggered(){
}

/* Starts a new game with different oponent: an advanced player. */
void GameWindow::on_actionAdvanced_triggered(){

}

/* Saves current state of game (to be specific: the wisdom of an oponent). */
void GameWindow::on_actionSave_triggered(){
}

/* Loads state of game (to be specific: the wisdom of an oponent). */
void GameWindow::on_actionLoad_triggered(){

}

/* Closes the game */
void GameWindow::on_actionEnd_triggered(){
    QCoreApplication::quit();
}


