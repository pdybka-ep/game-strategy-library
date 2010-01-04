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

namespace library {

    class GameStrategy {
    public:
        GameStrategy();
        GameStrategy(const GameStrategy&);
        virtual ~GameStrategy();

        GameStrategy& operator= (const GameStrategy&);

        /* library functions */
        void initialize(boost::shared_ptr<AbstractGameFactory>&);
        void startGame(const Game&, const Player&, const Player&);
        Move findBestMove() throw(GameNotStartedException, NoMoveAvailableException);
        void move(const Move&) throw(GameNotStartedException, InvalidMoveException);
        void endOfGame(const Player&);
        void saveGame(const std::string&);
        void loadGame(const std::string&);

    private:
        /* private helper methods */
        bool updateNodeValue(boost::shared_ptr<Node>& node, bool maximizingNode);

    private:
        boost::shared_ptr<AbstractGameFactory> gameFactory_;
        GameState gameState_;
    };

}

#endif /* GAMESTRATEGY_HPP_ */
