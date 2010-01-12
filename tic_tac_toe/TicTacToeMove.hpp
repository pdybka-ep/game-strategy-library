/**
  @file TicTacToeMove.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEMOVE_H
#define TICTACTOEMOVE_H

#include "../game-strategy-library/Move.hpp"

class TicTacToeMove;
bool operator== (const TicTacToeMove & move1, const TicTacToeMove & move2);
bool operator!= (const TicTacToeMove & move1, const TicTacToeMove & move2);
//std::ostream & operator<<(std::ostream & os, const TicTacToeMove & node);

/**
	@class TicTacToeMove
	@author Hanna Dutkiewicz
	Class representing a single move in TicTacToe Game - placing one's sign on a board
*/
class TicTacToeMove: public library::Move{

public:
	/**
		Default constructor
	*/
	TicTacToeMove();
	
	/**
		Concstructor, sets coordinates of a move
		@param x first coordinate of a move (coordinate on a game board)
		@param y second coordinate of a move
	*/
	TicTacToeMove(int x, int y);
	
	/**
		Copy constructor
		@param move other move to be copied
	*/
    TicTacToeMove(const TicTacToeMove & move);
	
	/**
		Virtual destructor
	*/
	virtual ~TicTacToeMove(){}

	/**
		Copies elements from other move
		@param move other move to be copied
		@return copied move
	*/
    TicTacToeMove& operator= (const TicTacToeMove & move);

	/**
		Compares two moves, a friend function
		@param move1 first move to be compared
		@param move2 second move to be compared
		@return <code>true</code> if moves are equal, <code>false</code> otherwise
	*/
    friend bool operator== (const TicTacToeMove & move1, const TicTacToeMove & move2);
	
	/**
		Compares two moves and returns if they are not equal, a friend function
		@param move1 first move to be compared
		@param move2 second move to be compared
		@return <code>true</code> if moves are NOT equal, <code>false</code> otherwise
	*/
    friend bool operator!= (const TicTacToeMove & move1, const TicTacToeMove & move2);
	//friend std::ostream & operator<<(std::ostream & os, const TicTacToeMove & node);

	/**
		Returns coordinates of a move
		@return coordinates of a move
	*/
	std::pair<int,int> getCoordinates() const{
		return coordinates_;
	}

	/**
		Sets coordinates of a move
		@param x first coordinate
		@param y second coordinate
	*/
	void setCoordinates(int x, int y){
		this->coordinates_ = std::make_pair<int, int>(x, y);
	}

	/**
		Sets coordinates of a move
		@param coordinates coordinates of a move
	*/
	void setCoordinates(const std::pair<int,int> coordinates){
		this->coordinates_ = coordinates;
	}

private:
	/** Coordinates of a move on a game board of TicTacToe Game */
	std::pair<int, int> coordinates_;
};


#endif /* TICTACTOEMOVE_H */