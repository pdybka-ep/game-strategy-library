/*
 * GameStrategy.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAMESTRATEGY_HPP_
#define GAMESTRATEGY_HPP_

#include <list>
#include <boost/shared_ptr.hpp>
#include "GameState.hpp"
#include "AbstractGameFactory.hpp"
#include "GameNotStartedException.hpp"
#include "InvalidMoveException.hpp"
#include "NoMoveAvailableException.hpp"
#include "InvalidPlayerException.hpp"
#include "UnknownGameException.hpp"
#include "FileAccessException.hpp"
#include "GameFactoryInitializationException.hpp"

namespace library {

    class GameStrategy {
    public:
        GameStrategy();
        GameStrategy(const GameStrategy&);
        virtual ~GameStrategy();

        GameStrategy& operator= (const GameStrategy&);

        /* library functions */
        void initialize(const boost::shared_ptr<AbstractGameFactory>&);
        void startGame(const boost::shared_ptr<Game>&, const boost::shared_ptr<Player> &, const boost::shared_ptr<Player> &);
        void startGame() throw(UnknownGameException);
        boost::shared_ptr<Move> findBestMove() throw(GameNotStartedException, NoMoveAvailableException);
        void move(const boost::shared_ptr<Move>&) throw(GameNotStartedException, InvalidMoveException);
        void endOfGame(const boost::shared_ptr<Player> &) throw(GameNotStartedException);
        void endOfGame() throw(GameNotStartedException);
        void saveGame(const std::string&) throw(FileAccessException, GameFactoryInitializationException);
        void loadGame(const std::string&) throw(FileAccessException, GameFactoryInitializationException);

        boost::shared_ptr<Game> getCurrentGame() const {
            return this->gameState_.getGame();
        }

    private:
        /* private helper methods */
        bool updateNodeValue(boost::shared_ptr<Node>& node, bool maximizingNode);

    private:
        boost::shared_ptr<AbstractGameFactory> gameFactory_;
        GameState gameState_;
        bool gameStateInitialized_;
    };

}

#endif /* GAMESTRATEGY_HPP_ */
