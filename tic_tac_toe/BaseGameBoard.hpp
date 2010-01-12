/**
    @file   field.hpp
    @author Hanna Dutkiewicz
*/

#ifndef BASEGAMEBOARD_H
#define BASEGAMEBOARD_H

#include <iostream>
#include <boost\numeric\ublas\matrix.hpp>

#include "BaseField.hpp"
#include "TicTacToePlayer.hpp"

class BaseGameBoard{

public:
	enum GameBoardState {GAME_NOT_STARTED, GAME_DURING_PLAY, GAME_FINISH_WINNER, GAME_FINISH_REMIS};

	BaseGameBoard();
	virtual ~BaseGameBoard();

	virtual void startNewGame();
	virtual void init();
	
	//virtual void startFirstGame();

	virtual void endGame();
	virtual void endGame(TicTacToePlayer::PlayerType );

	GameBoardState makeAmove(std::pair<int,int> coordinates, TicTacToePlayer::PlayerSign sign);

protected:
	GameBoardState boardState_;

	boost::numeric::ublas::matrix<BaseField *> field_;

	/** Maximum fields in a row of a game board */
	static const int MAX_IN_A_ROW = 3;

};

#endif 