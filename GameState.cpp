/*
 * GameState.cpp
 * Author: Michal Kolodziejski
 */

#include "GameState.hpp"

namespace library {

    GameState::GameState() {
        this->currentNode_ = boost::shared_ptr<Node>();
        this->nextPlayerIndex_ = -1;
    }


    GameState::GameState(const GameState & gameState){
        this->game_ = gameState.game_;
        this->currentNode_ = gameState.currentNode_;
        this->players_ = gameState.players_;
        this->nextPlayerIndex_ = gameState.nextPlayerIndex_;
        this->gamePath_ = gameState.gamePath_;
    }


    GameState::~GameState() {
        this->players_.clear();
    }


    GameState& GameState::operator= (const GameState& gameState){
        if(this == &gameState)
            return *this;

        this->game_ = gameState.game_;
        this->currentNode_ = gameState.currentNode_;
        this->players_ = gameState.players_;
        this->nextPlayerIndex_ = gameState.nextPlayerIndex_;
        this->gamePath_ = gameState.gamePath_;
        return *this;
    }

}
