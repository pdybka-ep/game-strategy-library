/**
    @file   gamewindow.cpp
    @author Hanna Dutkiewicz
*/

#include <QImage>
#include <QBrush>
#include <QGraphicsScene>
#include <QFileDialog>

#include <boost/shared_ptr.hpp>

#include "gamewindow.hpp"
#include "ui_gamewindow.h"
#include "TicTacToeGameController.hpp"
#include "TicTacToePlayer.hpp"
#include "optionsdialog.hpp"
#include "SignDialog.hpp"


/* A constructor of GameWindow - the main window of a game. */
GameWindow::GameWindow(QWidget *parent): QMainWindow(parent), ui_(new Ui::GameWindow), humanPlayerSign_(TicTacToePlayer::CIRCLE){
    ui_->setupUi(this);
}

/* A destructor. */
GameWindow::~GameWindow(){

}

void GameWindow::setGraphicsScene(boost::shared_ptr<QGraphicsScene> graphScene){
	ui_->graphicsView->setScene(graphScene.get());
	scene_ = graphScene;
}

void GameWindow::endGame(){
	ui_->newGameButton->setEnabled(true);
	ui_->actionTotalNewGame->setEnabled(true);
	ui_->actionNewGame->setEnabled(true);
	ui_->actionChangeSign->setEnabled(true);
}

void GameWindow::endGame(TicTacToePlayer::PlayerType winner){
	ui_->newGameButton->setEnabled(true);
	ui_->actionNewGame->setEnabled(true);
	ui_->actionTotalNewGame->setEnabled(true);
	ui_->actionChangeSign->setEnabled(true);

	if(winner == TicTacToePlayer::COMPUTER)
		ui_->OponentPointsLcd->display( ui_->OponentPointsLcd->intValue()+1 );
	else
		ui_->playerPointsLcd->display( ui_->playerPointsLcd->intValue()+1 );
}


void GameWindow::wait(){
	ui_->exitButton->setEnabled(false);
	ui_->actionEnd->setEnabled(false);
	ui_->newGameButton->setEnabled(false);
	ui_->actionNewGame->setEnabled(false);
	ui_->actionTotalNewGame->setEnabled(false);
	ui_->actionLoad->setEnabled(false);
	ui_->actionSave->setEnabled(false);
	ui_->actionChangeSign->setEnabled(false);
}

void GameWindow::stopWaiting(){
	ui_->exitButton->setEnabled(true);
	ui_->actionEnd->setEnabled(true);
	ui_->newGameButton->setEnabled(true);
	ui_->actionNewGame->setEnabled(true);
	ui_->actionTotalNewGame->setEnabled(true);
	ui_->actionLoad->setEnabled(true);
	ui_->actionSave->setEnabled(true);
	//
}

/* Sets all the parametres before game is started. */
void GameWindow::okClickedSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel, QString filename){

	ui_->actionSave->setEnabled(true);

	humanPlayerSign_ = humanPlayerSign;
	computerPlayerLevel_ = computerPlayerLevel;

    init();
	
	// set oponent's level and player's sign on the window
	ui_->playerSignLabel->setText(humanPlayerSign == TicTacToePlayer::CIRCLE ? " KOLKO " : " KRZYZYK ");

	QString level = (computerPlayerLevel == TicTacToePlayer::BEGINNER) ? " Poczatkujacy" : ( (computerPlayerLevel == TicTacToePlayer::ADVANCED) ? " Zaawansowany " : "Sredni");
	ui_->oponentLevelLabel->setText(level);

	ui_->playerPointsLcd->display(0);
	ui_->OponentPointsLcd->display(0);

	// generate signal to GameController to start a new game
	if(filename.isEmpty()){
		createFirstGameNewPlayerSignal(humanPlayerSign, computerPlayerLevel);
	}
	else{
		createFirstGameLoadPlayerSignal(humanPlayerSign, filename.toStdString());
	}
}


void GameWindow::init(){
	 int x, y, w, h;
    ui_->graphicsView->rect().getRect(&x, &y, &w, &h);
	scene_->setSceneRect(QRect(x, y, w-2, h-2));
}

void GameWindow::changeSignSlot(TicTacToePlayer::PlayerSign sign){
	humanPlayerSign_ = sign;
	ui_->playerSignLabel->setText(humanPlayerSign_ == TicTacToePlayer::CIRCLE ? " KOLKO " : " KRZYZYK ");
	changeSignSignal(sign);
}


/*************** MENU items reactions ****************/
/* Starts a new game. */
void GameWindow::on_actionNewGame_triggered(){
	ui_->actionSave->setEnabled(true);

	ui_->newGameButton->setEnabled(false);
	ui_->actionNewGame->setEnabled(false);
	ui_->actionTotalNewGame->setEnabled(false);
	ui_->actionChangeSign->setEnabled(false);

	createNewGameSignal();
}

void GameWindow::on_actionTotalNewGame_triggered(){
	OptionsDialog dialog(this);
	dialog.exec();
}


/* Saves current state of game (to be specific: the wisdom of an oponent). */
void GameWindow::on_actionSave_triggered(){
	std::string text = "Game Files (*";

	std::string extend = (computerPlayerLevel_ == TicTacToePlayer::BEGINNER) ? ".beg" : ( (computerPlayerLevel_ == TicTacToePlayer::ADVANCED) ? ".adv" : ".int");

	text.append(extend);
	text.append(")");

	QString qfilename = QFileDialog::getSaveFileName(this, tr("Save"), "/", tr(text.c_str()));

	if(qfilename.isEmpty())
		return;

	if(!qfilename.contains(".")){
		qfilename.append(QString(extend.c_str()));
	}

	saveGameSignal(qfilename.toStdString());
}

/* Loads state of game (to be specific: the wisdom of an oponent). */
void GameWindow::on_actionLoad_triggered(){
	QString filename = QFileDialog::getOpenFileName(this, tr("Open"), "/", tr("Game Files (*.beg *.int *.adv)"));

	if(filename.endsWith(".beg")){
		ui_->oponentLevelLabel->setText("Poczatkujacy");
		computerPlayerLevel_ = TicTacToePlayer::BEGINNER;
	} 
	else if(filename.endsWith(".int")){
		ui_->oponentLevelLabel->setText("Sredni");
		computerPlayerLevel_ = TicTacToePlayer::INTERMEDIATE;
	} 
	else if(filename.endsWith(".adv")){
		ui_->oponentLevelLabel->setText("Zaawansowany");
		computerPlayerLevel_ = TicTacToePlayer::ADVANCED;
	}

	ui_->playerPointsLcd->display(0);
	ui_->OponentPointsLcd->display(0);

	createFirstGameLoadPlayerSignal(humanPlayerSign_, filename.toStdString());

}

/* Closes the game */
void GameWindow::on_actionEnd_triggered(){
    QCoreApplication::quit();
}

void GameWindow::on_actionChangeSign_triggered(){
	SignDialog dialog(this, humanPlayerSign_);
	dialog.exec();
}

void GameWindow::setPercLabel(double percentage){
	ui_->lcdNumberPerc->display(percentage);
}