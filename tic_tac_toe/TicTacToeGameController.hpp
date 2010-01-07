/**
  @file TicTacToeGameController.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEGAMECONTROLLER_H
#define TICTACTOEGAMECONTROLLER_H

#include "..\game-strategy-library\GameStrategy.hpp"
#include "TicTacToeGameFactory.hpp"
#include "GameWindow.hpp"
#include "TicTacToePlayer.hpp"
#include "GameBoard.hpp"


/**
	@class GameController
	Game controller (in MVC model), a singleton.
	@uthor Hanna Dutkiewicz
*/
class TicTacToeGameController{

public:
	static TicTacToeGameController & getInstance(){
		static TicTacToeGameController instance;
		return instance;
	};

	~TicTacToeGameController(){}

	void initialize(GameWindow & gameWindow);

private:
	TicTacToeGameController(){}
	TicTacToeGameController(const TicTacToeGameController &){}


	
	// model
	library::GameStrategy gameStrategy_;

	// view
	GameWindow gameWindow_;

	// game elements
	GameBoard gameBoard_;
	TicTacToePlayer player1_;
	TicTacToePlayer player2_;
};


#endif /* TICTACTOEGAMECONTROLLER_H */