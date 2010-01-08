/**
  @file TicTacToePlayer.cpp
  @author Hanna Dutkiewicz
*/

#include "TicTacToePlayer.hpp"

TicTacToePlayer::TicTacToePlayer(): Player(){
	this->playerSign_ = CIRCLE;
	this->playerType_ = COMPUTER;
}

TicTacToePlayer::TicTacToePlayer(const TicTacToePlayer & player)
: Player(), playerType_(player.playerType_), playerSign_(player.playerSign_){
	this->name_ = player.name_;
    this->startingPlayer_ = player.startingPlayer_;
}

TicTacToePlayer & TicTacToePlayer::operator=(const TicTacToePlayer & player){
	if(this == &player)
        return *this;

    this->name_ = player.name_;
    this->startingPlayer_ = player.startingPlayer_;
	this->playerType_ = player.playerType_;
	this->playerSign_ = player.playerSign_;
    return *this;
}

bool operator==(const TicTacToePlayer & p1, const TicTacToePlayer & p2){
	 if(&p1 == &p2)
        return true;
    if(	p1.name_ == p2.name_ && 
		p1.startingPlayer_ == p2.startingPlayer_ &&
		p1.playerSign_ == p2.playerSign_ &&
		p1.playerType_ == p2.playerType_)
        return true;
    return false;
}

bool operator!=(const TicTacToePlayer & p1, const TicTacToePlayer & p2){
	return !(p1 == p2);
}
