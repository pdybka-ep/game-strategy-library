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

        std::list<Player> getPlayers() const {
            return players_;
        }

        void setCurrentNode(boost::shared_ptr<Node> currentNode_) {
            this->currentNode_ = currentNode_;
        }

        void setGame(Game game_) {
            this->game_ = game_;
        }

        void setNextPlayerIndex(int nextPlayerIndex_) {
            this->nextPlayerIndex_ = nextPlayerIndex_;
        }

        void setPlayers(std::list<Player> players_) {
            this->players_ = players_;
        }

    protected:
        Game game_;
        std::list<Player> players_;
        boost::shared_ptr<Node> currentNode_;
        int nextPlayerIndex_;
    };

}

#endif /* GAMESTATE_H_ */
