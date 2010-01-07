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

    class GameState {
    public:
        GameState();
        GameState(const GameState &);
        virtual ~GameState();

        GameState& operator= (const GameState&);


        boost::shared_ptr<Node> getCurrentNode() const {
            return currentNode_;
        }

        Game getGame() const {
            return game_;
        }

        int getNextPlayerIndex() const {
            return nextPlayerIndex_;
        }

        std::list<boost::shared_ptr<Player> > getPlayers() const {
            return players_;
        }

        std::list<boost::shared_ptr<Node> > getGamePath() const {
            return gamePath_;
        }

        void setCurrentNode(const boost::shared_ptr<Node>& currentNode_) {
            this->currentNode_ = currentNode_;
        }

        void setGame(const Game& game_) {
            this->game_ = game_;
        }

        void setNextPlayerIndex(int nextPlayerIndex_) {
            this->nextPlayerIndex_ = nextPlayerIndex_;
        }

        void setPlayers(const std::list<boost::shared_ptr<Player> >& players_) {
            this->players_ = players_;
        }

        void setGamePath(const std::list<boost::shared_ptr<Node> >& gamePath) {
            this->gamePath_ = gamePath;
        }

        void addNodeToGamePath(const boost::shared_ptr<Node>& node) {
            this->gamePath_.push_back(node);
        }

        void clearGamePath() {
            this->gamePath_.clear();
        }

    protected:
        Game game_;
        std::list<boost::shared_ptr<Player> > players_;
        boost::shared_ptr<Node> currentNode_;
        int nextPlayerIndex_;
        std::list<boost::shared_ptr<Node> > gamePath_;
    };

}

#endif /* GAMESTATE_H_ */
