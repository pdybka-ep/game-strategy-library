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
        if(this == &player)
            return *this;

        this->name_ = player.name_;
        this->startingPlayer_ = player.startingPlayer_;
        return *this;
    }


    bool operator==(const Player& p1, const Player& p2){
        if(&p1 == &p2)
            return true;
        if(p1.name_ == p2.name_ && p1.startingPlayer_ == p2.startingPlayer_)
            return true;
        return false;
    }

    bool operator!=(const Player& p1, const Player& p2){
        return !(p1==p2);
    }
}
