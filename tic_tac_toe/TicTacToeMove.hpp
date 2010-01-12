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
std::ostream & operator<<(std::ostream & os, const TicTacToeMove & node);


class TicTacToeMove: public library::Move{

public:
	TicTacToeMove();
	TicTacToeMove(int x, int y);
    TicTacToeMove(const TicTacToeMove & move);
	virtual ~TicTacToeMove(){}

    TicTacToeMove& operator= (const TicTacToeMove & move);

    friend bool operator== (const TicTacToeMove & move1, const TicTacToeMove & move2);
    friend bool operator!= (const TicTacToeMove & move1, const TicTacToeMove & move2);
	friend std::ostream & operator<<(std::ostream & os, const TicTacToeMove & node);

	std::pair<int,int> getCoordinates() const{
		return coordinates_;
	}

	void setCoordinates(int x, int y){
		this->coordinates_ = std::make_pair<int, int>(x, y);
	}

	void setCoordinates(const std::pair<int,int> coordinates){
		this->coordinates_ = coordinates;
	}



private:
	std::pair<int, int> coordinates_;
};


#endif /* TICTACTOEMOVE_H */