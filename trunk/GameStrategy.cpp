/*
 * GameStrategy.cpp
 * Author: Michal Kolodziejski
 */

#include "GameStrategy.hpp"
#include <iostream> // FIXME TMP!

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
        if(this == &gameStrategy)
            return *this;

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
        gameState_.addNodeToGamePath(game.getStartNode());
        if(player1.isStartingPlayer()){
            gameState_.setNextPlayerIndex(0);
        }
        else {
            gameState_.setNextPlayerIndex(1);
        }
    }


    Move GameStrategy::findBestMove() throw(GameNotStartedException, NoMoveAvailableException){
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
            std::cout << "throwing GameNotStartedException" << std::endl;
            throw GameNotStartedException();
        }
        std::list<boost::shared_ptr<Move> > availableMoves = currentNode->getAvailableMoves();

        // check if move is acceptable
        bool acceptable = false;
        for(std::list<boost::shared_ptr<Move> >::const_iterator it = availableMoves.begin(); it!=availableMoves.end() && acceptable==false; ++it){
            if(*(*it) == move){
                acceptable = true;
            }
        }
        if(!acceptable){
            std::cout << "throwing InvalidMoveException" << std::endl;
            throw InvalidMoveException();
        }

        // move
        gameState_.setCurrentNode(move.getDestination());
        gameState_.addNodeToGamePath(move.getDestination());
        gameState_.setNextPlayerIndex((gameState_.getNextPlayerIndex()+1)%2);
    }


    void GameStrategy::endOfGame(const Player& winner){
        // set value
        if(gameState_.getPlayers().front() == winner){
            gameState_.getCurrentNode()->setValue(1);
        }
        else if (gameState_.getPlayers().back() == winner) {
            gameState_.getCurrentNode()->setValue(-1);
        }
        else {
            gameState_.getCurrentNode()->setValue(0);
        }

        // update values up the tree
        std::list<boost::shared_ptr<Node> > gamePath = gameState_.getGamePath();
        // get back one level in tree (don't have to update the leaf)
        gamePath.pop_back();
        gameState_.setNextPlayerIndex((gameState_.getNextPlayerIndex()+1)%2);
        if(gamePath.size() != 0){
            bool maximizingNode = (gameState_.getNextPlayerIndex() == 0);
            bool nodeChanged = false;
            boost::shared_ptr<Node> currentNode;
            do {
                currentNode = gamePath.back();
                nodeChanged = updateNodeValue(currentNode, maximizingNode);
                gamePath.pop_back();
                maximizingNode = !maximizingNode;
            } while (nodeChanged && !gamePath.empty());
        }
        // set not started (finished) game
        boost::shared_ptr<Node> empty;
        gameState_.setCurrentNode(empty);
    }


    void GameStrategy::saveGame(const std::string& filePath){
        // TODO implement
    }

    void GameStrategy::loadGame(const std::string& filePath){
        // TODO implement
    }


    /* private methods */
    bool GameStrategy::updateNodeValue(boost::shared_ptr<Node>& node, bool maximizingNode) {
        if(node->isLeaf())
            return false;

        std::list<boost::shared_ptr<Move> > availableMoves = node->getAvailableMoves();
        int oldValue = node->getValue();
        int newValue = availableMoves.front()->getDestination()->getValue();
        for(std::list<boost::shared_ptr<Move> >::const_iterator it = availableMoves.begin();
                it != availableMoves.end(); ++it){
            if((maximizingNode && newValue < (*it)->getDestination()->getValue())
                    || (!maximizingNode && newValue > (*it)->getDestination()->getValue())){
                newValue = (*it)->getDestination()->getValue();
            }
        }

        node->setValue(newValue);
        return (oldValue != newValue);
    }
}
