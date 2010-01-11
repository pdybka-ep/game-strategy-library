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
#include "..\game-strategy-library\Player.hpp"
#include "..\game-strategy-library\Game.hpp"

#include "TicTacToeGameController.hpp"
#include "TicTacToeGameFactory.hpp"
#include "GameWindow.hpp"
#include "BaseGameBoard.hpp"


using namespace library;
using namespace QtConcurrent;


TicTacToeGameController::TicTacToeGameController(GameWindow& gameWindow): 
QObject(NULL), gameWindow_(gameWindow), computerPlayerLevel_(TicTacToePlayer::BEGINNER){
	
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
	//factory_ = boost::shared_ptr<TicTacToeGameFactory>(factory);

	//boost::shared_ptr<AbstractGameFactory> 
	factory_ = boost::shared_ptr<AbstractGameFactory>( static_cast<AbstractGameFactory *>(factory) );
	gameStrategy_.initialize(factory_);


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

	// check computer player level and teach him if it's necessary
	if(computerPlayerLevel_ != TicTacToePlayer::BEGINNER){
		trainComputerPlayer(game);
	}

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

	computerPlayerLevel_ = computerPlayerLevel;

	TicTacToeGameFactory * tttFactory = static_cast<TicTacToeGameFactory *>( factory_.get() );
	QFuture<boost::shared_ptr<Game> > f = run(boost::bind(&TicTacToeGameFactory::create, tttFactory));
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

	if(!checkEndGame(move, playerHuman_, gameBoard_)){
		makeComputerMove();
	}
}

/**************** PRIVATE METHODS *******************/

void TicTacToeGameController::makeComputerMove(){

	boost::shared_ptr<Move> move = gameStrategy_.findBestMove();
	gameStrategy_.move(move);

	TicTacToeMove * tttmove = static_cast<TicTacToeMove *> (move.get());
	checkEndGame(tttmove->getCoordinates(), playerComp_, gameBoard_);
}

// return true if finished
bool TicTacToeGameController::checkEndGame
(std::pair<int,int> coordinates, boost::shared_ptr<Player> player, BaseGameBoard & board, bool notifyWindow){
	
	TicTacToePlayer * tttplayer = static_cast<TicTacToePlayer *> (player.get());
	//GameBoard::GameBoardState gameState = gameBoard_.makeAmove(coordinates, tttplayer->getPlayerSign());
	GameBoard::GameBoardState gameState = board.makeAmove(coordinates, tttplayer->getPlayerSign());

	if(gameState == GameBoard::GAME_DURING_PLAY)
		return false;
	
	if(gameState == GameBoard::GAME_FINISH_REMIS){
		gameStrategy_.endOfGame();
		//gameBoard_.endGame();
		board.endGame();
		if(notifyWindow)	
			gameWindow_.endGame();
	}
	else{
		gameStrategy_.endOfGame(player);
		//gameBoard_.endGame(tttplayer->getPlayerType());
		board.endGame(tttplayer->getPlayerType());
		if(notifyWindow)
			gameWindow_.endGame(tttplayer->getPlayerType());
	}

	return true;
}

void TicTacToeGameController::trainComputerPlayer(boost::shared_ptr<Game> game){

	TicTacToePlayer * dummyPlayer1 = new TicTacToePlayer;
	dummyPlayer1->setName("1");
	dummyPlayer1->setPlayerSign(TicTacToePlayer::CIRCLE);
	boost::shared_ptr<Player> player1ptr = boost::shared_ptr<Player>(dummyPlayer1);

	TicTacToePlayer * dummyPlayer2 = new TicTacToePlayer;
	dummyPlayer2->setName("2");
	dummyPlayer2->setPlayerSign(TicTacToePlayer::CROSS);
	boost::shared_ptr<Player> player2ptr = boost::shared_ptr<Player>(dummyPlayer2);

	BaseGameBoard board;

	board.startFirstGame();
	gameStrategy_.startGame(game, player1ptr, player2ptr);

	boost::shared_ptr<Move> move;
	TicTacToeMove * tttmove;

	while(game->getNumberOfVisitedLeafs() < 2000){

		// player1 move
		move = gameStrategy_.findBestMove();
		gameStrategy_.move(move);
		tttmove = static_cast<TicTacToeMove *> (move.get());
		
		// check if player1 won
		if(!checkEndGame(tttmove->getCoordinates(), player1ptr, board, false)){
			
			// if not player2 makes a move
			move = gameStrategy_.findBestMove();
			gameStrategy_.move(move);
			tttmove = static_cast<TicTacToeMove *> (move.get());

			// if game is finished start a new one or break
			if(checkEndGame(tttmove->getCoordinates(), player2ptr, board, false)){
				// game finished, start a new game
				if(game->getNumberOfVisitedLeafs() >= 2000)
					break;
				board.startNewGame();
				gameStrategy_.startGame();
			}
		}
			
	}

}