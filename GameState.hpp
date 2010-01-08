/*
 * GameState.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <list>
#include <boost/shared_ptr.hpp>
#include "Game.hpp"
#include "Player.hpp"
#include "Node.hpp"

namespace library {

    /**
     * Class representing a state of a game
     * @author Michał Kołodziejski
     */
    class GameState {
    public:
        /**
         * Creates game's state
         */
        GameState();
        /**
         * Copies game's state
         * @param gameState a game's state to be copied
         */
        GameState(const GameState& gameState);

        /**
         * Destroys the game's state
         */
        virtual ~GameState();

        GameState& operator= (const GameState&);


        /**
         * Returns current node
         * @return current node
         */
        boost::shared_ptr<Node> getCurrentNode() const {
            return currentNode_;
        }

        /**
         * Returns game
         * @return game
         */
        boost::shared_ptr<Game> getGame() const {
            return game_;
        }

        /**
         * Returns next player's index (starting from 0)
         * @return next player's index
         */
        int getNextPlayerIndex() const {
            return nextPlayerIndex_;
        }

        /**
         * Returns players
         * @return players
         */
        std::list<boost::shared_ptr<Player> > getPlayers() const {
            return players_;
        }

        /**
         * Returns game path
         * @return game path
         */
        std::list<boost::shared_ptr<Node> > getGamePath() const {
            return gamePath_;
        }

        /**
         * Sets current node
         * @param currentNode a current node to be set
         */
        void setCurrentNode(const boost::shared_ptr<Node>& currentNode) {
            this->currentNode_ = currentNode;
        }

        /**
         * Sets game
         * @param game a game to be set
         */
        void setGame(const boost::shared_ptr<Game>& game) {
            this->game_ = game;
        }

        /**
         * Sets next player's index
         * @param nextPlayerIndex a next player's index to be set
         */
        void setNextPlayerIndex(int nextPlayerIndex) {
            this->nextPlayerIndex_ = nextPlayerIndex;
        }

        /**
         * Sets players
         * @param players players to be set
         */
        void setPlayers(const std::list<boost::shared_ptr<Player> >& players) {
            this->players_ = players;
        }

        /**
         * Sets game path
         * @param gamePath a game path to be set
         */
        void setGamePath(const std::list<boost::shared_ptr<Node> >& gamePath) {
            this->gamePath_ = gamePath;
        }

        /**
         * Adds a node to the game path
         * @param node a node to be added
         */
        void addNodeToGamePath(const boost::shared_ptr<Node>& node) {
            this->gamePath_.push_back(node);
        }

        /**
         * Clears game path
         */
        void clearGamePath() {
            this->gamePath_.clear();
        }

    protected:
        /**
         * Game
         */
        boost::shared_ptr<Game> game_;

        /**
         * List of players
         */
        std::list<boost::shared_ptr<Player> > players_;

        /**
         * Current node
         */
        boost::shared_ptr<Node> currentNode_;

        /**
         * Next player's index (starts from 0)
         */
        int nextPlayerIndex_;

        /**
         * Game path
         */
        std::list<boost::shared_ptr<Node> > gamePath_;
    };

}

#endif /* GAMESTATE_H_ */
