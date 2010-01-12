/**
  @file TicTacToePlayer.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEPLAYER_H
#define TICTACTOEPLAYER_H

#include "../game-strategy-library/Player.hpp"


class TicTacToePlayer;
bool operator==(const TicTacToePlayer & p1, const TicTacToePlayer & p2);
bool operator!=(const TicTacToePlayer & p1, const TicTacToePlayer & p2);


class TicTacToePlayer: public library::Player{

public:
	enum PlayerType {HUMAN, COMPUTER};
	enum PlayerSign {CROSS, CIRCLE};
	enum PlayerLevel {BEGINNER, INTERMEDIATE, ADVANCED};

public:
	TicTacToePlayer();
    TicTacToePlayer(const TicTacToePlayer & player);
	~TicTacToePlayer(){}

    TicTacToePlayer & operator=(const TicTacToePlayer & player);

    friend bool operator==(const TicTacToePlayer & p1, const TicTacToePlayer & p2);
    friend bool operator!=(const TicTacToePlayer & p1, const TicTacToePlayer & p2);

	PlayerType getPlayerType() const{
		return playerType_;
	}

	void setPlayerType(const PlayerType type){
		this->playerType_ = type;
	}

	PlayerSign getPlayerSign() const{
		return playerSign_;
	}

	void setPlayerSign(PlayerSign playerSign){
		this->playerSign_ = playerSign;
		this->startingPlayer_ = (this->playerSign_ == CIRCLE ? true : false );
	}

	void setStartingPlayer(bool startingPlayer) {
		this->startingPlayer_ = startingPlayer;
		this->playerSign_ = (this->startingPlayer_ == true ? CIRCLE : CROSS );
	}

private:
	/** Type of the player. It has to be initialized when player is created. */
	PlayerType playerType_;
	PlayerSign playerSign_;
};


#endif /* TICTACTOEPLAYER_H */