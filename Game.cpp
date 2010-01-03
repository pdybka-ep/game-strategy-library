/*
 * Game.cpp
 * Author: Michal Kolodziejski
 */

#include "Game.hpp"

namespace library {

	Game::Game() {
		this->gameId_ = -1;
	}

	Game::Game(const Game& game){
		this->gameId_ = game.gameId_;
		this->startNode_ = game.startNode_;
	}

	Game::~Game() {
		// nothing to do
	}


	Game& Game::operator=(const Game& game){
		this->gameId_ = game.gameId_;
		this->startNode_ = game.startNode_;
		return *this;
	}
}
