/*
 * GameStrategy.cpp
 * Author: Michal Kolodziejski
 */

#include "GameStrategy.hpp"

namespace library {

    GameStrategy::GameStrategy() {
        // nothing to do
    }

    GameStrategy::GameStrategy(const GameStrategy& gameStrategy){
        this->gameState_ = gameStrategy.gameState_;
    }

    GameStrategy::~GameStrategy() {
        // nothing to do
    }

    GameStrategy& GameStrategy::operator= (const GameStrategy& gameStrategy){
        this->gameState_ = gameStrategy.gameState_;
        this->gameFactory_ = gameStrategy.gameFactory_;
        return *this;
    }


    void GameStrategy::initialize(boost::shared_ptr<AbstractGameFactory>& gameFactory){
        this->gameFactory_ = gameFactory;
    }

    void GameStrategy::startGame(const Game& game, const Player& player1, const Player& player2){
        std::list<Player> players;
        players.push_back(player1);
        players.push_back(player2);

        gameState_.setGame(game);
        gameState_.setPlayers(players);
        gameState_.setCurrentNode(game.getStartNode());
        if(player1.isStartingPlayer()){
            gameState_.setNextPlayerIndex(0);
        }
        else {
            gameState_.setNextPlayerIndex(1);
        }
    }


    Move& GameStrategy::findBestMove() throw(GameNotStartedException, NoMoveAvailableException){
        boost::shared_ptr<Node> currentNode = gameState_.getCurrentNode();
        if(currentNode == 0){
            throw GameNotStartedException();
        }

        if(currentNode->isLeaf()){
            throw NoMoveAvailableException();
        }

        std::list<boost::shared_ptr<Move> > availableMoves = currentNode->getAvailableMoves();
        boost::shared_ptr<Move> bestMove = *(availableMoves.begin());
        if(gameState_.getNextPlayerIndex() == 0){
            /* maximizes */
            if(bestMove->getDestination()->getValue() == 1){
                return *bestMove;
            }
            for(std::list<boost::shared_ptr<Move> >::iterator it = availableMoves.begin(); it!=availableMoves.end(); ++it){
                if(bestMove->getDestination()->getValue() < (*it)->getDestination()->getValue()){
                    bestMove = *it;
                    if(bestMove->getDestination()->getValue() == 1){
                        return *bestMove;
                    }
                }
            }
        }
        else {
            /* minimizes */
            if(bestMove->getDestination()->getValue() == -1){
                return *bestMove;
            }
            for(std::list<boost::shared_ptr<Move> >::iterator it = availableMoves.begin(); it!=availableMoves.end(); ++it){
                if(bestMove->getDestination()->getValue() > (*it)->getDestination()->getValue()){
                    bestMove = *it;
                    if(bestMove->getDestination()->getValue() == -1){
                        return *bestMove;
                    }
                }
            }
        }
    }


    void GameStrategy::move(const Move& move) throw(GameNotStartedException, InvalidMoveException){
        boost::shared_ptr<Node> currentNode = gameState_.getCurrentNode();
        if(currentNode == 0){
            throw GameNotStartedException();
        }
        std::list<boost::shared_ptr<Move> > availableMoves = currentNode->getAvailableMoves();

        // check if move is acceptable
        bool acceptable = false;
        for(std::list<boost::shared_ptr<Move> >::const_iterator it = availableMoves.begin(); it!=availableMoves.end() && acceptable!=true; ++it){
            if((*it)->getMoveId() == move.getMoveId()){
                acceptable = true;
            }
        }
        if(!acceptable){
            throw InvalidMoveException();
        }

        // move
        gameState_.setCurrentNode(move.getDestination());
        if(gameState_.getNextPlayerIndex() == 0){
            gameState_.setNextPlayerIndex(1);
        }
        else {
            gameState_.setNextPlayerIndex(0);
        }
    }


    void GameStrategy::endOfGame(const Player& winner){
        // TODO implement
    }


    void GameStrategy::saveGame(const std::string& filePath){
        // TODO implement
    }

    void GameStrategy::loadGame(const std::string& filePath){
        // TODO implement
    }
}
