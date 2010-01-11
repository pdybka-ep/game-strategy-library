/*
 * GameStrategy.cpp
 * Author: Michal Kolodziejski
 */

#include "GameStrategy.hpp"
#include <iostream> // FIXME TMP!
#include <fstream>
#include <sstream>

namespace library {

    GameStrategy::GameStrategy() {
        gameStateInitialized_ = false;
    }

    GameStrategy::GameStrategy(const GameStrategy& gameStrategy){
        this->gameState_ = gameStrategy.gameState_;
        this->gameStateInitialized_ = gameStrategy.gameStateInitialized_;
    }

    GameStrategy::~GameStrategy() {
        // nothing to do
    }

    GameStrategy& GameStrategy::operator= (const GameStrategy& gameStrategy){
        if(this == &gameStrategy)
            return *this;

        this->gameState_ = gameStrategy.gameState_;
        this->gameStateInitialized_ = gameStrategy.gameStateInitialized_;
        this->gameFactory_ = gameStrategy.gameFactory_;
        return *this;
    }


    void GameStrategy::initialize(const boost::shared_ptr<AbstractGameFactory>& gameFactory){
        this->gameFactory_ = gameFactory;
    }

    void GameStrategy::startGame(const boost::shared_ptr<Game>& game, const boost::shared_ptr<Player> & player1, const boost::shared_ptr<Player> & player2){
        std::list<boost::shared_ptr<Player> > players;
        players.push_back(player1);
        players.push_back(player2);

        gameState_.setGame(game);
        gameState_.setPlayers(players);
        gameState_.setCurrentNode(game->getStartNode());
        gameState_.clearGamePath();
        gameState_.addNodeToGamePath(game->getStartNode());
        if(player1->isStartingPlayer()){
            gameState_.setNextPlayerIndex(0);
        }
        else {
            gameState_.setNextPlayerIndex(1);
        }
        gameStateInitialized_ = true;
    }

    void GameStrategy::startGame() throw(UnknownGameException){
        if(!gameStateInitialized_){
            throw UnknownGameException();
        }
        gameState_.setCurrentNode(gameState_.getGame()->getStartNode());
        gameState_.clearGamePath();
        gameState_.addNodeToGamePath(gameState_.getGame()->getStartNode());
        if(gameState_.getPlayers().front()->isStartingPlayer()){
            gameState_.setNextPlayerIndex(0);
        }
        else {
            gameState_.setNextPlayerIndex(1);
        }
    }

    boost::shared_ptr<Move> GameStrategy::findBestMove() throw(GameNotStartedException, NoMoveAvailableException){
        boost::shared_ptr<Node> currentNode = gameState_.getCurrentNode();
        if(currentNode.get() == 0){
            throw GameNotStartedException();
        }

        if(currentNode->isLeaf()){
            throw NoMoveAvailableException();
        }

        std::list<boost::shared_ptr<Move> > availableMoves = currentNode->getAvailableMoves();
        boost::shared_ptr<Move> bestMove = *(availableMoves.begin());
        bool maximizes = (gameState_.getNextPlayerIndex() == 0) ? true : false;

        for(std::list<boost::shared_ptr<Move> >::iterator it = availableMoves.begin(); it!=availableMoves.end(); ++it){
            if((maximizes && bestMove->getDestination()->getValue() < (*it)->getDestination()->getValue())
                    || (!maximizes && bestMove->getDestination()->getValue() > (*it)->getDestination()->getValue())){
                bestMove = *it;
                if(bestMove->getDestination()->getValue() == 1 || bestMove->getDestination()->getValue() == -1){
                    return bestMove;
                }
            }
        }
        return bestMove;
    }


    void GameStrategy::move(const boost::shared_ptr<Move>& move) throw(GameNotStartedException, InvalidMoveException){
        boost::shared_ptr<Node> currentNode = gameState_.getCurrentNode();
        if(currentNode.get() == 0){
            std::cout << "throwing GameNotStartedException" << std::endl;
            throw GameNotStartedException();
        }
        std::list<boost::shared_ptr<Move> > availableMoves = currentNode->getAvailableMoves();

        // check if move is acceptable
        bool acceptable = false;
        for(std::list<boost::shared_ptr<Move> >::const_iterator it = availableMoves.begin(); it!=availableMoves.end() && acceptable==false; ++it){
            if(*(*it) == *move){
                acceptable = true;
            }
        }
        if(!acceptable){
            std::cout << "throwing InvalidMoveException" << std::endl;
            throw InvalidMoveException();
        }

        // move
        gameState_.setCurrentNode(move->getDestination());
        gameState_.addNodeToGamePath(move->getDestination());
        gameState_.setNextPlayerIndex((gameState_.getNextPlayerIndex()+1)%2);
    }


