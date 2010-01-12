/**
  @file TicTacToeGameController.cpp
  @author Hanna Dutkiewicz
*/

#include <QThread>
#include <qtconcurrentrun.h>
#include <QFutureWatcher>

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../game-strategy-library/AbstractGameFactory.hpp"
#include "../game-strategy-library/Node.hpp"
#include "../game-strategy-library/Player.hpp"
#include "../game-strategy-library/Game.hpp"
#include "../game-strategy-library/UnknownGameException.hpp"
#include "../game-strategy-library/GameNotStartedException.hpp"
#include "../game-strategy-library/NoMoveAvailableException.hpp"
#include "../game-strategy-library/InvalidMoveException.hpp"

#include "TicTacToeGameController.hpp"
#include "TicTacToeGameFactory.hpp"
#include "gamewindow.hpp"
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

	srand(time(NULL));

	QGraphicsScene * scenePtr = new QGraphicsScene();

	boost::shared_ptr<QGraphicsScene> graphScene = boost::shared_ptr<QGraphicsScene>(scenePtr);
	
	gameWindow_.setGraphicsScene(graphScene);
	gameBoard_.setGraphicsScene(graphScene);

	//gameBoard_.init();

	TicTacToeGameFactory * factory = new TicTacToeGameFactory;
	factory_ = boost::shared_ptr<AbstractGameFactory>( static_cast<AbstractGameFactory *>(factory) );
	gameStrategy_.initialize(factory_);

	// connect all signals and slots between GameWindow and controller

	connect(&gameWindow_,	SIGNAL(createFirstGameNewPlayerSignal(TicTacToePlayer::PlayerSign, TicTacToePlayer::PlayerLevel)), 
			this,			SLOT(createFirstGameNewPlayerSlot(TicTacToePlayer::PlayerSign, TicTacToePlayer::PlayerLevel)) );

	connect(&gameWindow_,	SIGNAL(createFirstGameLoadPlayerSignal(TicTacToePlayer::PlayerSign, std::string )), 
			this,			SLOT(createFirstGameLoadPlayerSlot(TicTacToePlayer::PlayerSign, std::string )) );

	connect(&gameWindow_,	SIGNAL(createNewGameSignal()), 
			this,			SLOT(createNewGameSlot()) );

	connect(&gameWindow_,	SIGNAL(saveGameSignal(std::string) ), 
			this,			SLOT(saveGameSlot(std::string)) );

	connect(&gameWindow_,	SIGNAL(loadGameSignal(std::string)), 
			this,			SLOT(loadGameSlot(std::string) ) );

	connect(&gameWindow_,	SIGNAL(changeSignSignal(TicTacToePlayer::PlayerSign)), 
			this,			SLOT(changeSignSlot(TicTacToePlayer::PlayerSign) ) );


	// connect with GameBoard
	connect(&gameBoard_,	SIGNAL(playerMadeAmoveSignal(std::pair<int,int>)), 
			this,			SLOT(playerMadeAmoveSlot(std::pair<int,int>)) );

}


/************** SLOTS ********************/
void TicTacToeGameController::saveGameSlot(std::string filename){

}

void TicTacToeGameController::loadGameSlot(std::string filename){

}


