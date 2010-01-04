/*
 * Game.cpp
 * Author: Michal Kolodziejski
 */

#include "Game.hpp"

namespace library {

    Game::Game() {
        this->gameId_ = -1;
        this->totalNumberOfNodes_ = 0;
        this->numberOfVisitedNodes_ = 0;
    }

    Game::Game(const Game& game){
        this->gameId_ = game.gameId_;
        this->startNode_ = game.startNode_;
        this->totalNumberOfNodes_ = game.totalNumberOfNodes_;
        this->numberOfVisitedNodes_ = game.numberOfVisitedNodes_;
    }

    Game::~Game() {
        // nothing to do
    }


    Game& Game::operator=(const Game& game){
        if(this == &game)
            return *this;

        this->gameId_ = game.gameId_;
        this->startNode_ = game.startNode_;
        this->totalNumberOfNodes_ = game.totalNumberOfNodes_;
        this->numberOfVisitedNodes_ = game.numberOfVisitedNodes_;
        return *this;
    }
}
