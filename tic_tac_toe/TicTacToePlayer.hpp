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

/**
	@class TicTacToePlayer
	@author Hanna Dutkiewicz
	Class representing a TicTacToe game player
*/
class TicTacToePlayer: public library::Player{

public:
	/** Type of the player */
	enum PlayerType {
		/** Human player */
		HUMAN, 
		/** COmputer player */
		COMPUTER
	};
	
	/** Sign of the player */
	enum PlayerSign {
		/** Cross */
		CROSS, 
		/** Circle */
		CIRCLE
	};
	
	/** Level of the computer player */
	enum PlayerLevel {
		/** A beginner player level */
		BEGINNER, 
		/** An intermediate player level */
		INTERMEDIATE, 
		/** An advanced player level */
		ADVANCED
	};

public:
	/**
		Default constructor
	*/
	TicTacToePlayer();
	
	/**
		Copy constructor
		@param player other player to be copied
	*/
    TicTacToePlayer(const TicTacToePlayer & player);
	
	/**
		Destructor
	*/
	~TicTacToePlayer(){}

	/**
		Copies elements of another player
		@param player player to be copied
		@return copied player
	*/
    TicTacToePlayer & operator=(const TicTacToePlayer & player);

	/**
		Friend function that compares two TicTacToePlayers
		@param b1 first TicTacToePlayer to compare
		@param b2 second TicTacToePlayer to compare
		@return <code>true</code> if players are equal, <code>false</code> otherwhise
	*/
    friend bool operator==(const TicTacToePlayer & p1, const TicTacToePlayer & p2);
	
	/**
		Friend function that compares two TicTacToePlayers and indicates whether they are not equal
		@param b1 first TicTacToePlayer to compare
		@param b2 second TicTacToePlayer to compare
		@return <code>true</code> if players are NOT equal, <code>false</code> otherwhise
	*/
    friend bool operator!=(const TicTacToePlayer & p1, const TicTacToePlayer & p2);

	/**
		Returns player type
		@return player type
	*/
	PlayerType getPlayerType() const{
		return playerType_;
	}

	/**
		Sets player type
		@param type player type to set
	*/
	void setPlayerType(const PlayerType type){
		this->playerType_ = type;
	}

	/**
		Returns player sign
		@return player sign
	*/
	PlayerSign getPlayerSign() const{
		return playerSign_;
	}

	/**
		Sets player sign considering TicTacToe game rules:
		if new sign is circle player is set to be the starting player,
		otherwise it's not a starting player
		@param playerSign new player sign to set
	*/
	void setPlayerSign(PlayerSign playerSign){
		this->playerSign_ = playerSign;
		this->startingPlayer_ = (this->playerSign_ == CIRCLE ? true : false );
	}

	/**
		Sets if a player is a starting player considering TicTacToe game rules:
		if player is a starting player it's sign is a circle,
		otherwise it's a cross
		@param startingPlayer whether player is a starting game player
	*/
	void setStartingPlayer(bool startingPlayer) {
		this->startingPlayer_ = startingPlayer;
		this->playerSign_ = (this->startingPlayer_ == true ? CIRCLE : CROSS );
	}

private:
	/** Type of the player */
	PlayerType playerType_;
	
	/** Sign of the player */
	PlayerSign playerSign_;
};


#endif /* TICTACTOEPLAYER_H */