void TicTacToeGameController::createFirstGameNewPlayerSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel){
	gameBoard_.init();

	computerPlayerLevel_ = computerPlayerLevel;
	
	// make GUI elements wait
	gameBoard_.wait();
	gameWindow_.wait();

	//bind appropriate method to a new thread creating a game and possibly training
	if(computerPlayerLevel != TicTacToePlayer::BEGINNER){
		QFuture<boost::shared_ptr<library::Game> > f = run(boost::bind(&TicTacToeGameController::toBindCreateGameAndTrain, this));
		watcher_.setFuture(f);
		connect(&watcher_, SIGNAL(finished()), this, SLOT(startNewGame()));
	} else{
		QFuture<boost::shared_ptr<library::Game> > f = run(boost::bind(&TicTacToeGameController::toBindOnlyCreateGame, this));
		watcher_.setFuture(f);
		connect(&watcher_, SIGNAL(finished()), this, SLOT(startNewGame()));
	}

	// create players
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


boost::shared_ptr<library::Game> TicTacToeGameController::toBindOnlyCreateGame(){
	TicTacToeGameFactory * tttFactory = static_cast<TicTacToeGameFactory *>( factory_.get() );
	boost::shared_ptr<library::Game> game = tttFactory->create();
	return game;
}


boost::shared_ptr<library::Game> TicTacToeGameController::toBindCreateGameAndTrain(){
	TicTacToeGameFactory * tttFactory = static_cast<TicTacToeGameFactory *>( factory_.get() );
	boost::shared_ptr<library::Game> game = tttFactory->create();
	return trainComputerPlayer(game);
}


void TicTacToeGameController::createNewGameSlot(){

	gameBoard_.startNewGame();

	try{
		gameStrategy_.startGame();
	} catch(UnknownGameException ex){
		std::cerr<<ex.toString();
		exit(1);
	}

	if(playerComp_->isStartingPlayer()){
		makeComputerMove();
	}
}

void TicTacToeGameController::startNewGame(){
	// thread was finished, there should be a result - a new game
	boost::shared_ptr<library::Game> game = watcher_.result();

	gameStrategy_.startGame(game, playerHuman_, playerComp_);
	gameBoard_.startNewGame();

	gameBoard_.stopWaiting();
	gameWindow_.stopWaiting();

	// make first move
	if(playerComp_->isStartingPlayer()){
		makeComputerMove();
	}
}


void TicTacToeGameController::createFirstGameLoadPlayerSlot
(TicTacToePlayer::PlayerSign humanPlayerSign, std::string computerPlayerFilename){
	//gameBoard_.init();

}


void TicTacToeGameController::playerMadeAmoveSlot(std::pair<int,int> move){
	
	std::list<boost::shared_ptr<Move> > allMoves = gameStrategy_.getAvailableMoves();
	std::list<boost::shared_ptr<Move> >::const_iterator it = allMoves.begin();

    while(it != allMoves.end()){
        TicTacToeMove * tttmove = static_cast<TicTacToeMove *> ((*it).get());
		if(tttmove->getCoordinates() == move){
			try{
				gameStrategy_.move(*it);
				break;
			} catch(GameNotStartedException ex){
				std::cerr << ex.toString();
				exit(1);
			} catch(InvalidMoveException ex2){
				std::cerr << ex2.toString();
				exit(1);
			}
		}
        ++it;
    }

	if(!checkEndGame(move, playerHuman_, gameBoard_, true)){
		makeComputerMove();
	}
}


void TicTacToeGameController::changeSignSlot(TicTacToePlayer::PlayerSign humanPlayerSign){

	TicTacToePlayer * player = static_cast<TicTacToePlayer *>(playerHuman_.get());
	player->setPlayerSign(humanPlayerSign);

	player = static_cast<TicTacToePlayer *>(playerComp_.get());
	player->setPlayerSign(humanPlayerSign == TicTacToePlayer::CIRCLE ? TicTacToePlayer::CROSS : TicTacToePlayer::CIRCLE );
}

/**************** PRIVATE METHODS *******************/
void TicTacToeGameController::makeComputerMove(){

	try{
		boost::shared_ptr<Move> move = gameStrategy_.findBestMove();
		gameStrategy_.move(move);
		TicTacToeMove * tttmove = static_cast<TicTacToeMove *> (move.get());
		checkEndGame(tttmove->getCoordinates(), playerComp_, gameBoard_, true);

	} catch(GameNotStartedException ex){
		std::cerr << ex.toString();
		exit(1);
	} catch(InvalidMoveException ex2){
		std::cerr << ex2.toString();
		exit(1);
	} catch(NoMoveAvailableException ex3){
		std::cerr << ex3.toString();
		exit(1);
	}

}

// return true if finished
bool TicTacToeGameController::checkEndGame
(std::pair<int,int> coordinates, boost::shared_ptr<Player> player, BaseGameBoard & board, bool notifyWindow){
	
	TicTacToePlayer * tttplayer = static_cast<TicTacToePlayer *> (player.get());
	GameBoard::GameBoardState gameState = board.makeAmove(coordinates, tttplayer->getPlayerSign());

	if(gameState == GameBoard::GAME_DURING_PLAY)
		return false;
	
	if(gameState == GameBoard::GAME_FINISH_REMIS){
		try{
			gameStrategy_.endOfGame();
		} catch(GameNotStartedException ex){
			std::cerr << ex.toString();
			return false;
		}
		board.endGame();
		if(notifyWindow)
			gameWindow_.endGame();
	}
	else{
		try{
			gameStrategy_.endOfGame(player);
		} catch(GameNotStartedException ex){
			std::cerr << ex.toString();
			return false;
		}
		board.endGame(tttplayer->getPlayerType());
		if(notifyWindow)
			gameWindow_.endGame(tttplayer->getPlayerType());
	}

	return true;
}

boost::shared_ptr<Game> TicTacToeGameController::trainComputerPlayer(boost::shared_ptr<Game> game){

	TicTacToePlayer * dummyPlayer1 = new TicTacToePlayer;
	dummyPlayer1->setName("1");
	dummyPlayer1->setPlayerSign(TicTacToePlayer::CIRCLE);
	boost::shared_ptr<Player> player1ptr = boost::shared_ptr<Player>(dummyPlayer1);

	TicTacToePlayer * dummyPlayer2 = new TicTacToePlayer;
	dummyPlayer2->setName("2");
	dummyPlayer2->setPlayerSign(TicTacToePlayer::CROSS);
	boost::shared_ptr<Player> player2ptr = boost::shared_ptr<Player>(dummyPlayer2);

	BaseGameBoard board;
	board.init();
	
	board.startNewGame();
	gameStrategy_.startGame(game, player1ptr, player2ptr);

	TicTacToeMove * tttmove;

	int max = (computerPlayerLevel_ == TicTacToePlayer::INTERMEDIATE) ? NODES_MEDIUM : NODES_ADVANCED;

	while(true){

		// player1 move
		boost::shared_ptr<Move> move = getRandMove();

		try{
			gameStrategy_.move(move);
			tttmove = static_cast<TicTacToeMove *> (move.get());
		
			// check if player1 won
			if(!checkEndGame(tttmove->getCoordinates(), player1ptr, board, false)){

				// if not player2 makes a move
				boost::shared_ptr<Move> move = getRandMove();
				gameStrategy_.move(move);
				tttmove = static_cast<TicTacToeMove *> (move.get());

				// if game is finished start a new one or break
				if(!checkEndGame(tttmove->getCoordinates(), player2ptr, board, false))
					continue;
				
					// game finished, start a new game
				if(game->getNumberOfVisitedLeafs() >= max)
					break;
				board.startNewGame();
				gameStrategy_.startGame();
			} else{
				if(game->getNumberOfVisitedLeafs() >= max)
					break;
				board.startNewGame();
				gameStrategy_.startGame();
			}


		}catch(GameNotStartedException ex){
			std::cerr << ex.toString();
			exit(1);
		} catch(InvalidMoveException ex2){
			std::cerr << ex2.toString();
			exit(1);
		} catch(UnknownGameException ex){
			std::cerr << ex.toString();
			exit(1);
		}
	}
			/*
			if(checkEndGame(tttmove->getCoordinates(), player2ptr, board, false)){
				// game finished, start a new game
				if(game->getNumberOfVisitedLeafs() >= 300000)
					break;
				board.startNewGame();
				gameStrategy_.startGame();
			}
		} else{
			if(game->getNumberOfVisitedLeafs() >= 300000)
				break;
			board.startNewGame();
			gameStrategy_.startGame();
		}*/
	return game;
}

boost::shared_ptr<library::Move> TicTacToeGameController::getRandMove(){

	try{
		std::list<boost::shared_ptr<Move> > allMoves = gameStrategy_.getAvailableMoves();
		int r = rand() % (allMoves.size());

		std::list<boost::shared_ptr<Move> >::const_iterator it = allMoves.begin();

		for(int i = 0; i < r; ++i)
			++it;
		return *it;

	}catch(GameNotStartedException ex){
		std::cerr << ex.toString();
		exit(1);
	}
}