    void GameStrategy::endOfGame(const boost::shared_ptr<Player> & winner) throw(GameNotStartedException){
        boost::shared_ptr<Node> currentNode = gameState_.getCurrentNode();
        if(currentNode.get() == 0){
            std::cout << "throwing GameNotStartedException" << std::endl;
            throw GameNotStartedException();
        }

        // set value
        if(winner == 0 || (*(gameState_.getPlayers().front()) != *winner && *(gameState_.getPlayers().back()) != *winner)){
            throw InvalidPlayerException();
        }
        else if(*(gameState_.getPlayers().front()) == *winner){
            currentNode->setValue(1);
        }
        else if (*(gameState_.getPlayers().back()) == *winner) {
            currentNode->setValue(-1);
        }


        if(!(currentNode->isLeaf())){
            /* generally shouldn't happen, but just in case of lazy programmer... */
            updateDownTheTree(currentNode, currentNode->getValue());
        }
        else {
            // update counter
            if(!currentNode->isVisited()){
                currentNode->setVisited(true);
                gameState_.getGame()->incNumberOfVisitedLeafs();
            }
        }

        // update values up the tree
        std::list<boost::shared_ptr<Node> > gamePath = gameState_.getGamePath();
        // get back one level in tree (don't have to update the leaf/current node)
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

    void GameStrategy::endOfGame() throw(GameNotStartedException){
        boost::shared_ptr<Node> currentNode = gameState_.getCurrentNode();
        if(currentNode.get() == 0){
            std::cout << "throwing GameNotStartedException" << std::endl;
            throw GameNotStartedException();
        }

        if(!currentNode->isLeaf()){
            /* generally shouldn't happen, but just in case of lazy programmer... */
            updateDownTheTree(currentNode, currentNode->getValue());
        }
        else {
            // update counter
            if(!currentNode->isVisited()){
                currentNode->setVisited(true);
                gameState_.getGame()->incNumberOfVisitedLeafs();
            }
        }

        // set not started (finished) game
        boost::shared_ptr<Node> empty;
        gameState_.setCurrentNode(empty);
    }

    void GameStrategy::saveGame(const std::string& filePath) throw(FileAccessException, GameFactoryInitializationException){
        if(gameFactory_.get() == 0){
            throw GameFactoryInitializationException();
        }
        std::ofstream file(filePath.c_str());
        if(!file.is_open()){
            throw FileAccessException();
        }
        file << gameFactory_->serialize(gameState_.getGame());
        file.close();
    }

    void GameStrategy::loadGame(const std::string& filePath) throw(FileAccessException, GameFactoryInitializationException){
        if(gameFactory_.get() == 0){
            throw GameFactoryInitializationException();
        }
        std::ifstream file(filePath.c_str());
        if(!file.is_open()){
            throw FileAccessException();
        }
        boost::shared_ptr<Game> game;
        std::stringstream gameDataBuf;
        std::string gameData, tmp;
        while(!file.eof()){
            file >> tmp;
            gameDataBuf << tmp;
        }
        gameData = gameDataBuf.str();
        file.close();
        game = gameFactory_->deserialize(gameData);
        gameState_.setGame(game);
    }


    /* private methods */
    bool GameStrategy::updateNodeValue(boost::shared_ptr<Node> node, bool maximizingNode) {
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

    void GameStrategy::updateDownTheTree(boost::shared_ptr<Node> node, int value){
        node->setValue(value);
        if(node->isLeaf()){
            if(!node->isVisited()){
                node->setVisited(true);
                gameState_.getGame()->incNumberOfVisitedLeafs();
            }
            return;
        }

        std::list<boost::shared_ptr<Move> > availableMoves = node->getAvailableMoves();
        for(std::list<boost::shared_ptr<Move> >::iterator it = availableMoves.begin();
                it != availableMoves.end(); ++it){
            updateDownTheTree((*it)->getDestination(), value);
        }
    }
}
