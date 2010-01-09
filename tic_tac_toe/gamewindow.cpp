/**
    @file   gamewindow.cpp
    @author Hanna Dutkiewicz
*/

#include <QImage>
#include <QBrush>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>

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
	
	// set oponent's level and player's sign on the window
	//ui_->playerSignLabel->setText();
	//ui_->oponentLevelLabel->setText();

	// generate signal to GameController to start a new game
	if(filename.isEmpty()){
		createFirstGameNewPlayerSignal(humanPlayerSign, computerPlayerLevel);
	}
	else{
		createFirstGameLoadPlayerSignal(humanPlayerSign, filename.toStdString());
	}
}


/*************** MENU items reactions ****************/
/* Starts a new game. */
void GameWindow::on_actionNewGame_triggered(){
	createNewGameSignal();
}

/* Starts a new game with different oponent: a beginner. */
void GameWindow::on_actionBeginner_triggered(){
	crateNewOponentSignal(TicTacToePlayer::BEGINNER);
}

/* Starts a new game with different oponent: an intermediate player. */
void GameWindow::on_actionIntermediate_triggered(){
	crateNewOponentSignal(TicTacToePlayer::INTERMEDIATE);
}

/* Starts a new game with different oponent: an advanced player. */
void GameWindow::on_actionAdvanced_triggered(){
	crateNewOponentSignal(TicTacToePlayer::ADVANCED);
}

/* Saves current state of game (to be specific: the wisdom of an oponent). */
void GameWindow::on_actionSave_triggered(){
	saveGameSignal();
}

/* Loads state of game (to be specific: the wisdom of an oponent). */
void GameWindow::on_actionLoad_triggered(){
	QString qfilename = QFileDialog::getOpenFileName(this, tr("Open"), "/", tr("Game Files (*.beg *.int *.adv)"));
	loadGameSignal(qfilename.toStdString());
}

/* Closes the game */
void GameWindow::on_actionEnd_triggered(){
	QMessageBox msgBox;
	msgBox.setText("Papa :)");
	msgBox.exec();

    QCoreApplication::quit();
}
