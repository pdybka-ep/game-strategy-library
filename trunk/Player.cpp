/*
 * Player.cpp
 * Author: Michal Kolodziejski
 */

#include "Player.hpp"

namespace library {

	Player::Player() {
		name_ = "unknown";
		startingPlayer_ = false;
	}

	Player::Player(const Player& player){
		this->name_ = player.name_;
		this->startingPlayer_ = player.startingPlayer_;
	}

	Player::~Player() {
		// nothing to do here
	}

	Player& Player::operator=(const Player& player){
		this->name_ = player.name_;
		this->startingPlayer_ = player.startingPlayer_;
		return *this;
	}

}
