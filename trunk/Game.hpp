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

    class Game;
    bool operator== (const Game&, const Game&);
    bool operator!= (const Game&, const Game&);

    /**
     * Class representing a single game
     * @author Michał Kołodziejski
     */
    class Game {
    public:
        /**
         * Creates a game
         */
        Game();

        /**
         * Copies a game
         * @param game a game to be copied
         */
        Game(const Game& game);

        /**
         * Destroys a game
         */
        virtual ~Game();

        Game& operator=(const Game&);
        friend bool operator== (const Game&, const Game&);
        friend bool operator!= (const Game&, const Game&);


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
         * Returns total number of nodes
         */
        int getTotalNumberOfLeafs() const {
            return totalNumberOfLeafs_;
        }

        /**
         * Returns number of visited nodes
         */
        int getNumberOfVisitedLeafs() const {
            return numberOfVisitedLeafs_;
        }

        /**
         * Sets game ID
         */
        void setGameId(const std::string& gameId) {
            this->gameId_ = gameId;
        }

        /**
         * Sets start node
         */
        void setStartNode(const boost::shared_ptr<Node>& startNode) {
            this->startNode_ = startNode;
        }

        /**
         * Sets total number of nodes
         */
        void setTotalNumberOfLeafs(int totalNumberOfLeafs){
            this->totalNumberOfLeafs_ = totalNumberOfLeafs;
        }

        /**
         * Sets number of visited nodes
         */
        void setNumberOfVisitedLeafs(int numberOfVisitedLeafs){
            this->numberOfVisitedLeafs_ = numberOfVisitedLeafs;
        }

        /**
         * Increments number of visited nodes
         */
        void incNumberOfVisitedLeafs(){
            ++ this->numberOfVisitedLeafs_;
        }

    protected:
        /**
         * Game's ID
         */
        std::string gameId_;

        /**
         * Start node
         */
        boost::shared_ptr<Node> startNode_;

        /**
         * Total number of leafs. It's equal to number of all game tree's routes.
         */
        int totalNumberOfLeafs_;

        /**
         * Number of visited leafs.
         */
        int numberOfVisitedLeafs_;
    };

}

#endif /* GAME_H_ */
