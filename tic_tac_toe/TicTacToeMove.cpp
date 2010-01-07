/**
  @file TicTacToeMove.cpp
  @author Hanna Dutkiewicz
*/

#include "TicTacToeMove.hpp"
#include "..\game-strategy-library\Node.hpp"

TicTacToeMove::TicTacToeMove(): Move(){

}

TicTacToeMove::TicTacToeMove(int x, int y): Move(){
	this->coordinates_ = std::make_pair<int,int>(x,y);
}

TicTacToeMove::TicTacToeMove(const TicTacToeMove & move): Move(){
	this->moveId_ = move.moveId_;
	this->destination_ = move.destination_;
	this->coordinates_ = move.coordinates_;
}

TicTacToeMove& TicTacToeMove::operator= (const TicTacToeMove & move){
	if(this == &move)
        return *this;

    this->moveId_ = move.moveId_;
    this->destination_ = move.destination_;
	this->coordinates_ = move.coordinates_;
    return *this;
}

bool operator== (const TicTacToeMove & m1, const TicTacToeMove & m2){
	if(&m1 == &m2)
        return true;
    if((m1.moveId_ == m2.moveId_) && 
		*(m1.destination_.get()) == *(m2.destination_.get()) && 
		(m1.coordinates_ == m2.coordinates_))
        return true;
    return false;
}

bool operator!= (const TicTacToeMove & m1, const TicTacToeMove & m2){
	return !(m1 == m2);
}