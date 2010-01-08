/**
  @file TicTacToeGameController.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEGAMECONTROLLER_H
#define TICTACTOEGAMECONTROLLER_H


#include <boost/shared_ptr.hpp>
#include "..\game-strategy-library\GameStrategy.hpp"
#include "TicTacToeGameFactory.hpp"
#include "GameWindow.hpp"
#include "TicTacToePlayer.hpp"
#include "GameBoard.hpp"
#include "TicTacToeMove.hpp"


/**
	@class GameController
	Game controller (in MVC model), a singleton.
	@uthor Hanna Dutkiewicz
*/
class TicTacToeGameController{

public:
	TicTacToeGameController(GameWindow &gameWindow_);

	~TicTacToeGameController(){}

	void initialize();

public slots:

	void crateNewOponentSlot(TicTacToePlayer::PlayerLevel level);

	void saveGameSlot(std::string & filename);

	void loadGameSlot(std::string & filename);

	void createNewGameSlot();

	void createFirstGameNewPlayerSlot
		(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel);

	void createFirstGameLoadPlayerSlot
		(TicTacToePlayer::PlayerSign humanPlayerSign, std::string & computerPlayerFilename);

	void playerMadeAmoveSlot(TicTacToeMove m);


private:
	//TicTacToeGameController(){}
	//TicTacToeGameController(const TicTacToeGameController &){}

	// model
	library::GameStrategy gameStrategy_;

	// view
	GameWindow &gameWindow_;

	// game elements
	GameBoard gameBoard_;
	TicTacToePlayer player1_;
	TicTacToePlayer player2_;
};


#endif /* TICTACTOEGAMECONTROLLER_H */