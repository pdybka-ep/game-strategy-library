/*
 * Game.cpp
 * Author: Michal Kolodziejski
 */

#include "Game.hpp"

namespace library {

    Game::Game() {
        this->gameId_ = -1;
        this->totalNumberOfLeafs_ = 0;
        this->numberOfVisitedLeafs_ = 0;
    }

    Game::Game(const Game& game){
        this->gameId_ = game.gameId_;
        this->startNode_ = game.startNode_;
        this->totalNumberOfLeafs_ = game.totalNumberOfLeafs_;
        this->numberOfVisitedLeafs_ = game.numberOfVisitedLeafs_;
    }

    Game::~Game() {
        // nothing to do
    }


    Game& Game::operator=(const Game& game){
        if(this == &game)
            return *this;

        this->gameId_ = game.gameId_;
        this->startNode_ = game.startNode_;
        this->totalNumberOfLeafs_ = game.totalNumberOfLeafs_;
        this->numberOfVisitedLeafs_ = game.numberOfVisitedLeafs_;
        return *this;
    }


    bool operator== (const Game& g1, const Game& g2){
        if(&g1 == &g2)
            return true;
        if(g1.gameId_ == g2.gameId_ && *(g1.startNode_) == *(g2.startNode_)
                && g1.numberOfVisitedLeafs_ == g2.numberOfVisitedLeafs_
                && g1.totalNumberOfLeafs_ == g2.totalNumberOfLeafs_)
            return true;
        return false;
    }

    bool operator!= (const Game& g1, const Game& g2){
        return !(g1 == g2);
    }

}
