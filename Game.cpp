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


    bool operator== (const Game& g1, const Game& g2){
        if(&g1 == &g2)
            return true;
        if(g1.gameId_ == g2.gameId_ && *(g1.startNode_) == *(g2.startNode_)
                && g1.numberOfVisitedNodes_ == g2.numberOfVisitedNodes_
                && g1.totalNumberOfNodes_ == g2.totalNumberOfNodes_)
            return true;
        return false;
    }

    bool operator!= (const Game& g1, const Game& g2){
        return !(g1 == g2);
    }

}
