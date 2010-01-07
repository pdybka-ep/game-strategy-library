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

    class Game {
    public:
        Game();
        Game(const Game&);
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
        int getTotalNumberOfNodes() const {
            return totalNumberOfNodes_;
        }

        /**
         * Returns number of visited nodes
         */
        int getNumberOfVisitedNodes() const {
            return numberOfVisitedNodes_;
        }

        /**
         * Sets game ID
         */
        void setGameId(std::string gameId) {
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
        void setTotalNumberOfNodes(int totalNumberOfNodes){
            this->totalNumberOfNodes_ = totalNumberOfNodes;
        }

        /**
         * Sets number of visited nodes
         */
        void setNumberOfVisitedNodes(int numberOfVisitedNodes){
            this->numberOfVisitedNodes_ = numberOfVisitedNodes;
        }

        /**
         * Increments number of visited nodes
         */
        void incNumberOfVisitedNodes(){
            ++ this->numberOfVisitedNodes_;
        }

    protected:
        std::string gameId_;
        boost::shared_ptr<Node> startNode_;
        int totalNumberOfNodes_;
        int numberOfVisitedNodes_;
    };

}

#endif /* GAME_H_ */
