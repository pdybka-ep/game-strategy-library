/**
    @file   BaseGameBoard.hpp
    @author Hanna Dutkiewicz
*/

#ifndef BASEGAMEBOARD_H
#define BASEGAMEBOARD_H

#include <iostream>

#include <boost/numeric/ublas/matrix.hpp>

#include "BaseField.hpp"
#include "TicTacToePlayer.hpp"

/**
	@class BaseGameBoard
	@author Hanna Dutkiewicz
	Class of a simple game board of a TicTacToe game
*/
class BaseGameBoard{

public:
	/**
		State of a game board
	*/
	enum GameBoardState {
		/** Game isn't started yet */
		GAME_NOT_STARTED, 
		/** Game is during a play */
		GAME_DURING_PLAY, 
		/** Game is finished, there is a winner */
		GAME_FINISH_WINNER, 
		/** Game is finished, there is no winner */
		GAME_FINISH_REMIS};

	/**
		Default constructor
	*/
	BaseGameBoard();
	
	/**
		Virtual destructor
	*/
	virtual ~BaseGameBoard();

	/**
		Virtual function for starting a new game
	*/
	virtual void startNewGame();
	
	/**
		Virtual method for initializing a game board
	*/
	virtual void init();
	
	//virtual void startFirstGame();

	/**
		Virtual method to indicate that a game was finished without a winner
	*/
	virtual void endGame();
	
	/**
		Virtual method to indicate that a game was finished with a specific winner type
		@param type of a winner (type of TicTacToePlayer::PlayerType)
	*/
	virtual void endGame(TicTacToePlayer::PlayerType type);

	/**
		Makes a move on a board o specific coordinates
		@param coordinates coordinates od a field where move was made
		@param sign sign of a player that made this move
		@return state of the board after making this move
	*/
	GameBoardState makeAmove(std::pair<int,int> coordinates, TicTacToePlayer::PlayerSign sign);

protected:
	/** State of the board */
	GameBoardState boardState_;

	/** Matrix of fields on a board */
	boost::numeric::ublas::matrix<BaseField *> field_;

	/** Maximum fields in a row of a game board */
	static const int MAX_IN_A_ROW = 3;

};

#endif 