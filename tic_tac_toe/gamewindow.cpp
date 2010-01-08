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
#include "TicTacToeGameController.hpp"
#include "TicTacToePlayer.hpp"


/* A constructor of GameWindow - the main window of a game. */
GameWindow::GameWindow(QWidget *parent): QMainWindow(parent), ui_(new Ui::GameWindow){

    ui_->setupUi(this);
	
}

/* A destructor. */
GameWindow::~GameWindow(){

}

void GameWindow::setGraphicsScene(boost::shared_ptr<QGraphicsScene> graphScene){
	//Ui::GameWindow * ui = static_cast<Ui::GameWindow *> ( ui_.get() );
	ui_->graphicsView->setScene(graphScene.get());
	scene_ = graphScene;
}


/* Sets all the parametres before game is started. */
void GameWindow::okClickedSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel, QString filename){

    int x, y, w, h;
    ui_->graphicsView->rect().getRect(&x, &y, &w, &h);
	scene_->setSceneRect(QRect(x, y, w-2, h-2));
	/*
    board_->startNewGame();
	*/
}


/*************** MENU items reactions ****************/
/* Starts a new game. */
void GameWindow::on_actionNewGame_triggered(){
	//TicTacToeGameController::getInstance().createNewGameSlot();
}

/* Starts a new game with different oponent: a beginner. */
void GameWindow::on_actionBeginner_triggered(){
	//TicTacToeGameController::getInstance().crateNewOponentSlot(TicTacToePlayer::PlayerLevel::BEGINNER);
}

/* Starts a new game with different oponent: an intermediate player. */
void GameWindow::on_actionIntermediate_triggered(){
	//TicTacToeGameController::getInstance().crateNewOponentSlot(TicTacToePlayer::PlayerLevel::INTERMEDIATE);
}

/* Starts a new game with different oponent: an advanced player. */
void GameWindow::on_actionAdvanced_triggered(){
	//TicTacToeGameController::getInstance().crateNewOponentSlot(TicTacToePlayer::PlayerLevel::ADVANCED);
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
