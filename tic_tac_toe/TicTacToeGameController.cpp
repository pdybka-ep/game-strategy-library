/**
  @file TicTacToeGameController.cpp
  @author Hanna Dutkiewicz
*/

#include <boost/shared_ptr.hpp>
#include "TicTacToeGameController.hpp"
#include "GameWindow.hpp"

TicTacToeGameController::TicTacToeGameController(GameWindow& gameWindow): gameWindow_(gameWindow){
	
}

void TicTacToeGameController::initialize(){

	QGraphicsScene * scenePtr = new QGraphicsScene(/*gameWindow.get()*/);

	boost::shared_ptr<QGraphicsScene> graphScene = boost::shared_ptr<QGraphicsScene>(scenePtr);
	
	gameWindow_.setGraphicsScene(graphScene);
	gameBoard_.setGraphicsScene(graphScene);
}

void TicTacToeGameController::crateNewOponentSlot(TicTacToePlayer::PlayerLevel level){

}

void TicTacToeGameController::saveGameSlot(std::string & filename){

}

void TicTacToeGameController::loadGameSlot(std::string & filename){

}

void TicTacToeGameController::createNewGameSlot(){

}

void TicTacToeGameController::createFirstGameNewPlayerSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel){

}

void TicTacToeGameController::createFirstGameLoadPlayerSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, std::string & computerPlayerFilename){

}

void TicTacToeGameController::playerMadeAmoveSlot(TicTacToeMove m){

}
