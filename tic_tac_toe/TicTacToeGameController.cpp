/**
  @file TicTacToeGameController.cpp
  @author Hanna Dutkiewicz
*/

#include <boost/shared_ptr.hpp>

#include "..\game-strategy-library\AbstractGameFactory.hpp"
#include "TicTacToeGameController.hpp"
#include "GameWindow.hpp"

using namespace library;


TicTacToeGameController::TicTacToeGameController(GameWindow& gameWindow): QObject(NULL), gameWindow_(gameWindow){
	
}

void TicTacToeGameController::initialize(){

	QGraphicsScene * scenePtr = new QGraphicsScene(/*gameWindow.get()*/);

	boost::shared_ptr<QGraphicsScene> graphScene = boost::shared_ptr<QGraphicsScene>(scenePtr);
	
	gameWindow_.setGraphicsScene(graphScene);
	gameBoard_.setGraphicsScene(graphScene);

	TicTacToeGameFactory * factory = new TicTacToeGameFactory;
	boost::shared_ptr<AbstractGameFactory> factoryPtr = 
		boost::shared_ptr<AbstractGameFactory>( dynamic_cast<AbstractGameFactory *>(factory) );
	gameStrategy_.initialize(factoryPtr);


	// connect all signals and slots between GameWindow and controller
	connect(&gameWindow_,	SIGNAL(crateNewOponentSignal(TicTacToePlayer::PlayerLevel)), 
			this,			SLOT(crateNewOponentSlot(TicTacToePlayer::PlayerLevel)) );

	connect(&gameWindow_,	SIGNAL(createFirstGameNewPlayerSignal(TicTacToePlayer::PlayerSign, TicTacToePlayer::PlayerLevel)), 
			this,			SLOT(createFirstGameNewPlayerSlot(TicTacToePlayer::PlayerSign, TicTacToePlayer::PlayerLevel)) );

	connect(&gameWindow_,	SIGNAL(createFirstGameLoadPlayerSignal(TicTacToePlayer::PlayerSign, std::string & )), 
			this,			SLOT(createFirstGameLoadPlayerSlot(TicTacToePlayer::PlayerSign, std::string & )) );

	connect(&gameWindow_,	SIGNAL(createNewGameSignal()), 
			this,			SLOT(createNewGameSlot()) );

	connect(&gameWindow_,	SIGNAL(saveGameSignal()), 
			this,			SLOT(saveGameSlot()) );

	connect(&gameWindow_,	SIGNAL(loadGameSignal(std::string &)), 
			this,			SLOT(loadGameSlot(std::string &) ) );


	// connect with GameBoard
	connect(&gameBoard_,	SIGNAL(playerMadeAmoveSignal(std::pair<int,int>)), 
			this,			SLOT(playerMadeAmoveSlot(std::pair<int,int>)) );
}

void TicTacToeGameController::crateNewOponentSlot(TicTacToePlayer::PlayerLevel level){

}

void TicTacToeGameController::saveGameSlot(){

}

void TicTacToeGameController::loadGameSlot(std::string & filename){

}

void TicTacToeGameController::createNewGameSlot(){
	gameBoard_.startNewGame();

}

void TicTacToeGameController::createFirstGameNewPlayerSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel){

}

void TicTacToeGameController::createFirstGameLoadPlayerSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, std::string & computerPlayerFilename){

}

void TicTacToeGameController::playerMadeAmoveSlot(std::pair<int,int> move){

}
