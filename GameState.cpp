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
        this->nextPlayerIndex_ = gameState.nextPlayerIndex_;
        std::list<Player>::const_iterator it = gameState.players_.begin();
        while(it != gameState.players_.end()){
            this->players_.push_back(*it);
            ++it;
        }
    }


    GameState::~GameState() {
        this->players_.clear();
    }


    GameState& GameState::operator= (const GameState& gameState){
        this->game_ = gameState.game_;
        this->currentNode_ = gameState.currentNode_;
        this->nextPlayerIndex_ = gameState.nextPlayerIndex_;
        std::list<Player>::const_iterator it = gameState.players_.begin();
        while(it != gameState.players_.end()){
            this->players_.push_back(*it);
            ++it;
        }
        return *this;
    }

}
