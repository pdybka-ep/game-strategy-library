/*
 * Game.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <boost/shared_ptr.hpp>
#include "Node.hpp"

namespace library {

    class Game {
    public:
        Game();
        Game(const Game&);
        virtual ~Game();

        Game& operator=(const Game&);

        /**
         * Returns game ID
         */
        std::string getGameId() const {
            return gameId_;
        }

        /**
         * Returns start node
         */
        boost::shared_ptr<Node> getStartNode() const {
            return startNode_;
        }

        /**
         * Sets game ID
         */
        void setGameId(std::string gameId_) {
            this->gameId_ = gameId_;
        }

        /**
         * Sets start node
         */
        void setStartNode(const boost::shared_ptr<Node>& startNode_) {
            this->startNode_ = startNode_;
        }

    protected:
        std::string gameId_;
        boost::shared_ptr<Node> startNode_;
    };

}

#endif /* GAME_H_ */
