/*
 * Move.cpp
 * Author: Michal Kolodziejski
 */

#include "Move.hpp"

namespace library {

	Move::Move() {
		moveId_ = -1;
	}


	Move::Move(const Move& move){
		this->moveId_ = move.moveId_;
		this->destination_ = move.destination_;
	}

	Move::~Move() {
	}

	Move& Move::operator= (const Move& move){
		this->moveId_ = move.moveId_;
		this->destination_ = move.destination_;
		return *this;
	}

}
