/**
  @file TicTacToeGameController.cpp
  @author Hanna Dutkiewicz
*/

#include <boost/shared_ptr.hpp>
#include <QThread>
#include <qtconcurrentrun.h>
#include <boost/bind.hpp>
#include <QFutureWatcher>

#include "..\game-strategy-library\AbstractGameFactory.hpp"
#include "..\game-strategy-library\Node.hpp"

#include "TicTacToeGameController.hpp"
#include "TicTacToeGameFactory.hpp"
#include "GameWindow.hpp"


using namespace library;
using namespace QtConcurrent;


TicTacToeGameController::TicTacToeGameController(GameWindow& gameWindow): 
QObject(NULL), gameWindow_(gameWindow){
	
}

TicTacToeGameController::~TicTacToeGameController(){
	if(watcher_.isRunning()){
		watcher_.cancel();
	}
}

void TicTacToeGameController::initialize(){

	QGraphicsScene * scenePtr = new QGraphicsScene(/*gameWindow.get()*/);

	boost::shared_ptr<QGraphicsScene> graphScene = boost::shared_ptr<QGraphicsScene>(scenePtr);
	
	gameWindow_.setGraphicsScene(graphScene);
	gameBoard_.setGraphicsScene(graphScene);

	TicTacToeGameFactory * factory = new TicTacToeGameFactory;
	factory_ = boost::shared_ptr<TicTacToeGameFactory>(factory);

	boost::shared_ptr<AbstractGameFactory> factoryPtr = 
		boost::shared_ptr<AbstractGameFactory>( static_cast<AbstractGameFactory *>(factory) );
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

/************** SLOTS ********************/
void TicTacToeGameController::crateNewOponentSlot(TicTacToePlayer::PlayerLevel level){
	
}

void TicTacToeGameController::saveGameSlot(){

}

void TicTacToeGameController::loadGameSlot(std::string & filename){

}

void TicTacToeGameController::createNewGameSlot(){
	gameBoard_.startNewGame();
	gameStrategy_.startGame();

	if(playerComp_->isStartingPlayer()){
		makeComputerMove();
	}
}


void TicTacToeGameController::gameOponentCreatedSlot(){
	boost::shared_ptr<Game> game = watcher_.result();

	gameStrategy_.startGame(game, playerHuman_, playerComp_);
	gameBoard_.stopWaiting();
	gameBoard_.startFirstGame();

	// make first move
	if(playerComp_->isStartingPlayer()){
		makeComputerMove();
	}
}

void TicTacToeGameController::createFirstGameNewPlayerSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel){

	QFuture<boost::shared_ptr<Game> > f = run(boost::bind(&TicTacToeGameFactory::create, factory_));
	//QFutureWatcher<boost::shared_ptr<Game> > watcher;
	watcher_.setFuture(f);
	connect(&watcher_, SIGNAL(finished()), this, SLOT(gameOponentCreatedSlot()));
	gameBoard_.wait();


	TicTacToePlayer * playerH = new TicTacToePlayer;
	playerH->setName("human");
	playerH->setPlayerSign(humanPlayerSign);
	playerH->setPlayerType(TicTacToePlayer::HUMAN);
	
	TicTacToePlayer * playerC = new TicTacToePlayer;
	playerC->setName("comp");
	playerC->setPlayerSign(humanPlayerSign == TicTacToePlayer::CIRCLE ? TicTacToePlayer::CROSS : TicTacToePlayer::CIRCLE);
	playerC->setPlayerType(TicTacToePlayer::COMPUTER);

	playerHuman_ = boost::shared_ptr<Player>(playerH);
	playerComp_ = boost::shared_ptr<Player>(playerC);
}

void TicTacToeGameController::createFirstGameLoadPlayerSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, std::string & computerPlayerFilename){

}

void TicTacToeGameController::playerMadeAmoveSlot(std::pair<int,int> move){
	
	std::list<boost::shared_ptr<Move> > allMoves = gameStrategy_.getCurrentGameState().getCurrentNode()->getAvailableMoves();
	std::list<boost::shared_ptr<Move> >::const_iterator it = allMoves.begin();

    while(it != allMoves.end()){
        TicTacToeMove * tttmove = static_cast<TicTacToeMove *> ((*it).get());
		if(tttmove->getCoordinates() == move){
			gameStrategy_.move(*it);
			break;
		}
        ++it;
    }

	if(!checkEndGame(move, playerHuman_)){
		makeComputerMove();
	}
}

/**************** PRIVATE METHODS *******************/

void TicTacToeGameController::makeComputerMove(){

	boost::shared_ptr<Move> move = gameStrategy_.findBestMove();
	gameStrategy_.move(move);

	TicTacToeMove * tttmove = static_cast<TicTacToeMove *> (move.get());
	checkEndGame(tttmove->getCoordinates(), playerComp_);
}

// return true if finished
bool TicTacToeGameController::checkEndGame(std::pair<int,int> coordinates, boost::shared_ptr<Player> player){
	
	TicTacToePlayer * tttplayer = static_cast<TicTacToePlayer *> (player.get());
	GameBoard::GameBoardState gameState = gameBoard_.makeAmove(coordinates, tttplayer->getPlayerSign());

	if(gameState == GameBoard::GAME_DURING_PLAY)
		return false;
	
	if(gameState == GameBoard::GAME_FINISH_REMIS){
		gameStrategy_.endOfGame();
		gameBoard_.endGame();
		gameWindow_.endGame();
	}
	else{
		gameStrategy_.endOfGame(player);
		gameBoard_.endGame(tttplayer->getPlayerType());
		gameWindow_.endGame(tttplayer->getPlayerType());
	}

	return true;
}
